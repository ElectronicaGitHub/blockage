//
//  PlayingScene.cpp
//  cppTests
//
//  Created by shum on 17.10.15.
//
//

#include "PlayingScene.h"

bool PlayingAnimateLayer::init() {
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
    
    pair<float, float> tileSize = { fullsizeWidth/mapSizeX, fullsizeHeight/mapSizeY };
    
    cout << "fullsizeWidth: " << fullsizeWidth << " and fullsizeHeight: " << fullsizeHeight << endl;
    cout << "mapSizeX: " << mapSizeX << " and mapSizeY: " << mapSizeY << endl;
    
    for (int i = 0; i < mapStorage.map.size(); i++) {
        for (int j = 0; j < mapStorage.map[i].size(); j++) {
            string id = "brick" + to_string(i) + "::" + to_string(j) + "";
            if (mapStorage.map[i][j] != 0) {
                Entity* ent = new BrickEntity();
                EntityManager::addEntity(ent);
                EntityManager::addComponentToEntity(ent, new PositionComponent(tileSize.first * j + tileSize.first/2 + origin.x, tileSize.second * i + tileSize.second/2 + origin.y, 1));
                
                if (mapStorage.map[i][j] == 2) {
                    EntityManager::addComponentsToEntity(ent, {
                        new DropComponent(),
                        new RenderComponent(this, IMAGE_WALL_DROP, tileSize),
                    });
                }
                else if (mapStorage.map[i][j] == 1) {
                    EntityManager::addComponentsToEntity(ent, {
                        new RenderComponent(this, IMAGE_WALL, tileSize),
                        new PassiveCollisionComponent()
                    });
                }
                
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

void PlayingAnimateLayer::update(float delta) {
    MotionController motionController;
    RangedAttackController rangedAttackController;
    RenderController renderController;
    CollisionController collisionController;
    
    for (int i = 0 ; i != EntityManager::entities.size(); ++i) {
        Entity* entity = EntityManager::entities[i];
        
        userActionsController->tick(entity, delta);
        motionController.tick(entity, delta);
        rangedAttackController.tick(entity, this, delta);
        renderController.tick(entity, delta);
        collisionController.tick(entity);
        
        if (entity->deleted) {
            EntityManager::removeEntity(entity);
            i--;
        }
    }
}





bool PlayingBGLayer::init() {
    if ( !Layer::init() ) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    cocos2d::Sprite* sprite = cocos2d::Sprite::create(ImageStorage::getImage(IMAGE_BACKGROUND));
    sprite->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    sprite->setScale(0.5);
    
    Size contentSize = sprite->getContentSize();
    sprite->setScaleX(visibleSize.width / contentSize.width);
    sprite->setScaleY(visibleSize.height / contentSize.height);
    
    this->addChild(sprite);
    
    return true;
}

