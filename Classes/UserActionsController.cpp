//
//  UserActionsController.cpp
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#include "UserActionsController.h"

// разруливает нажатие клавиш и кладет в контролс компонент
UserActionsController::UserActionsController(EventDispatcher* evd, Layer* _this, EntityManager* entityManager) {
    cout << "UserActionsController Initialized" << endl;
    
    vector<MainComponent*> rightComponents = entityManager->getComponentsByType("ControlsComponent");
    ControlsComponent* component = (ControlsComponent*)rightComponents[0];
    
    auto eventListener = EventListenerKeyboard::create();
    
    eventListener->onKeyPressed = [component](EventKeyboard::KeyCode keyCode, Event* event){
        component->keys[keyCode] = true;
    };
    eventListener->onKeyReleased = [component](EventKeyboard::KeyCode keyCode, Event* event) {
        component->keys[keyCode] = false;
    };
    
    evd->addEventListenerWithSceneGraphPriority(eventListener, _this);
    
};
