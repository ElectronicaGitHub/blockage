//
//  Component.h
//  cppTests
//
//  Created by Philip Antonov on 25.09.15.
//
//

#ifndef __cppTests__Component__
#define __cppTests__Component__

#include <stdio.h>
#include "State.h"

using namespace std;

class EntityManager;
class Entity;

enum ComponentType {
    RENDER_COMPONENT, CONTROLS_COMPONENT, ACTIVE_COLLISION_COMPONENT, PASSIVE_COLLISION_COMPONENT,
    POSITION_COMPONENT, MOTION_COMPONENT, GRAVITY_COMPONENT, JUMPING_COMPONENT, RANGED_ATTACK_COMPONENT
};

class MainComponent
{
public:
    ComponentType type;
    MainComponent() {};
    MainComponent(ComponentType _type)
        : type(_type)
        {}
    MainComponent(ComponentType _type, State* state)
        : type(_type)
        , currentState(state)
        {}
    virtual ~MainComponent() {};
    
    State* getCurrentState();
    void switchState(State* state, Entity* entity);

protected:
    State* currentState;
};

#endif /* defined(__cppTests__Component__) */
