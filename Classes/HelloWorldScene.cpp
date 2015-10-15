#include "HelloWorldScene.h"

using namespace std;

USING_NS_CC;

Scene* HelloWorld::createScene() {
    auto scene = Scene::createWithPhysics();
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
    
    MapStorage mapStorage;
    
    int mapSizeX = mapStorage.map[0].size();
    int mapSizeY = mapStorage.map.size();
    
    float fullsizeWidth = visibleSize.width;
    float fullsizeHeight = visibleSize.height;
    
    pair<float, float> tileSize = { round(fullsizeWidth/mapSizeX), round(fullsizeHeight/mapSizeY) };
    
    cout << "fullsizeWidth: " << fullsizeWidth << " and fullsizeHeight: " << fullsizeHeight << endl;
    cout << "mapSizeX: " << mapSizeX << " and mapSizeY: " << mapSizeY << endl;

    for (int i = 0; i < mapStorage.map.size(); i++) {
        for (int j = 0; j < mapStorage.map[i].size(); j++) {
            string id = "brick" + to_string(i) + "::" + to_string(j) + "";
            if (mapStorage.map[i][j]) {
                Entity* ent = new BrickEntity();
                EntityManager::addEntity(ent);
                EntityManager::addComponentsToEntity(ent, {
                    new RenderComponent(this, IMAGE_WALL, tileSize),
                    new PositionComponent(tileSize.first * j + tileSize.second/2 + origin.x, tileSize.second * i + tileSize.second/2 + origin.y, 1)
                });
            
            }
        }
    }
    
    Entity* player = new PlayerEntity();
    EntityManager::addEntity(player);
    EntityManager::addComponentsToEntity(player, {
        new RenderComponent(this, IMAGE_DWARF, pair<float, float>(20, 20)),
    });
    
    userActionsController = new UserActionsController(_eventDispatcher, this);
    
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta) {
    MotionController motionController;
    RangedAttackController rangedAttackController;
    RenderController renderController;
    CollisionController collisionController;
    
    userActionsController->tick(delta);
    motionController.tick(delta);
    rangedAttackController.tick(this, delta);
    renderController.tick(delta);
    collisionController.tick();
}