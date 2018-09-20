#pragma once
#include "windowexport.h"
#include "window_interface.h"
#include <core/event.h>

#include <memory>
#include <vector>

namespace ga
{
    class Window : public WindowInterface
    {
        public:
        Window(const std::string& windowName);
        virtual ~Window();

        virtual void tick() override;

        virtual void setWindowName(const std::string& name) override;

        virtual bool isDestroyed() const override;

        virtual std::vector<std::shared_ptr<const Event>> getWindowEvents() const override;

        virtual void addRenderObject(std::shared_ptr<RenderObject> object) override;
        virtual void removeRenderObject(const ObjectId& id) override;
        virtual std::vector<std::shared_ptr<RenderObject>> getRenderObjects() const override;

        private:

        std::unique_ptr<WindowInterface> p_impl;
    };   
}