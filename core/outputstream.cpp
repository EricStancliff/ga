#include "outputstream.h"

namespace ga
{
    std::ostream* InfoStream = &std::cout;
    std::ostream* DebugStream = &std::cout;
    std::ostream* WarningStream = &std::cout;
    std::ostream* ErrorStream = &std::cout;
    std::ostream* CriticalStream = &std::cout;


void setOutputStream(Severity s, std::ostream& os)
{
    switch(s)
    {
    case INFO:
        InfoStream = &os;
        break;
    case DEBUG:
        DebugStream = &os;
        break;
    case WARNING:
        WarningStream = &os;
        break;
    case ERROR:
        ErrorStream = &os;
        break;
    case CRITICAL:
        CriticalStream = &os;
        break;
    default:
        error() << "Undefined Stream Type " << s;
        break;
    };
}

std::ostream& info()
{
    return *InfoStream;
}
std::ostream& debug()
{
    return *InfoStream;
}
std::ostream& warning()
{
    return *InfoStream;
}
std::ostream& error()
{
    return *InfoStream;
}
std::ostream& critical()
{
    return *InfoStream;
}

}