//
//  MotionController.cpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#include "MotionController.h"

void MotionController::tick(float delta) {
    vector<Entity*> entities = EntityManager::getAllEntitiesByComponentTypes({POSITION_COMPONENT, MOTION_COMPONENT});
    for (int i = 0; i < entities.size(); ++i) {
        Entity* entity = entities[i];
        PositionComponent* position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
        MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
        
        if (EntityManager::entityHasComponent(entity, GRAVITY_COMPONENT)) {
            GravityComponent* gravity = static_cast<GravityComponent* >(EntityManager::getComponentByTypeFromEntity(entity, GRAVITY_COMPONENT));
            
            // выпилить этот костыль как-нибудь
            ActiveCollisionComponent* collision = static_cast<ActiveCollisionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, ACTIVE_COLLISION_COMPONENT));
            if (collision->collision[COL_BOTTOM]) {
                if (motion->dy < 0) {
                    motion->dy = 0;
                }
                motion->dx = motion->dx / gravity->friction;
                
                if (entity->id.find("stone") != std::string::npos) {
                    EntityManager::removeEntity(entity);
                }
            }
            else {
                motion->dy -= gravity->gravity * delta;
            };
        }
    
        position->x += motion->dx * delta;
        position->orientation = (motion->dx >= 0) ? 1 : -1;
        
        position->y = position->y + motion->dy * delta;
    }
}