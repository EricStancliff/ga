#include "triangle.h"
#include "triangleimpl_p.h"

namespace ga
{
    Triangle::Triangle() : RenderObject(), p_impl(std::make_unique<TriangleImpl>())
    {
    }

    Triangle::~Triangle()
    {
    }

    void Triangle::calculate()
    {
        p_impl->calculate();
    }
    
    void Triangle::draw(const std::vector<std::shared_ptr<const Event>>& windowEvents)
    {
        p_impl->draw(windowEvents);
    }

    void Triangle::setVertices(const Vec3<Vec3<float>> &vertices)
    {
        p_impl->setVertices(vertices);
    }

    Vec3<Vec3<float>> Triangle::getVertices() const
    {
        return p_impl->getVertices();
    }

    void Triangle::setColor(const Vec4<float> &color)
    {
        p_impl->setColor(color);
    }

    Vec4<float> Triangle::getColor() const
    {
        return p_impl->getColor();
    }

    void Triangle::setColors(const Vec3<Vec4<float>> &colors)
    {
        p_impl->setColors(colors);
    }

    Vec3<Vec4<float>> Triangle::getColors() const
    {
        return p_impl->getColors();
    }

    void Triangle::addManagedRenderObject(std::shared_ptr<RenderObject> ro)
    {
        p_impl->addManagedRenderObject(ro);
    }

    void Triangle::removeManagedRenderObject(const ObjectId &id)
    {
        p_impl->removeManagedRenderObject(id);
    }
    std::vector<std::shared_ptr<RenderObject>> Triangle::getManagedRenderObjects() const
    {
        return p_impl->getManagedRenderObjects();
    }
}