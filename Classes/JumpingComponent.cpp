//
//  JumpingComponent.cpp
//  cppTests
//
//  Created by shum on 10.10.15.
//
//

#include <stdio.h>
#include "JumpingComponent.h"

map<StateType, State*> JumpingComponent::states = {
    {JUMPING_AIR_STATE, new JumpingAirState() },
    {JUMPING_GROUND_STATE, new JumpingGroundState() }
};

float JumpingComponent::velocity = 240;


void JumpingAirState::handleEvent(Entity* entity, MainComponent* component, EventType event) {
    if (event == COLLISION_BOTTOM) {
        JumpingComponent* jumping = static_cast<JumpingComponent*>(component);
        jumping->switchState(jumping->states[JUMPING_GROUND_STATE], entity);
    }
}

void JumpingAirState::onEnter(Entity* entity, MainComponent* component) {
    JumpingComponent* jumping = static_cast<JumpingComponent*>(component);
    MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
    ActiveCollisionComponent* collision = static_cast<ActiveCollisionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, ACTIVE_COLLISION_COMPONENT));
    if (collision->collision[COL_BOTTOM]) {
        motion->dy = jumping->velocity;
    }
}

void JumpingAirState::update(Entity* entity, MainComponent* component) {}
void JumpingAirState::onExit(Entity* entity, MainComponent* component) {}




void JumpingGroundState::handleEvent(Entity* entity, MainComponent* component, EventType event) {
    if (event == INPUT_UP) {
        JumpingComponent* jumping = static_cast<JumpingComponent*>(component);
        component->switchState(jumping->states[JUMPING_AIR_STATE], entity);
    }
}

void JumpingGroundState::onEnter(Entity* entity, MainComponent* component) {
    MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
    motion->dy = 0;
}

void JumpingGroundState::update(Entity* entity, MainComponent* component) {}
void JumpingGroundState::onExit(Entity* entity, MainComponent* component) {}

