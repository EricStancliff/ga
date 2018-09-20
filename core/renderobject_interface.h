#pragma once
#include <memory>
#include <vector>
namespace ga
{
class Event;

typedef uint_fast64_t ObjectId;
class RenderObject;

class RenderObjectInterface
{
  public:
    virtual void calculate() = 0;

    virtual void draw(const std::vector<std::shared_ptr<const Event>>& windowEvents) = 0;

    virtual void addManagedRenderObject(std::shared_ptr<RenderObject> ro) = 0;
    virtual void removeManagedRenderObject(const ObjectId& id) = 0;
    virtual std::vector<std::shared_ptr<RenderObject>> getManagedRenderObjects() const = 0;
};
} // namespace ga