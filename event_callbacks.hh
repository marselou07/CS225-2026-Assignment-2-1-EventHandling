#pragma once
#include <vector>
#include "event.hh"
typedef void (*CallbackFunction)(void* context, Event* event);

struct EventListener
{

// Object listening the event (Who)
void* contextObject;
// Method to call (How)
CallbackFunction callbackFunction; 

};

class EventDispatcher
{
    std::vector<EventListener> Listeners_Subscribed;
    public:
    void subscribe(void* context, CallbackFunction callback);
    EventListener* getListenerAt(int position);
    void dispatchEvent(Event * eventnotify);
};