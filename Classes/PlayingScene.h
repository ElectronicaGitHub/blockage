//
//  PlayingScene.h
//  cppTests
//
//  Created by shum on 17.10.15.
//
//

#ifndef __cppTests__PlayingScene__
#define __cppTests__PlayingScene__

#include "cocos2d.h"

#include "RenderController.h"
#include "UserActionsController.h"
#include "MotionController.h"
#include "CollisionController.h"
#include "RangedAttackController.h"

#include "EntityManager.h"
#include "Entity.h"
#include "PlayerEntity.h"
#include "BrickEntity.h"

#include "MapStorage.h"
#include "ImageStorage.h"

#include "RenderComponent.h"

using namespace std;

class PlayingAnimateLayer : public cocos2d::Layer {
public:
    UserActionsController* userActionsController;
    
    virtual bool init() override;
    virtual void update(float delta) override;
    
    CREATE_FUNC(PlayingAnimateLayer);
};


class PlayingBGLayer : public cocos2d::Layer {
public:
    virtual bool init() override;
    
    CREATE_FUNC(PlayingBGLayer);
};


#endif /* defined(__cppTests__PlayingScene__) */
