#pragma once
#include "quad_interface.h"

#include <GL/gl.h>

#include <algorithm>
#include <core/renderobject.h>

namespace ga
{
    const Vec4<Vec3<float>> BlankVertices = {
        Vec3<float>({0.0f, 0.0f, 0.0f}),
        Vec3<float>({0.0f, 0.0f, 0.0f}),
        Vec3<float>({0.0f, 0.0f, 0.0f}),
        Vec3<float>({0.0f, 0.0f, 0.0f})
    };

    const Vec4<Vec4<float>> BlankColors = {
        Vec4<float>({0.0f, 0.0f, 0.0f, 0.0f}),
        Vec4<float>({0.0f, 0.0f, 0.0f, 0.0f}),
        Vec4<float>({0.0f, 0.0f, 0.0f, 0.0f}),
        Vec4<float>({0.0f, 0.0f, 0.0f, 0.0f})
    };

    class QuadImpl : public QuadInterface
    {
        public:
        QuadImpl() : 
        m_center({0.0f, 0.0f, 0.0f}),
        m_width(0.0f),
        m_height(0.0f),
        m_vertices(BlankVertices),
        m_colors(BlankColors)
        {
            
        }
        ~QuadImpl() {}

        virtual void setVertices(const Vec4<Vec3<float>> &vertices) override
        {
            m_vertices = vertices;
            updateWidthHeightAndCenter();
        }

        virtual Vec4<Vec3<float>> getVertices() const override
        {
            return m_vertices;
        }

        virtual void setCenter(Vec3<float> center) override
        {
            m_center = center;
            updateVertices();
        }
        virtual Vec3<float> getCenter() const override
        {
            return m_center;
        }

        virtual void setXWidth(float xWidth) override
        {
            m_width = xWidth;
            updateVertices();
        }
        virtual float getXWidth() const override
        {
            return m_width;
        }

        virtual void setYHeight(float yHeight) override
        {
            m_height = yHeight;
            updateVertices();
        }
        virtual float getYHeight() const override
        {
            return m_height;
        }

        virtual void setColor(const Vec4<float> &color) override
        {
            std::get<0>(m_colors) = color;
            std::get<1>(m_colors) = color;            
            std::get<2>(m_colors) = color;            
            std::get<3>(m_colors) = color;
        }

        virtual void setColors(const Vec4<Vec4<float>> &colors) override
        {
            m_colors = colors;
        }

        virtual Vec4<Vec4<float>> getColors() const override
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
            glBegin(GL_TRIANGLE_STRIP);
            
            constexpr int x(0), y(1), z(2);
            constexpr int r(0), g(1), b(2), a(3);

            int v = 3;
            glColor4f(m_colors[v][r], m_colors[v][g], m_colors[v][b], m_colors[v][a]);
            glVertex3f(m_vertices[v][x], m_vertices[v][y], m_vertices[v][z]);
            v = 0;
            glColor4f(m_colors[v][r], m_colors[v][g], m_colors[v][b], m_colors[v][a]);
            glVertex3f(m_vertices[v][x], m_vertices[v][y], m_vertices[v][z]);
            v = 2;
            glColor4f(m_colors[v][r], m_colors[v][g], m_colors[v][b], m_colors[v][a]);
            glVertex3f(m_vertices[v][x], m_vertices[v][y], m_vertices[v][z]);
            v = 1;
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

        void updateVertices() 
        {
            float minx = std::get<0>(m_center) - (m_width/2.0f);
            float maxx = std::get<0>(m_center) + (m_width/2.0f);
            float miny = std::get<1>(m_center) - (m_height/2.0f);
            float maxy = std::get<1>(m_center) + (m_height/2.0f);
            float zval = std::get<2>(m_center);
            std::get<0>(m_vertices) = {minx, maxy, zval};
            std::get<1>(m_vertices) = {maxx, maxy, zval};
            std::get<2>(m_vertices) = {maxx, miny, zval};
            std::get<3>(m_vertices) = {minx, miny, zval};
        }

        void updateWidthHeightAndCenter()
        {
            //Find different xvals
            float x1 = std::get<0>(std::get<0>(m_vertices));
            float x2 = std::get<0>(std::get<1>(m_vertices));
            if(x1 == x2)
                x2 = std::get<0>(std::get<2>(m_vertices));
            m_width = std::abs(x2 - x1);

            //Find different xvals
            float y1 = std::get<1>(std::get<0>(m_vertices));
            float y2 = std::get<1>(std::get<1>(m_vertices));
            if(y1 == y2)
                y2 = std::get<1>(std::get<2>(m_vertices));
            m_height = std::abs(y2 - y1);

            //Find center
            float cx = (std::get<0>(std::get<0>(m_vertices)) + std::get<0>(std::get<1>(m_vertices)) +
                        std::get<0>(std::get<2>(m_vertices)) + std::get<0>(std::get<3>(m_vertices))) /
                       4.0f;
            float cy = (std::get<1>(std::get<0>(m_vertices)) + std::get<1>(std::get<1>(m_vertices)) +
                        std::get<1>(std::get<2>(m_vertices)) + std::get<1>(std::get<3>(m_vertices))) /
                       4.0f;
            float cz = (std::get<2>(std::get<0>(m_vertices)) + std::get<2>(std::get<1>(m_vertices)) +
                        std::get<2>(std::get<2>(m_vertices)) + std::get<2>(std::get<3>(m_vertices))) /
                       4.0f;
            m_center = {cx, cy, cz};
        }

        Vec4<Vec3<float>> m_vertices;
        Vec4<Vec4<float>> m_colors;

        float m_width, m_height;
        Vec3<float> m_center;

        std::vector<std::shared_ptr<RenderObject>> m_ros;
    };
}