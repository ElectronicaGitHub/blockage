//
//  UserActionsController.h
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#ifndef __cppTests__UserActionsController__
#define __cppTests__UserActionsController__

#include <stdio.h>
#include "iostream"
#include "ControlsComponent.h"
#include "EntityManager.h"

using namespace cocos2d;
using namespace std;

class UserActionsController {
public:
    // разруливает нажатие клавиш и кладет в контролс компонент
    UserActionsController(EventDispatcher* evd, Layer* _this) {
        cout << "UserActionsController Initialized" << endl;
        
        EntityManager entityManager;
    
        vector<MainComponent*> rightComponents = entityManager.GetComponentsByType("ControlsComponent");
        ControlsComponent *component = (ControlsComponent*)rightComponents[0];
        
        auto eventListener = EventListenerKeyboard::create();
        
        eventListener->onKeyPressed = [component](EventKeyboard::KeyCode keyCode, Event* event){
            component->keys[keyCode] = true;
        };
        eventListener->onKeyReleased = [component](EventKeyboard::KeyCode keyCode, Event* event) {
            component->keys[keyCode] = false;
        };
        
        evd->addEventListenerWithSceneGraphPriority(eventListener, _this);

    };
    ~UserActionsController() {};
};

#endif /* defined(__cppTests__UserActionsController__) */
