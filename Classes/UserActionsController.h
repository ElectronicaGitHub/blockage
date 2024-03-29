//
//  UserActionsController.h
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#ifndef __cppTests__UserActionsController__
#define __cppTests__UserActionsController__

#include <stdio.h>
#include "iostream"
#include "ControlsComponent.h"
#include "MotionComponent.h"
#include "JumpingComponent.h"
#include "SkillReleaseComponent.h"
#include "EntityManager.h"

using namespace cocos2d;
using namespace std;

class UserActionsController {
public:
    UserActionsController(EventDispatcher* evd, Layer* _this, ControlsComponent* controls);
    ~UserActionsController() {};
    
    void tick(Entity* entity, float delta);
};

#endif /* defined(__cppTests__UserActionsController__) */
