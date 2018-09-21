#pragma once
#include "shapesexport.h"
#include "triangle_interface.h"

#include <memory>

#include <core/renderobject.h>
#include <core/types.h>

namespace ga
{
    class SHAPES_EXPORT Triangle : public RenderObject, public TriangleInterface
    {
        public:
        Triangle();
        virtual ~Triangle();

        virtual void calculate() override;
        virtual void draw(const std::vector<std::shared_ptr<const Event>>& windowEvents) override;

        //Assumes Clockwise winding starting from Top
        virtual void setVertices(const Vec3<Vec3<float>> &vertices) override;
        virtual Vec3<Vec3<float>> getVertices() const override;

        //Assumes Clockwise winding starting from Top-Left
        virtual void setColor(const Vec4<float> &color) override;
        virtual Vec4<float> getColor() const override;

        virtual void setColors(const Vec3<Vec4<float>> &colors) override;
        virtual Vec3<Vec4<float>> getColors() const override;

        virtual void addManagedRenderObject(std::shared_ptr<RenderObject> ro) override;
        virtual void removeManagedRenderObject(const ObjectId &id) override;
        virtual std::vector<std::shared_ptr<RenderObject>> getManagedRenderObjects() const override;

      private:
        std::unique_ptr<TriangleInterface> p_impl;
    };
}