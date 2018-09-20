#pragma once
#include <string>
#include <memory>
#include <vector>


namespace ga
{
class Event;
class RenderObject;
typedef uint_fast64_t ObjectId;

class WindowInterface {

public:

    virtual void tick() = 0;
    
    virtual void setWindowName(const std::string& name) = 0;

    virtual std::vector<std::shared_ptr<const Event>> getWindowEvents() const = 0;

    virtual bool isDestroyed() const = 0;

    virtual void addRenderObject(std::shared_ptr<RenderObject> object) = 0;
    virtual void removeRenderObject(const ObjectId& id) = 0;
    virtual std::vector<std::shared_ptr<RenderObject>> getRenderObjects() const = 0;
};
}