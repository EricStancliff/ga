#pragma once
#include "shapesexport.h"
#include "quad_interface.h"

#include <memory>

#include <core/renderobject.h>
#include <core/types.h>

namespace ga
{
    class SHAPES_EXPORT Quad : public RenderObject, public QuadInterface
    {
        public:
        Quad();
        virtual ~Quad();

        virtual void calculate() override;
        virtual void draw(const std::vector<std::shared_ptr<const Event>>& windowEvents) override;

        //Assumes Clockwise winding starting from Top-Left
        virtual void setVertices(const Vec4<Vec3<float>> &vertices) override;
        virtual Vec4<Vec3<float>> getVertices() const override;

        //Assumes Clockwise winding starting from Top-Left
        virtual void setColor(const Vec4<float> &color) override;
        virtual Vec4<float> getColor() const override;

        virtual void setColors(const Vec4<Vec4<float>> &colors) override;
        virtual Vec4<Vec4<float>> getColors() const override;

        virtual void setCenter(Vec3<float>) override;
        virtual Vec3<float> getCenter() const override; 

        virtual void setXWidth(float xWidth) override;
        virtual float getXWidth() const override;

        virtual void setYHeight(float yHeight) override;
        virtual float getYHeight() const override;

        virtual void addManagedRenderObject(std::shared_ptr<RenderObject> ro) override;
        virtual void removeManagedRenderObject(const ObjectId &id) override;
        virtual std::vector<std::shared_ptr<RenderObject>> getManagedRenderObjects() const override;

      private:
        std::unique_ptr<QuadInterface> p_impl;
    };
}