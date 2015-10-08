//
//  MotionController.cpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#include "MotionController.h"

void MotionController::tick(EntityManager* entityManager, float delta) {
    vector<Entity*> entities = entityManager->getAllEntitiesByComponentTypes({"PositionComponent", "MotionComponent"});
    for (int i = 0; i < entities.size(); ++i) {
        Entity* entity = entities[i];
        PositionComponent* position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(entity, "PositionComponent"));
        MotionComponent* motion = static_cast<MotionComponent* >(entityManager->getComponentByTypeFromEntity(entity, "MotionComponent"));
        ActiveCollisionComponent* collision = static_cast<ActiveCollisionComponent* >(entityManager->getComponentByTypeFromEntity(entity, "ActiveCollisionComponent"));
        
        
        if (entityManager->entityHasComponent(entity, "GravityComponent")) {
            GravityComponent* gravity = static_cast<GravityComponent* >(entityManager->getComponentByTypeFromEntity(entity, "GravityComponent"));
            
            // выпилить этот костыль в стейт
            if (collision->collision["bottom"]) {
                motion->dy = 0;
            }
            else {
                motion->dy -= gravity->gravity * delta;
            }
            motion->dx -= gravity->friction * delta;
            motion->dx = motion->dx / gravity->friction;
        }
        
        if (entityManager->entityHasComponent(entity, "ControlsComponent")) {
            ControlsComponent* control = static_cast<ControlsComponent* >(entityManager->getComponentByTypeFromEntity(entity, "ControlsComponent"));
            
            bool moveLeft = control->keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_A];
            bool moveRight = control->keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_D];
            
            if (moveLeft && !collision->collision["left"]) {
                motion->dx = -motion->controlVelosity;
            }
            if (moveRight && !collision->collision["right"]) {
                motion->dx = motion->controlVelosity;
            }
            
            if (entityManager->entityHasComponent(entity, "JumpingComponent")) {
                JumpingComponent* jumping = static_cast<JumpingComponent* >(entityManager->getComponentByTypeFromEntity(entity, "JumpingComponent"));
                bool moveUp = control->keys[EventKeyboard::KeyCode::KEY_UP_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_W];
                
                if (moveUp && !jumping->isJump) {
                    motion->dy = jumping->velocity;
                    jumping->isJump = true;
                }
                
                // перенести в стейт
                if (collision->collision["bottom"]) {
                    jumping->isJump = false;
                }
            }
        }
    
        position->x += motion->dx * delta;
        position->orientation = (motion->dx >= 0) ? 1 : -1;
        
        position->y = position->y + motion->dy * delta;
    }
}