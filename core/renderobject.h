#pragma once
#include "renderobject_interface.h"
#include "coreexport.h"

#include "objectid.h"

#include <memory>

namespace ga
{


class CORE_EXPORT RenderObject : public RenderObjectInterface
{
  public:
    RenderObject();
    virtual ~RenderObject() = 0;

    ObjectId getObjectId() const;

  protected:
    ObjectId m_objectId;
};
} // namespace ga