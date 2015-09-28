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
//            switch(keyCode){
//                case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
//                case EventKeyboard::KeyCode::KEY_A:
//                    component->keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] = true;
//                    component->keys[EventKeyboard::KeyCode::KEY_A] = true;
//                    break;
//                case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
//                case EventKeyboard::KeyCode::KEY_D:
//                    component->keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] = true;
//                    component->keys[EventKeyboard::KeyCode::KEY_D] = true;
//                    break;
//                case EventKeyboard::KeyCode::KEY_UP_ARROW:
//                case EventKeyboard::KeyCode::KEY_W:
//                    component->keys[EventKeyboard::KeyCode::KEY_UP_ARROW] = true;
//                    component->keys[EventKeyboard::KeyCode::KEY_W] = true;
//                    break;
//                case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
//                case EventKeyboard::KeyCode::KEY_S:
//                    component->keys[EventKeyboard::KeyCode::KEY_DOWN_ARROW] = true;
//                    component->keys[EventKeyboard::KeyCode::KEY_S] = true;
//                    break;
//            }
        };
        eventListener->onKeyReleased = [component](EventKeyboard::KeyCode keyCode, Event* event) {
            component->keys[keyCode] = false;
        };
        
        evd->addEventListenerWithSceneGraphPriority(eventListener, _this);

    };
    ~UserActionsController() {};
};

#endif /* defined(__cppTests__UserActionsController__) */
