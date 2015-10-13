#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "MainComponent.h"
#include "MotionComponent.h"
#include "RenderComponent.h"
#include "ControlsComponent.h"
#include "GravityComponent.h"
#include "ActiveCollisionComponent.h"
#include "PassiveCollisionComponent.h"
#include "RangedAttackComponent.h"
#include "DragAndCarryComponent.h"
#include "DraggableComponent.h"
#include "DropComponent.h"

#include "RenderController.h"
#include "UserActionsController.h"
#include "MotionController.h"
#include "CollisionController.h"
#include "RangedAttackController.h"
#include "DragAndCarryController.h"

#include "Entity.h"
#include "MapStorage.h"
#include "ImageStorage.h"

#include "EntityManager.h"

class HelloWorld : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    EntityManager* entityManager;
    
    ImageStorage* imageStorage;

    virtual bool init() override;

    virtual void update(float delta) override;

    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
