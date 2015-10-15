//
//  RangedAttackComponent.h
//  cppTests
//
//  Created by shum on 06.10.15.
//
//

#ifndef __cppTests__RangedAttackComponent__
#define __cppTests__RangedAttackComponent__

#include <stdio.h>
#include "MainComponent.h"

class RangedAttackComponent : public MainComponent
{
public:
    float damage;
    int cooldown, cooldownCounter;
    ComponentType type = RANGED_ATTACK_COMPONENT;
    RangedAttackComponent(float _damage, int _cooldown) : MainComponent(RANGED_ATTACK_COMPONENT) {
        damage = _damage;
        cooldown = _cooldown;
        cooldownCounter = _cooldown;
    };
    ~RangedAttackComponent() {};
};

#endif /* defined(__cppTests__RangedAttackComponent__) */
