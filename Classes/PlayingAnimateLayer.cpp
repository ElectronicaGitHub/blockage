//
//  PlayingAnimateLayer.cpp
//  cppTests
//
//  Created by shum on 12.11.15.
//
//

#include "PlayingAnimateLayer.h"

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
        new RenderComponent(this, IMAGE_DWARF, pair<float, float>(11, 16)),
        new DndComponent(),
        new LifecycleComponent(RANGE_APPRENTICE),
    });
    ControlsComponent* player_controls_component = static_cast<ControlsComponent*>(EntityManager::getComponentByTypeFromEntity(player, CONTROLS_COMPONENT));
    SkillReleaseComponent* skill_release = static_cast<SkillReleaseComponent*>(EntityManager::getComponentByTypeFromEntity(player, SKILL_RELEASE_COMPONENT));
    skill_release->setSkill(INPUT_Z, new RangedAttackLv1Skill());
    
    
    Entity* drop_block = new BrickEntity();
    EntityManager::addComponentsToEntity(drop_block, {
        new DragComponent(),
        new PassiveCollisionComponent(),
        new PositionComponent(100, 120, 1),
        new RenderComponent(this, IMAGE_WALL_DRAG, tileSize)
    });
    
//        EntityManager::addEntity(drop_block);
    
    userActionsController = new UserActionsController(_eventDispatcher, this, player_controls_component);
    motionController = new MotionController();
    renderController = new RenderController();
    collisionController = new CollisionController();
    dndController = new DndController();
    lifecycleController = new LifecycleController();
    
    this->scheduleUpdate();
    
    return true;
}

void PlayingAnimateLayer::update(float delta) {
    for (int i = 0 ; i != EntityManager::entities.size(); ++i) {
        Entity* entity = EntityManager::entities[i];
        
        userActionsController->tick(entity, delta);
        motionController->tick(entity, delta);
        renderController->tick(entity, delta);
        collisionController->tick(entity);
        dndController->tick(entity);
        lifecycleController->tick(entity, delta);
        
        if (entity->deleted) {
            EntityManager::removeEntity(entity);
            i--;
        }
    }
}
