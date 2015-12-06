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
#include "CharClass.h"

class LifecycleComponent : public MainComponent
{
public:
    int hp, xp, level;
    CharClass* char_class;
    
    cocos2d::Label* hp_label = NULL;
    ComponentType type = LIFECYCLE_COMPONENT;
    LifecycleComponent(ClassName class_name)
    : MainComponent(LIFECYCLE_COMPONENT)
    , xp(0)
    , level(1)
    {
        char_class = new CharClass(class_name);
        hp = char_class->getFullHPValue(1);
    }
    ~LifecycleComponent(){}
    
    int getFullHPValue() {
        return char_class->getFullHPValue(level);
    }
};

#endif /* defined(__cppTests__HPComponent__) */
