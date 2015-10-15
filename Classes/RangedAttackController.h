//
//  RangedAttackController.h
//  cppTests
//
//  Created by shum on 06.10.15.
//
//

#ifndef __cppTests__RangedAttackController__
#define __cppTests__RangedAttackController__

#include <stdio.h>
#include "EntityManager.h"
#include "StoneEntity.h"

#include "RangedAttackComponent.h"
#include "PositionComponent.h"
#include "MotionComponent.h"

using namespace std;

class RangedAttackController {
public:
    RangedAttackController() {};
    ~RangedAttackController() {};
    
    void tick(cocos2d::Layer* layer, float delta);
};

#endif /* defined(__cppTests__RangedAttackController__) */
