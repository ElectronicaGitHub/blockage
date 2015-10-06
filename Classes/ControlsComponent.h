//
//  ControlsComponent.h
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#ifndef __cppTests__ControlsComponent__
#define __cppTests__ControlsComponent__

#include <stdio.h>
#include "MainComponent.h"
#include "iostream"
#include "map"

using namespace cocos2d;
using namespace std;

class ControlsComponent : public MainComponent {
public:
    // тут хранятся все данные о перемещениях игроков EventKeyboard::KeyCode
    map<EventKeyboard::KeyCode, bool> keys = {
        {EventKeyboard::KeyCode::KEY_LEFT_ARROW, false },
        {EventKeyboard::KeyCode::KEY_A, false },
        {EventKeyboard::KeyCode::KEY_RIGHT_ARROW, false },
        {EventKeyboard::KeyCode::KEY_D, false },
        {EventKeyboard::KeyCode::KEY_UP_ARROW, false },
        {EventKeyboard::KeyCode::KEY_W, false },
        {EventKeyboard::KeyCode::KEY_DOWN_ARROW, false },
        {EventKeyboard::KeyCode::KEY_S, false },
        {EventKeyboard::KeyCode::KEY_SPACE, false }
    };
    
    string type = "ControlsComponent";
    ControlsComponent() : MainComponent("ControlsComponent") {};
    ~ControlsComponent() {};
};

#endif /* defined(__cppTests__ControlsComponent__) */
