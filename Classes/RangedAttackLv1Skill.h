//
//  RangedAttackLv1Skill.h
//  cppTests
//
//  Created by shum on 19.11.15.
//
//

#ifndef __cppTests__RangedAttackLv1Skill__
#define __cppTests__RangedAttackLv1Skill__

#include <stdio.h>
#include <iostream>
#include "Skill.h"
#include "EntityManager.h"
#include "GameStateManager.h"

#include "StoneEntity.h"

using namespace std;

class RangedLv1ReadyState : public State
{
public:
    RangedLv1ReadyState(){}
    ~RangedLv1ReadyState(){}
    
    void handleEvent(Entity* entity, MainComponent* component, EventType event) override;
    void update(Entity* entity, MainComponent* component, float delta) override;
    void onEnter(Entity* entity, MainComponent* component) override;
    void onExit(Entity* entity, MainComponent* component) override;
};


class RangedLv1ReloadState : public State
{
public:
    RangedLv1ReloadState(){}
    ~RangedLv1ReloadState(){}
    
    void handleEvent(Entity* entity, MainComponent* component, EventType event) override;
    void update(Entity* entity, MainComponent* component, float delta) override;
    void onEnter(Entity* entity, MainComponent* component) override;
    void onExit(Entity* entity, MainComponent* component) override;
};


class RangedAttackLv1Skill : public Skill
{
public:
    float damage, cooldown, cooldownCounter;
    SkillName name = RANGED_ATTACK_LV1_SKILL;
    
    static map<StateType, State*> states;
    RangedAttackLv1Skill()
    : Skill(states.find(ATTACK_READY)->second)
    , damage(30)
    , cooldown(0.3)
    , cooldownCounter(cooldown)
    {}
    ~RangedAttackLv1Skill(){}
    
    void release(Entity* entity) override;
};

#endif /* defined(__cppTests__RangedAttackLv1Skill__) */
