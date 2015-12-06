//
//  JumpingComponent.hpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#ifndef JumpingComponent_hpp
#define JumpingComponent_hpp

#include <stdio.h>
#include "MainComponent.h"
#include "MotionComponent.h"
#include "State.h"
#include "Entity.h"
#include "EntityManager.h"

using namespace std;

class JumpingAirState : public State
{
public:
    JumpingAirState(){}
    ~JumpingAirState(){}
    
    void handleEvent(Entity* entity, MainComponent* component, EventType event) override;
    void update(Entity* entity, MainComponent* component, float delta) override;
    void onEnter(Entity* entity, MainComponent* component) override;
    void onExit(Entity* entity, MainComponent* component) override;
};


class JumpingGroundState : public State
{
public:
    JumpingGroundState(){}
    ~JumpingGroundState(){}
    
    void handleEvent(Entity* entity, MainComponent* component, EventType event) override;
    void update(Entity* entity, MainComponent* component, float delta) override;
    void onEnter(Entity* entity, MainComponent* component) override;
    void onExit(Entity* entity, MainComponent* component) override;
};


class JumpingComponent : public MainComponent
{
public:
    ComponentType type = JUMPING_COMPONENT;
    
    static float velocity;
    static map<StateType, State*> states;
    
    JumpingComponent() : MainComponent(JUMPING_COMPONENT, states.find(JUMPING_AIR_STATE)->second) {}
    ~JumpingComponent(){}
};

#endif /* JumpingComponent_hpp */
