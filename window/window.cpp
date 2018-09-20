#include "window.h"

#include "windowimpl_p.h"

namespace ga
{

Window::Window(const std::string& windowName) : p_impl(std::make_unique<WindowImpl>(windowName))
{
}

Window::~Window()
{
}

void Window::tick()
{
  p_impl->tick();
}

bool Window::isDestroyed() const
{
  return p_impl->isDestroyed();
}

void Window::setWindowName(const std::string& name)
{
  p_impl->setWindowName(name);
}

std::vector<std::shared_ptr<const Event>> Window::getWindowEvents() const
{
  return p_impl->getWindowEvents();  //makes copy to return
}

void Window::addRenderObject(std::shared_ptr<RenderObject> object)
{
  p_impl->addRenderObject(object);
}

void Window::removeRenderObject(const ObjectId& id)
{
  p_impl->removeRenderObject(id);
}

std::vector<std::shared_ptr<RenderObject>> Window::getRenderObjects() const
{
  return p_impl->getRenderObjects();
}

} // namespace ga