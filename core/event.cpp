#include "event.h"

namespace ga{

std::string eventTypeToString(EventType type)
{
    switch (type)
    {
    case KeyPress:
        return "KeyPress";
        break;
    case KeyRelease:
        return "KeyRelease";
        break;
    case ButtonPress:
        return "ButtonPress";
        break;
    case ButtonRelease:
        return "ButtonRelease";
        break;
    case MotionNotify:
        return "MotionNotify";
        break;
    case EnterNotify:
        return "EnterNotify";
        break;
    case LeaveNotify:
        return "LeaveNotify";
        break;
    case FocusIn:
        return "FocusIn";
        break;
    case FocusOut:
        return "FocusOut";
        break;
    case KeymapNotify:
        return "KeymapNotify";
        break;
    case Expose:
        return "Expose";
        break;
    case GraphicsExpose:
        return "GraphicsExpose";
        break;
    case NoExpose:
        return "NoExpose";
        break;
    case VisibilityNotify:
        return "VisibilityNotify";
        break;
    case CreateNotify:
        return "CreateNotify";
        break;
    case DestroyNotify:
        return "DestroyNotify";
        break;
    case UnmapNotify:
        return "UnmapNotify";
        break;
    case MapNotify:
        return "MapNotify";
        break;
    case MapRequest:
        return "MapRequest";
        break;
    case ReparentNotify:
        return "ReparentNotify";
        break;
    case ConfigureNotify:
        return "ConfigureNotify";
        break;
    case ConfigureRequest:
        return "ConfigureRequest";
        break;
    case GravityNotify:
        return "GravityNotify";
        break;
    case ResizeRequest:
        return "ResizeRequest";
        break;
    case CirculateNotify:
        return "CirculateNotify";
        break;
    case CirculateRequest:
        return "CirculateRequest";
        break;
    case PropertyNotify:
        return "PropertyNotify";
        break;
    case SelectionClear:
        return "SelectionClear";
        break;
    case SelectionRequest:
        return "SelectionRequest";
        break;
    case SelectionNotify:
        return "SelectionNotify";
        break;
    case ColormapNotify:
        return "ColormapNotify";
        break;
    case ClientMessage:
        return "ClientMessage";
        break;
    case MappingNotify:
        return "MappingNotify";
        break;
    case GenericEvent:
        return "GenericEvent";
        break;
    default:
        return "UnknownEventType";
        break;
    }
}

Event::Event(EventType type) : m_eventType(type)
{
}
Event::~Event()
{
}

EventType Event::getEventType() const
{
    return m_eventType;
}
} // namespace ga