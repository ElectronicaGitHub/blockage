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
#include "MapStorage.h"

using namespace std;

USING_NS_CC;

Scene* HelloWorld::createScene() {
    auto scene = Scene::createWithPhysics();
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vect(0, -200));
    
    auto layer = HelloWorld::create();
    
    scene->addChild(layer);
    
    return scene;
}
bool HelloWorld::init() {
    if ( !Layer::init() ) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create screen boundary
    
    auto edgeNode = Node::create();
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    
    edgeNode->setPhysicsBody(edgeBody);
    edgeNode->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(edgeNode);
    // screen boundary ended

    EntityManager entityManager;
    EntityManager entityManagerStatic;
    
    Entity* entity1 = new Entity("aaaa", vector<MainComponent *> {
        new MovementComponent(),
        new RenderComponent(this, "CloseSelected.png", pair<float, float>(200, 200), pair<float, float>(20, 20), "sprite"),
        new ControlsComponent()
    });
    
    MapStorage mapStorage;

    for (int i = mapStorage.map.size(); i > 0; i--) {
        for (int j = mapStorage.map[i].size(); j > 0; j--) {
            string id = "brick" + to_string(i) + "::" + to_string(j) + "";
            if (mapStorage.map[mapStorage.map.size() - i][mapStorage.map[i].size() - j]) {
                Entity* ent = new Entity(id, vector<MainComponent *> {
                    new RenderComponent(
                                        this,
                                        "Brick400x400.png",
                                        pair<float, float>(visibleSize.width/20 * (int)(j+1)- visibleSize.width/20/3, visibleSize.height/15 * (int)(i) - visibleSize.height/15/2),
                                        pair<float, float>(visibleSize.width/20, visibleSize.height/15),
                                        "node"),
                });
                entityManagerStatic.AddEntity(ent);
            }
        }
    }
    
    entityManager.AddEntity(entity1);
    
    UserActionsController(_eventDispatcher, this);
    
    this->scheduleUpdate();
    
    RenderController rc;
//    MovementController mc;
    rc.tick();
//    mc.tick();
    
    return true;
}

void HelloWorld::update(float delta) {
    MovementController mc;
//    RenderController rc;
//    
//    rc.tick();
    mc.tick();
}