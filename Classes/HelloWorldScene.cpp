#include "HelloWorldScene.h"
#include "EntityManager.h"
#include "MainComponent.h"
#include "MovementComponent.h"
#include "MovementController.h"
#include "RenderComponent.h"
#include "RenderController.h"
#include "ControlsComponent.h"
#include "UserActionsController.h"
#include "Entity.h"

using namespace std;

USING_NS_CC;

Scene* HelloWorld::createScene() {
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    
    return scene;
}
bool HelloWorld::init() {
    if ( !Layer::init() ) {
        return false;
    }

    EntityManager entityManager;
    
    Entity* entity1 = new Entity("aaaa", vector<MainComponent *>{
        new MovementComponent(),
        new RenderComponent(this, "CloseSelected.png", pair<float, float>(50, 50)),
        new ControlsComponent()
    });
    
    entityManager.AddEntity(entity1);
    
    UserActionsController(_eventDispatcher, this);
    
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta) {
    MovementController mc;
    RenderController rc;
    
    rc.tick();
    mc.tick();
}