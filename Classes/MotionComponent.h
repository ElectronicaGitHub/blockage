//
//  MotionComponent.hpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#ifndef MotionComponent_hpp
#define MotionComponent_hpp

#include <stdio.h>
#include "MainComponent.h"

class MotionComponent : public MainComponent
{
public:
    float dx;
    float dy;
    float density;
    string type = "MotionComponent";
    MotionComponent() : MainComponent("MotionComponent") {
        density = 100;
        dx = 0;
        dy = 0;
    };
    ~MotionComponent() {};
};

#endif /* MotionComponent_hpp */
