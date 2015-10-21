//
//  State.h
//  cppTests
//
//  Created by shum on 08.10.15.
//
//

#ifndef __cppTests__State__
#define __cppTests__State__

#include <stdio.h>

class Entity;
class EntityManager;
class MainComponent;

enum EventType {
    COLLISION_TOP, COLLISION_BOTTOM, COLLISION_LEFT, COLLISION_RIGHT,
    INPUT_UP, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT,
    INPUT_Z, INPUT_X, INPUT_C, INPUT_V,
    INPUT_SPACE
};

class State
{
public:
    ~State() {}

    virtual void handleEvent(Entity* entity, MainComponent* component, EventType event) = 0;
    virtual void update(Entity* entity, MainComponent* component) = 0;
    virtual void onEnter(Entity* entity, MainComponent* component) = 0;
    virtual void onExit(Entity* entity, MainComponent* component) = 0;
};

#endif /* defined(__cppTests__State__) */
