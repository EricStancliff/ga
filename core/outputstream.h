#pragma once
#include <iostream>

#include "coreexport.h"

namespace ga
{

enum Severity
{
    INFO,
    DEBUG,
    WARNING,
    ERROR,
    CRITICAL
};

CORE_EXPORT void setOutputStream(Severity s, std::ostream& os);

CORE_EXPORT std::ostream& info();
CORE_EXPORT std::ostream& debug();
CORE_EXPORT std::ostream& warning();
CORE_EXPORT std::ostream& error();
CORE_EXPORT std::ostream& critical();

} // namespace ga