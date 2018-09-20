#pragma once
#include "coreexport.h"

#include <cinttypes>

namespace ga
{

    typedef uint_fast64_t ObjectId;

    CORE_EXPORT ObjectId createNewId();
}