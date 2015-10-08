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
#include "ImageStorage.h"
#include "RangedAttackComponent.h"
#include "ControlsComponent.h"
#include "PositionComponent.h"
#include "MotionComponent.h"
#include "RenderComponent.h"
#include "GravityComponent.h"
#include "ActiveCollisionComponent.h"

using namespace std;

class RangedAttackController {
public:
    RangedAttackController() {};
    ~RangedAttackController() {};
    
    void tick(EntityManager* entityManager, ImageStorage* imageStorage, float delta);
};

#endif /* defined(__cppTests__RangedAttackController__) */
