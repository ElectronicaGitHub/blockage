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
    
    int mapSizeX = MapStorage::mapSizeX;
    int mapSizeY = MapStorage::mapSizeY;
    
    float fullsizeWidth = visibleSize.width;
    float fullsizeHeight = visibleSize.height;
    
    pair<float, float> tileSize = { fullsizeWidth/mapSizeX, fullsizeHeight/mapSizeY };
    
    cout << "fullsizeWidth: " << fullsizeWidth << " and fullsizeHeight: " << fullsizeHeight << endl;
    cout << "mapSizeX: " << mapSizeX << " and mapSizeY: " << mapSizeY << endl;
    
    vector<array<int, 4>> brick_vector = MapStorage::map.find(BRICK_ENTITY)->second;
    float x,y,w,h;
    for (int i = 0; i < brick_vector.size(); i++) {
        string id = "brick" + to_string(i) + "";
        Entity* entity = new BrickEntity();
        EntityManager::addPassiveEntity(entity);
        
        x = tileSize.first * brick_vector[i][0] + origin.x;
        y = tileSize.second * brick_vector[i][1] + origin.y;
        w = tileSize.first * brick_vector[i][2];
        h = tileSize.second * brick_vector[i][3];
        
        RenderComponent* render = new RenderComponent(this, IMAGE_WALL, {w, h}, tileSize);
        PositionComponent* position = new PositionComponent(x, y, 1);
        render->sprite->setPosition(position->x, position->y);
        
        EntityManager::addComponentsToEntity(entity, {
            render, position,
            new PassiveCollisionComponent
        });
    }
    
    brick_vector = MapStorage::map.find(DROP_BRICK_ENTITY)->second;
    for (int i = 0; i < brick_vector.size(); i++) {
        string id = "drop_brick" + to_string(i) + "";
        Entity* entity = new BrickEntity();
        EntityManager::addPassiveEntity(entity);
        
        x = tileSize.first * brick_vector[i][0] + origin.x;
        y = tileSize.second * brick_vector[i][1] + origin.y;
        w = tileSize.first * brick_vector[i][2];
        h = tileSize.second * brick_vector[i][3];
        
        RenderComponent* render = new RenderComponent(this, IMAGE_WALL_DROP, {w, h}, tileSize);
        PositionComponent* position = new PositionComponent(x, y, 1);
        render->sprite->setPosition(position->x, position->y);
        
        EntityManager::addComponentsToEntity(entity, {
            render, position,
            new DropComponent
        });
        
    }
    
    Entity* player = new PlayerEntity();
    EntityManager::addEntity(player);
    EntityManager::addComponentsToEntity(player, {
        new RenderComponent(this, IMAGE_DWARF, pair<float, float>(14, 18), "stay"),
        new DndComponent()
    });
    ControlsComponent* player_controls_component = static_cast<ControlsComponent*>(EntityManager::getComponentByTypeFromEntity(player, CONTROLS_COMPONENT));
    
//    Entity* drop_block = new BrickEntity();
//    EntityManager::addComponentsToEntity(drop_block, {
//        new DragComponent(),
//        new PassiveCollisionComponent(),
//        new PositionComponent(100, 120, 1),
//        new RenderComponent(this, IMAGE_WALL_DRAG, tileSize)
//    });
    
//    EntityManager::addEntity(drop_block);
    
    userActionsController = new UserActionsController(_eventDispatcher, this, player_controls_component);
    motionController = new MotionController();
    rangedAttackController = new RangedAttackController();
    renderController = new RenderController();
    collisionController = new CollisionController();
    dndController = new DndController();
    
    this->scheduleUpdate();

    return true;
}

void PlayingAnimateLayer::update(float delta) {
    for (int i = 0 ; i != EntityManager::entities.size(); ++i) {
        Entity* entity = EntityManager::entities[i];
        
        userActionsController->tick(entity, delta);
        motionController->tick(entity, delta);
        rangedAttackController->tick(entity, this, delta);
        renderController->tick(entity, delta);
        collisionController->tick(entity);
        dndController->tick(entity);
        
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

