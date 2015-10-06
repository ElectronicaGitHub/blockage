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
        Entity* entity = entities[0];
        PositionComponent* position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(entity, "PositionComponent"));
        MotionComponent* motion = static_cast<MotionComponent* >(entityManager->getComponentByTypeFromEntity(entity, "MotionComponent"));
        ActiveCollisionComponent* collision = static_cast<ActiveCollisionComponent* >(entityManager->getComponentByTypeFromEntity(entity, "ActiveCollisionComponent"));
        
        
        if (entityManager->entityHasComponent(entity, "GravityComponent")) {
            GravityComponent* gravity = static_cast<GravityComponent* >(entityManager->getComponentByTypeFromEntity(entity, "GravityComponent"));
            
            if (collision->collision["bottom"]) {
                motion->dy = 0;
            } else {
                motion->dy -= gravity->g * delta;
            }
        }
        
        if (entityManager->entityHasComponent(entity, "ControlsComponent")) {
            ControlsComponent* control = static_cast<ControlsComponent* >(entityManager->getComponentByTypeFromEntity(entity, "ControlsComponent"));
            
            bool moveLeft = control->keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_A];
            bool moveRight = control->keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_D];
            
            if (moveLeft && !collision->collision["left"]) {
                motion->dx -= motion->density;
//                position->orientation = -1;
            }
            if (moveRight && !collision->collision["right"]) {
                motion->dx += motion->density;
//                position->orientation = 1;
            }
            
            if (entityManager->entityHasComponent(entity, "JumpingComponent")) {
                JumpingComponent* jumping = static_cast<JumpingComponent* >(entityManager->getComponentByTypeFromEntity(entity, "JumpingComponent"));
                bool moveUp = control->keys[EventKeyboard::KeyCode::KEY_UP_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_W];
                
                if (moveUp && !jumping->isJump) {
                    motion->dy = jumping->jumpA;
                    jumping->isJump = true;
                }
                
                if (collision->collision["bottom"]) {
                    jumping->isJump = false;
                }
//                if (collision->collision["top"]) {
//                    motion->dy = 0;
//                }
                
//                if (position->y < 110) {
//                    jumping->isJump = false;
//                }
            }
        }
    
        motion->dx = motion->dx / 1.4;
    
        position->x += motion->dx * delta;
        position->orientation = (motion->dx >= 0) ? 1 : -1;
        
        position->y = position->y + motion->dy * delta;
    }
}