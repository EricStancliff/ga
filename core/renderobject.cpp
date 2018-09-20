#include "renderobject.h"

#include "objectid.h"

namespace ga
{

RenderObject::RenderObject()
{
}

RenderObject::~RenderObject() = default;

ObjectId RenderObject::getObjectId() const
{
    return m_objectId;
}
} // namespace ga