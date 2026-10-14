#include "event_callbacks.hh"

void EventDispatcher::subscribe(void* context, CallbackFunction callback)
{
    EventListener listener = {context,callback};
    this->Listeners_Subscribed.push_back(&listener);
}

EventListener *EventDispatcher::getListenerAt(int position)
{
    return  this->Listeners_Subscribed[position];
}

void EventDispatcher::dispatchEvent(Event *eventnotify)
{
    for(auto listeners : this->Listeners_Subscribed)
    {
        listeners->callbackFunction(listeners->contextObject,eventnotify);
    }
}
