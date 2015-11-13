//
//  UserActionsController.cpp
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#include "UserActionsController.h"

// разруливает нажатие клавиш и кладет в контролс компонент
UserActionsController::UserActionsController(EventDispatcher* evd, Layer* _this, ControlsComponent* controls) {    
    auto eventListener = EventListenerKeyboard::create();
    
    eventListener->onKeyPressed = [controls](EventKeyboard::KeyCode keyCode, Event* event){
        controls->keys[keyCode] = true;
    };
    eventListener->onKeyReleased = [controls](EventKeyboard::KeyCode keyCode, Event* event) {
        controls->keys[keyCode] = false;
    };
    
    evd->addEventListenerWithSceneGraphPriority(eventListener, _this);
    
};

void UserActionsController::tick(Entity* entity, float delta) {
    if (EntityManager::entityHasComponent(entity, CONTROLS_COMPONENT)) {
        ControlsComponent* control = static_cast<ControlsComponent* >(EntityManager::getComponentByTypeFromEntity(entity, CONTROLS_COMPONENT));
        ActiveCollisionComponent* collision = static_cast<ActiveCollisionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, ACTIVE_COLLISION_COMPONENT));
        MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
        JumpingComponent* jumping = static_cast<JumpingComponent* >(EntityManager::getComponentByTypeFromEntity(entity, JUMPING_COMPONENT));
        DndComponent* dnd = static_cast<DndComponent* >(EntityManager::getComponentByTypeFromEntity(entity, DND_COMPONENT));
        
        bool isInputLeft = control->keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_A];
        bool isInputRight = control->keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_D];
        bool isInputUp = control->keys[EventKeyboard::KeyCode::KEY_UP_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_W];
        bool isInputZ = control->keys[EventKeyboard::KeyCode::KEY_Z];
        
        if (isInputLeft && !collision->collision[COL_LEFT]) {
            motion->dx = -motion->controlVelosity;
        }
        
        if (isInputRight && !collision->collision[COL_RIGHT]) {
            motion->dx = motion->controlVelosity;
        }
        
        if (isInputUp) {
            jumping->getCurrentState()->handleEvent(entity, jumping, INPUT_UP);
        }
        
        if (isInputZ && !dnd->buttonPressed) {
            dnd->getCurrentState()->handleEvent(entity, dnd, INPUT_Z);
            dnd->buttonPressed = true;
        }
        if (!isInputZ && dnd->buttonPressed) {
            dnd->buttonPressed = false;
        }
    }
}
