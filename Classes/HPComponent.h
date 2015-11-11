//
//  HPComponent.h
//  cppTests
//
//  Created by shum on 11.11.15.
//
//

#ifndef __cppTests__HPComponent__
#define __cppTests__HPComponent__

#include <stdio.h>
#include "MainComponent.h"

class HPComponent : public MainComponent
{
public:
    int value;
    cocos2d::Label* label = NULL;
    ComponentType type = HP_COMPONENT;
    HPComponent(int _value)
    : MainComponent(HP_COMPONENT)
    , value(_value)
    {}
    ~HPComponent() {}
};

#endif /* defined(__cppTests__HPComponent__) */
