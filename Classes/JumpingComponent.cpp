//
//  JumpingComponent.cpp
//  cppTests
//
//  Created by shum on 10.10.15.
//
//

#include <stdio.h>
#include "JumpingComponent.h"

map<JumpingStateType, State*> JumpingComponent::states = {
    {AIR_STATE, new JumpingAirState() },
    {GROUND_STATE, new JumpingGroundState() }
};

float JumpingComponent::velocity = 250;


void JumpingAirState::handleEvent(Entity* entity, MainComponent* component, EventType event) {
    if (event == COLLISION_BOTTOM) {
        JumpingComponent* jumping = static_cast<JumpingComponent*>(component);
        jumping->switchState(jumping->states[GROUND_STATE], entity);
    }
}

void JumpingAirState::onEnter(Entity* entity, MainComponent* component) {
    JumpingComponent* jumping = static_cast<JumpingComponent*>(component);
    MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
    motion->dy = jumping->velocity;
}

void JumpingAirState::update(Entity* entity, MainComponent* component) {}
void JumpingAirState::onExit(Entity* entity, MainComponent* component) {}


void JumpingGroundState::handleEvent(Entity* entity, MainComponent* component, EventType event) {
    if (event == INPUT_UP) {
        JumpingComponent* jumping = static_cast<JumpingComponent*>(component);
        component->switchState(jumping->states[AIR_STATE], entity);
    }
}

void JumpingGroundState::onEnter(Entity* entity, MainComponent* component) {
    MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
    motion->dy = 0;
}

void JumpingGroundState::update(Entity* entity, MainComponent* component) {}
void JumpingGroundState::onExit(Entity* entity, MainComponent* component) {}

