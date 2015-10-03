//
//  MovementComponent.h
//  cppTests
//
//  Created by Philip Antonov on 25.09.15.
//
//

#ifndef __cppTests__MovementComponent__
#define __cppTests__MovementComponent__

#include <stdio.h>
#include "MainComponent.h"
#include "map"

class MovementComponent : public MainComponent
{
public:
    // Тут хранятся настройки движения и прочего
    float velocityDx = 10;
    float velocityMax = 200;
    float velocityDensity = 5; // затухание ускорения
    string type = "MovementComponent";
    MovementComponent() : MainComponent("MovementComponent") {
    };
    ~MovementComponent() {};
};

#endif /* defined(__cppTests__MovementComponent__) */
