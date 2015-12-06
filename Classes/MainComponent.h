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
    RENDER_COMPONENT, ANIMATION_COMPONENT,
    CONTROLS_COMPONENT, ACTIVE_COLLISION_COMPONENT, PASSIVE_COLLISION_COMPONENT,
    POSITION_COMPONENT, MOTION_COMPONENT, GRAVITY_COMPONENT, JUMPING_COMPONENT,
    DRAG_COMPONENT, DROP_COMPONENT, DND_COMPONENT,
    LIFECYCLE_COMPONENT,
    SKILL_RELEASE_COMPONENT,
    
    SKILL
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
    virtual ~MainComponent() = 0;
    
    State* getCurrentState();
    void switchState(State* state, Entity* entity);
    void updateState(Entity* entity);
    void updateState(Entity* entity, float delta);

protected:
    State* currentState;
};

#endif /* defined(__cppTests__Component__) */
