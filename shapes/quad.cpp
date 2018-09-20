#include "quad.h"
#include "quadimpl_p.h"

namespace ga
{
    Quad::Quad() : RenderObject(), p_impl(std::make_unique<QuadImpl>())
    {
    }

    Quad::~Quad()
    {
    }

    void Quad::calculate()
    {
        p_impl->calculate();
    }
    
    void Quad::draw(const std::vector<std::shared_ptr<const Event>>& windowEvents)
    {
        p_impl->draw(windowEvents);
    }

    void Quad::setVertices(const Vec4<Vec3<float>> &vertices)
    {
        p_impl->setVertices(vertices);
    }

    Vec4<Vec3<float>> Quad::getVertices() const
    {
        return p_impl->getVertices();
    }

    void Quad::setColor(const Vec4<float> &color)
    {
        p_impl->setColor(color);
    }

    Vec4<float> Quad::getColor() const
    {
        return p_impl->getColor();
    }

    void Quad::setColors(const Vec4<Vec4<float>> &colors)
    {
        p_impl->setColors(colors);
    }

    Vec4<Vec4<float>> Quad::getColors() const
    {
        return p_impl->getColors();
    }

    void Quad::setCenter(Vec3<float> center)
    {
        p_impl->setCenter(center);
    }
    Vec3<float> Quad::getCenter() const
    {
        return p_impl->getCenter();
    }

    void Quad::setXWidth(float xWidth)
    {
        p_impl->setXWidth(xWidth);
    }
    float Quad::getXWidth() const
    {
        return p_impl->getXWidth();
    }

    void Quad::setYHeight(float yHeight)
    {
        p_impl->setYHeight(yHeight);
    }
    float Quad::getYHeight() const
    {
        return p_impl->getYHeight();
    }

    void Quad::addManagedRenderObject(std::shared_ptr<RenderObject> ro)
    {
        p_impl->addManagedRenderObject(ro);
    }

    void Quad::removeManagedRenderObject(const ObjectId &id)
    {
        p_impl->removeManagedRenderObject(id);
    }
    std::vector<std::shared_ptr<RenderObject>> Quad::getManagedRenderObjects() const
    {
        return p_impl->getManagedRenderObjects();
    }
}