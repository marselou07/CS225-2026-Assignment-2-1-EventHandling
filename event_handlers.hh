#pragma once
#include "event.hh"
#include "vector"
class IEventHandler
{
public:
virtual void call(Event* event) = 0;
};


template<typename TObject, typename TEvent>
class EventHandler : public IEventHandler
{
    typedef void (TObject::*MethodType)(TEvent*);
    TObject* ObjectT; // Who
    MethodType ActionMethod; // How

    public:
    EventHandler(TObject* obj, MethodType method)
    {
        ObjectT = obj;
        ActionMethod = method;
    }
    void call(Event* event) 
    {
        TEvent* specific_event = dynamic_cast<TEvent*>(event);
        if(specific_event != nullptr) // What
        (ObjectT->*ActionMethod)(specific_event); 
    }
};
class EventManager
{
    std::vector<IEventHandler*>Listeners_Subscribed;
    public:
    void registerEventHandler(IEventHandler* handler);
    IEventHandler* getEventHandlerAt(int position);
    void notifyEvent(Event* e);
};

