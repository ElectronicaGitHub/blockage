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
    string type = "RangedAttackComponent";
    RangedAttackComponent(float _damage, int _cooldown) : MainComponent("RangedAttackComponent") {
        damage = _damage;
        cooldown = _cooldown;
        cooldownCounter = _cooldown;
    };
    ~RangedAttackComponent() {};
};

#endif /* defined(__cppTests__RangedAttackComponent__) */
