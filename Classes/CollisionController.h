//
//  CollisionController.h
//  cppTests
//
//  Created by Philip Antonov on 06.10.15.
//
//

#ifndef __cppTests__CollisionController__
#define __cppTests__CollisionController__

#include <stdio.h>
#include "EntityManager.h"
#include "RenderComponent.h"
#include "ActiveCollisionComponent.h"
#include "PositionComponent.h"
#include "JumpingComponent.h"

using namespace cocos2d;

class CollisionController {
public:
    float controlPanelSize = 3;
    CollisionController() {};
    ~CollisionController() {};
    void tick();
};

#endif /* defined(__cppTests__CollisionController__) */