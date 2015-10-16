//
//  UserActionsController.cpp
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#include "UserActionsController.h"

// разруливает нажатие клавиш и кладет в контролс компонент
UserActionsController::UserActionsController(EventDispatcher* evd, Layer* _this) {
    vector<MainComponent*> components = EntityManager::getComponentsByType(CONTROLS_COMPONENT);
    ControlsComponent* component = (ControlsComponent*)components[0];
    
    auto eventListener = EventListenerKeyboard::create();
    
    eventListener->onKeyPressed = [component](EventKeyboard::KeyCode keyCode, Event* event){
        component->keys[keyCode] = true;
    };
    eventListener->onKeyReleased = [component](EventKeyboard::KeyCode keyCode, Event* event) {
        component->keys[keyCode] = false;
    };
    
    evd->addEventListenerWithSceneGraphPriority(eventListener, _this);
    
};

void UserActionsController::tick(float delta) {
    vector<Entity*> entities = EntityManager::getAllEntitiesByComponentType(CONTROLS_COMPONENT);
    
    for (int i = 0; i < entities.size(); ++i) {
        Entity* entity = entities[i];
        ControlsComponent* control = static_cast<ControlsComponent* >(EntityManager::getComponentByTypeFromEntity(entity, CONTROLS_COMPONENT));
        ActiveCollisionComponent* collision = static_cast<ActiveCollisionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, ACTIVE_COLLISION_COMPONENT));
        MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
        JumpingComponent* jumping = static_cast<JumpingComponent* >(EntityManager::getComponentByTypeFromEntity(entity, JUMPING_COMPONENT));
        
        bool isInputLeft = control->keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_A];
        bool isInputRight = control->keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_D];
        bool isInputUp = control->keys[EventKeyboard::KeyCode::KEY_UP_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_W];
        
        if (isInputLeft && !collision->collision[COL_LEFT]) {
            motion->dx = -motion->controlVelosity;
        }
        
        if (isInputRight && !collision->collision[COL_RIGHT]) {
            motion->dx = motion->controlVelosity;
        }
        
        if (isInputUp) {
            jumping->getCurrentState()->handleEvent(entity, jumping, INPUT_UP);
        }
    }
}
