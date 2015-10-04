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
    
    int mapSizeX = mapStorage.map[0].size();
    int mapSizeY = mapStorage.map.size();
    
    float fullsizeWidth = visibleSize.width;
    float fullsizeHeight = visibleSize.height;
    
    cout << "fullsizeWidth: " << fullsizeWidth << " and fullsizeHeight: " << fullsizeHeight << endl;
    cout << "mapSizeX: " << mapSizeX << " and mapSizeY: " << mapSizeY << endl;

    for (int i = 0; i < mapStorage.map.size(); i++) {
        for (int j = 0; j < mapStorage.map[i].size(); j++) {
            string id = "brick" + to_string(i) + "::" + to_string(j) + "";
            if (mapStorage.map[i][j]) {
                Entity* ent = new Entity(id, vector<MainComponent *> {
                    new RenderComponent(
                                        this,
                                        "Brick400x400.png",
                                        pair<float, float>(fullsizeWidth/mapSizeX * j + fullsizeWidth/mapSizeX/2 + origin.x, fullsizeHeight/mapSizeY * i + fullsizeWidth/mapSizeX/2),
                                        pair<float, float>(fullsizeWidth/mapSizeX, fullsizeHeight/mapSizeY),
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