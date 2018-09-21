#pragma once
#include "triangle_interface.h"

#include <GL/gl.h>

#include <algorithm>
#include <core/renderobject.h>

namespace ga
{
    const Vec3<Vec3<float>> BlankVertices = {
        Vec3<float>({0.0f, 0.0f, 0.0f}),
        Vec3<float>({0.0f, 0.0f, 0.0f}),
        Vec3<float>({0.0f, 0.0f, 0.0f})
    };

    const Vec3<Vec4<float>> BlankColors = {
        Vec4<float>({0.0f, 0.0f, 0.0f, 0.0f}),
        Vec4<float>({0.0f, 0.0f, 0.0f, 0.0f}),
        Vec4<float>({0.0f, 0.0f, 0.0f, 0.0f})
    };

    class TriangleImpl : public TriangleInterface
    {
        public:
        TriangleImpl() : 
        m_vertices(BlankVertices),
        m_colors(BlankColors)
        {
            
        }
        ~TriangleImpl() {}

        virtual void setVertices(const Vec3<Vec3<float>> &vertices) override
        {
            m_vertices = vertices;
        }

        virtual Vec3<Vec3<float>> getVertices() const override
        {
            return m_vertices;
        }

        virtual void setColor(const Vec4<float> &color) override
        {
            std::get<0>(m_colors) = color;
            std::get<1>(m_colors) = color;            
            std::get<2>(m_colors) = color;            
        }

        virtual void setColors(const Vec3<Vec4<float>> &colors) override
        {
            m_colors = colors;
        }

        virtual Vec3<Vec4<float>> getColors() const override
        {
            return m_colors;
        }

        virtual Vec4<float> getColor() const override
        {
            return std::get<0>(m_colors);
        }

        virtual void calculate() override
        {
            //noop
        }

        virtual void draw(const std::vector<std::shared_ptr<const Event>>& windowEvents) override
        {
            glFrontFace(GL_CW);
            glBegin(GL_TRIANGLES);
            
            constexpr int x(0), y(1), z(2);
            constexpr int r(0), g(1), b(2), a(3);

            int v = 0;
            glColor4f(m_colors[v][r], m_colors[v][g], m_colors[v][b], m_colors[v][a]);
            glVertex3f(m_vertices[v][x], m_vertices[v][y], m_vertices[v][z]);
            v = 1;
            glColor4f(m_colors[v][r], m_colors[v][g], m_colors[v][b], m_colors[v][a]);
            glVertex3f(m_vertices[v][x], m_vertices[v][y], m_vertices[v][z]);
            v = 2;
            glColor4f(m_colors[v][r], m_colors[v][g], m_colors[v][b], m_colors[v][a]);
            glVertex3f(m_vertices[v][x], m_vertices[v][y], m_vertices[v][z]);

            glEnd();

            //draw children
            for(auto&& ro : m_ros)
                ro->draw(windowEvents);
        }

        virtual void addManagedRenderObject(std::shared_ptr<RenderObject> ro) override
        {
            m_ros.push_back(ro);
        }

        virtual void removeManagedRenderObject(const ObjectId& id) override
        {
            std::remove_if(m_ros.begin(), m_ros.end(), [&id](auto&& rhs) {
                return rhs->getObjectId() == id;
            });
        }

        virtual std::vector<std::shared_ptr<RenderObject>> getManagedRenderObjects() const override
        {
            return m_ros;
        }

      private:

        Vec3<Vec3<float>> m_vertices;
        Vec3<Vec4<float>> m_colors;

        std::vector<std::shared_ptr<RenderObject>> m_ros;
    };
}