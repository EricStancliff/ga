
#pragma once
#include <core/types.h>

#include <core/renderobject_interface.h>

namespace ga
{
class QuadInterface : public RenderObjectInterface
{
  public:
    virtual void setVertices(const Vec4<Vec3<float>> &vertices) = 0;
    virtual Vec4<Vec3<float>> getVertices() const = 0;

    virtual void setColor(const Vec4<float> &color) = 0;
    virtual Vec4<float> getColor() const = 0;

    virtual void setColors(const Vec4<Vec4<float>> &colors) = 0;
    virtual Vec4<Vec4<float>> getColors() const = 0;

    virtual void setCenter(Vec3<float>) = 0;
    virtual Vec3<float> getCenter() const = 0;

    virtual void setXWidth(float xWidth) = 0;
    virtual float getXWidth() const = 0;

    virtual void setYHeight(float yHeight) = 0;
    virtual float getYHeight() const = 0;
};
} // namespace ga