//
//  DndComponent.h
//  cppTests
//
//  Created by Philip Antonov on 20.10.15.
//
//

#ifndef __cppTests__DndComponent__
#define __cppTests__DndComponent__

#include <stdio.h>
#include "MainComponent.h"
#include "DragComponent.h"
#include "Entity.h"

class EmptyState : public State
{
public:
    EmptyState(){}
    ~EmptyState(){}
    
    void handleEvent(Entity* entity, MainComponent* component, EventType event) override;
    void update(Entity* entity, MainComponent* component) override;
    void onEnter(Entity* entity, MainComponent* component) override;
    void onExit(Entity* entity, MainComponent* component) override;
};

class DraggingState : public State
{
public:
    DraggingState(){}
    ~DraggingState(){}
    
    void handleEvent(Entity* entity, MainComponent* component, EventType event) override;
    void update(Entity* entity, MainComponent* component) override;
    void onEnter(Entity* entity, MainComponent* component) override;
    void onExit(Entity* entity, MainComponent* component) override;
};

class DndComponent : public MainComponent {
public:
    StateType currentStateType = DND_EMPTY_STATE;
    bool buttonPressed;
    Entity* draggingEntity;
    static map<StateType, State*> states;
    
    DndComponent() : MainComponent(DND_COMPONENT, states.find(DND_EMPTY_STATE)->second) {};
    ~DndComponent() {};
};

#endif /* defined(__cppTests__DndComponent__) */
