#include "objectid.h"
#include <atomic>

namespace ga
{

        std::atomic_uint_fast64_t globalIdCounter;

        ObjectId createNewId()
        {
            return globalIdCounter.fetch_add(1);
        }

}