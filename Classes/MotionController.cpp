//
//  MotionController.cpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#include "MotionController.h"

void MotionController::tick(Entity* entity, float delta) {
    if (EntityManager::entityHasComponent(entity, MOTION_COMPONENT)) {
        PositionComponent* position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
        MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
        
        if (EntityManager::entityHasComponent(entity, GRAVITY_COMPONENT)) {
            GravityComponent* gravity = static_cast<GravityComponent* >(EntityManager::getComponentByTypeFromEntity(entity, GRAVITY_COMPONENT));
            
            ActiveCollisionComponent* collision = static_cast<ActiveCollisionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, ACTIVE_COLLISION_COMPONENT));
            if (collision->collision[COL_BOTTOM]) {
                if (gravity->downfall < 0) {
                    entity->deleted = true;
                }
                
                if (motion->dy < 0) {
                    motion->dy *= -gravity->downfall;
                }
                motion->dx = motion->dx / gravity->friction;
            }
            else {
                if (collision->collision[COL_TOP]) {
                    if (motion->dy > 0) {
                        motion->dy = 0;
                    }
                }
                motion->dy -= gravity->gravity * delta;
            };
        }
    
        position->x += motion->dx * delta;
        position->orientation = (motion->dx >= 0) ? 1 : -1;
        
        position->y = position->y + motion->dy * delta;
    }
}