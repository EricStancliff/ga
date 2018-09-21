
#pragma once
#include <core/types.h>

#include <core/renderobject_interface.h>

namespace ga
{
class TriangleInterface : public RenderObjectInterface
{
  public:
    virtual void setVertices(const Vec3<Vec3<float>> &vertices) = 0;
    virtual Vec3<Vec3<float>> getVertices() const = 0;

    virtual void setColor(const Vec4<float> &color) = 0;
    virtual Vec4<float> getColor() const = 0;

    virtual void setColors(const Vec3<Vec4<float>> &colors) = 0;
    virtual Vec3<Vec4<float>> getColors() const = 0;
};
} // namespace ga