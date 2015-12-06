//
//  PlayingAnimateLayer.h
//  cppTests
//
//  Created by shum on 12.11.15.
//
//

#ifndef __cppTests__PlayingAnimateLayer__
#define __cppTests__PlayingAnimateLayer__

#include <stdio.h>
#include <array>
#include "cocos2d.h"

#include "RenderController.h"
#include "UserActionsController.h"
#include "MotionController.h"
#include "CollisionController.h"
#include "DndController.h"
#include "LifecycleController.h"

#include "EntityManager.h"
#include "Entity.h"
#include "PlayerEntity.h"
#include "BrickEntity.h"

#include "MapStorage.h"
#include "ImageStorage.h"

#include "RenderComponent.h"
#include "LifecycleComponent.h"

#include "CharClass.h"
#include "RangedAttackLv1Skill.h"

using namespace std;

class PlayingAnimateLayer : public cocos2d::Layer {
public:
    UserActionsController* userActionsController;
    MotionController* motionController;
    RenderController* renderController;
    CollisionController* collisionController;
    DndController* dndController;
    LifecycleController* lifecycleController;
    
    virtual bool init() override;
    virtual void update(float delta) override;
    
    CREATE_FUNC(PlayingAnimateLayer);
};

#endif /* defined(__cppTests__PlayingAnimateLayer__) */
