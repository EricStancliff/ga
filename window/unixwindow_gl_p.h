#pragma once
//referencing https://www.khronos.org/opengl/wiki/Programming_OpenGL_in_Linux:_GLX_and_Xlib

#include<stdio.h>
#include<stdlib.h>
#include<X11/X.h>
#include<X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#include <stack>
#include <algorithm>

#include <core/event.h>
#include <core/renderobject.h>
#include <core/outputstream.h>

#include "window_interface.h"



namespace ga 
{
namespace {
constexpr unsigned long ALL_EVENTS_MASK =
    ButtonPressMask |
    ButtonReleaseMask |
    EnterWindowMask |
    ExposureMask |
    FocusChangeMask |
    KeymapStateMask |
    KeyPressMask |
    KeyReleaseMask |
    PointerMotionMask |
    StructureNotifyMask;
}

class WindowImpl : public WindowInterface
{
    public:

    WindowImpl(const std::string& windowName) : m_wasDestroyed(false),
    m_dpy(NULL),
    m_win(0),
    m_glc(NULL)
    {
        createWindow();
        setWindowName(windowName);
    }
    virtual ~WindowImpl()
    {
        if(!m_wasDestroyed)
            cleanUpWindow();
    }

    virtual void tick() override
    {
        if(m_wasDestroyed)
            return;

        clearLastFrame();

        collectEvents();

        if(m_wasDestroyed)
        {
            return;        
        }

        XGetWindowAttributes(m_dpy, m_win, &m_gwa);
        
        glViewport(0, 0, m_gwa.width, m_gwa.height);
        
        draw();
        
        glXSwapBuffers(m_dpy, m_win);
    }

    virtual std::vector<std::shared_ptr<const Event>> getWindowEvents() const override
    {
        return m_frameEvents;
    }

    virtual void setWindowName(const std::string& windowName) override
    {
        if(!m_wasDestroyed)
            XStoreName(m_dpy, m_win, windowName.c_str());
    }

    virtual bool isDestroyed() const override
    {
        return m_wasDestroyed;
    }

    virtual void addRenderObject(std::shared_ptr<RenderObject> object) override
    {
        m_renderObjects.push_back(object);
    }

    virtual void removeRenderObject(const ObjectId& id) override 
    {
        std::remove_if(m_renderObjects.begin(), m_renderObjects.end(), [&id](auto &&rhs) {
            return rhs->getObjectId() == id;
        });
    }

    virtual std::vector<std::shared_ptr<RenderObject>> getRenderObjects() const override
    {
        return m_renderObjects;
    }

  private:
    void createWindow()
    {
        GLint att[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};

        m_dpy = XOpenDisplay(NULL);

        if (!m_dpy)
        {
            critical() << "Cannot connect to X server\n";
            return;
        }

        ::Window root = DefaultRootWindow(m_dpy);

        XVisualInfo *vi = glXChooseVisual(m_dpy, 0, att);

        if (!vi)
        {
            critical() << "\n\tno appropriate visual found\n\n";
            return;
        }

        Colormap cmap = XCreateColormap(m_dpy, root, vi->visual, AllocNone);

        XSetWindowAttributes swa;
        swa.colormap = cmap;
        swa.event_mask = ALL_EVENTS_MASK;

        m_win = XCreateWindow(m_dpy, root, 0, 0, 600, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);

        XMapWindow(m_dpy, m_win);

        m_glc = glXCreateContext(m_dpy, vi, NULL, GL_TRUE);
        glXMakeCurrent(m_dpy, m_win, m_glc);

        //Get ready for delete
        m_wmDeleteMessage = XInternAtom(m_dpy, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(m_dpy, m_win, &m_wmDeleteMessage, 1);
    }

    void collectEvents()
    {
        XEvent xev;
        while (XPending(m_dpy))
        {
            XNextEvent(m_dpy, &xev);
            //in the future, may need explicit mapping from XEvent type to GAEvent type
            auto evtPtr = std::make_shared<Event>((EventType)xev.type);
            m_frameEvents.push_back(evtPtr);

            //Special handling
            switch (xev.type)
            {
            case ClientMessage: //Window closed
                if (xev.xclient.data.l[0] == m_wmDeleteMessage)
                {
                    debug() << "Closing window.\n";
                    cleanUpWindow();
                    return;
                }
                break;
            }
        }
    }

    void clearLastFrame()
    {
        m_frameEvents.clear();
    }

    void draw()
    {
        //clear screen
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //set up projection
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1., 1., -1., 1., 1., 20.);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);

        for(auto&& ro : m_renderObjects)
        {
            ro->draw(m_frameEvents);
        }
    }

    void cleanUpWindow()
    {
        if(m_dpy)
        {
            glXMakeCurrent(m_dpy, None, NULL);
            glXDestroyContext(m_dpy, m_glc);
            XDestroyWindow(m_dpy, m_win);
            XCloseDisplay(m_dpy);
        }
        m_wasDestroyed = true;
        m_dpy = nullptr;
        m_win = 0;
        m_glc = nullptr;
    }

    //X11
    Display *m_dpy;
    ::Window m_win;
    GLXContext m_glc;
    XWindowAttributes m_gwa;
    Atom m_wmDeleteMessage;

    std::vector<std::shared_ptr<const Event>> m_frameEvents;

    bool m_wasDestroyed;

    std::vector<std::shared_ptr<RenderObject>> m_renderObjects;

};
}
