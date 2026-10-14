#include "event_handlers.hh"
/******************************************************************************
filename    event_handlers.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.1
due date    15/10/2026

Brief Description: Thid program will implement the functions of a generic event 
manager.
******************************************************************************/
/**
 * registerEventHandler
 * @param handler: Ievent handler that will be stored 
 * on the vector
 * @return nothing
 */
void EventManager::registerEventHandler(IEventHandler *handler)
{
    Listeners_Subscribed.push_back(handler);
}
/**
 * getEventHandlerAt
 * @param position: the position on the vector to 
 * get the handler
 * @return IEventHandler: in that position
 */
IEventHandler *EventManager::getEventHandlerAt(int position)
{

    return Listeners_Subscribed[position];
}
/**
 * notifyEvent
 * @param Event *e: event to notify to the other 
 * listeners
 * @return nothing
 */
void EventManager::notifyEvent(Event *e)
{
    for(auto *listener : Listeners_Subscribed) 
    {
        listener->call(e);
    }
}
