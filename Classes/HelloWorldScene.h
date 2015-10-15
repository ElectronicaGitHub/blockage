#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

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


class HelloWorld : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();

    UserActionsController* userActionsController;

    virtual bool init() override;

    virtual void update(float delta) override;

    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
