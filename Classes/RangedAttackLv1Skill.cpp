//
//  RangedAttackLv1Skill.cpp
//  cppTests
//
//  Created by shum on 19.11.15.
//
//

#include "RangedAttackLv1Skill.h"

map<StateType, State*> RangedAttackLv1Skill::states = {
    {ATTACK_READY, new RangedLv1ReadyState() },
    {ATTACK_RELOAD, new RangedLv1ReloadState() }
};

void RangedLv1ReadyState::handleEvent(Entity* entity, MainComponent* component, EventType event) {
    RangedAttackLv1Skill* attack = static_cast<RangedAttackLv1Skill*>(component);
    component->switchState(attack->states[ATTACK_RELOAD], entity);
}

void RangedLv1ReadyState::onEnter(Entity* entity, MainComponent* component) {}
void RangedLv1ReadyState::update(Entity* entity, MainComponent* component, float delta) {}
void RangedLv1ReadyState::onExit(Entity* entity, MainComponent* component) {
    RangedAttackLv1Skill* attack = static_cast<RangedAttackLv1Skill*>(component);
    
    PositionComponent* position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
    MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
    Entity* stone = new StoneEntity();
    EntityManager::addEntity(stone);

    EntityManager::addComponentsToEntity(stone, {
        new MotionComponent(250 * position->orientation + motion->dx, 250),
        new PositionComponent(position->x, position->y, 1),
        new RenderComponent(GameStateManager::getAnimateLayer(), IMAGE_STONE, {7, 7}),
        new ActiveCollisionComponent("player", {"player", "block"})
    });

    attack->cooldownCounter = attack->cooldown;
}



void RangedLv1ReloadState::handleEvent(Entity* entity, MainComponent* component, EventType event) {}
void RangedLv1ReloadState::onEnter(Entity* entity, MainComponent* component) {}
void RangedLv1ReloadState::update(Entity* entity, MainComponent* component, float delta) {
    RangedAttackLv1Skill* attack = static_cast<RangedAttackLv1Skill*>(component);
    if (attack->cooldownCounter > 0) {
        attack->cooldownCounter -= delta;
        
    } else {
        component->switchState(attack->states[ATTACK_READY], entity);
    }
}
void RangedLv1ReloadState::onExit(Entity* entity, MainComponent* component) {}



void RangedAttackLv1Skill::release(Entity* entity) {
    currentState->handleEvent(entity, this, ATTACK_RELEASE);
}