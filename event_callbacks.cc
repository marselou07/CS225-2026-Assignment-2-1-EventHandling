#include "event_callbacks.hh"
/******************************************************************************
filename    event_callbacks.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.1
due date    15/10/2026

Brief Description: Thid program will the functions of a event 
manager
******************************************************************************/
/**
 * subscribe
 * @param context: the information of the listener
 * @param callback: the object which will call the event
 * @return nothing
 */
void EventDispatcher::subscribe(void* context, CallbackFunction callback)
{
    EventListener listener = {context,callback};
    this->Listeners_Subscribed.push_back(listener);
}
/**
 * getListenerAt
 * @param position: position of the listener on
 * the vector
 * @return EventListener: the eventlistener on 
 * that position
 */
EventListener *EventDispatcher::getListenerAt(int position)
{
    return  &(this->Listeners_Subscribed[position]);
}
/**
 * dispatchEvent
 * @param eventnotify: the event that will
 * be called
 * @return nothing
 */
void EventDispatcher::dispatchEvent(Event *eventnotify)
{
    for(auto listeners : this->Listeners_Subscribed)
    {
        listeners.callbackFunction(listeners.contextObject,eventnotify);
    }
}
