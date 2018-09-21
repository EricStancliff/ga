#include <thread>

#include <core/outputstream.h>

#include <shapes/quad.h>
#include <shapes/triangle.h>

#include <window/window.h>


int main(int argc, char *argv[])
{
    ga::Window window("Test");

    std::shared_ptr<ga::Quad> quad = std::make_shared<ga::Quad>();

    
    quad->setColor({1.0f, 0.0f, 0.0f, 1.0f});
    quad->setXWidth(1.5f);
    quad->setYHeight(1.5f);
    quad->setCenter({0.0f, 0.0f, 0.0f});

    window.addRenderObject(quad);

    std::shared_ptr<ga::Triangle> tri = std::make_shared<ga::Triangle>();

    ga::Vec3<ga::Vec3<float>> verts = {
        ga::Vec3<float>({0.0f, .75f, 0.0f}),
        ga::Vec3<float>({.75f, -.75f, 0.0f}),
        ga::Vec3<float>({-.75f, -.75f, 0.0f})};

    tri->setVertices(verts);
    tri->setColor({0.0f, 0.0f, 1.0f, 0.5f});

    quad->addManagedRenderObject(tri); //Ensure rendered after quad

    while(true)
    {
        window.tick();
        auto windowEvents = window.getWindowEvents();
        
        for(auto&& evt : windowEvents)
        {
            ga::debug() << ga::eventTypeToString(evt->getEventType()) << "\n";
        }

        if(window.isDestroyed())
        {
            ga::info() << "Goodbye\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}