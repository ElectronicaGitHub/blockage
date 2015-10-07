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
        
        if (entityManager->entityHasComponent(entity, "GravityComponent")) {
            GravityComponent* gravity = static_cast<GravityComponent* >(entityManager->getComponentByTypeFromEntity(entity, "GravityComponent"));
            
            motion->dy -= gravity->gravity * delta;
            if (position->y <= 100) {
                motion->dx = motion->dx / gravity->friction;
            }
        }
        
        if (entityManager->entityHasComponent(entity, "ControlsComponent")) {
            ControlsComponent* control = static_cast<ControlsComponent* >(entityManager->getComponentByTypeFromEntity(entity, "ControlsComponent"));
            
            bool moveLeft = control->keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_A];
            bool moveRight = control->keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_D];
            
            if (moveLeft) {
                motion->dx = -motion->controlVelosity;
//                position->orientation = -1;
            }
            if (moveRight) {
                motion->dx = motion->controlVelosity;
//                position->orientation = 1;
            }
            
            if (entityManager->entityHasComponent(entity, "JumpingComponent")) {
                JumpingComponent* jumping = static_cast<JumpingComponent* >(entityManager->getComponentByTypeFromEntity(entity, "JumpingComponent"));
                bool moveUp = control->keys[EventKeyboard::KeyCode::KEY_UP_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_W];
                
                if (moveUp && !jumping->isJump) {
                    motion->dy = jumping->jumpA;
                    jumping->isJump = true;
                }
                
                if (position->y <= 100) {
                    jumping->isJump = false;
                }
            }
        }
    
        position->x += motion->dx * delta;
        position->orientation = (motion->dx >= 0) ? 1 : -1;
        
        position->y = max(position->y + motion->dy * delta, 100.0f);

    }
}