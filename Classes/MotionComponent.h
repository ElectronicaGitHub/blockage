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
    float dx, dy, density, controlVelosity;
    
    string type = "MotionComponent";
    MotionComponent(float _dx, float _dy, float _density, float _controlVelosity) : MainComponent("MotionComponent") {
        density = _density;
        dx = _dx;
        dy = _dy;
        controlVelosity = _controlVelosity;
    };
    MotionComponent(float _dx, float _dy, float _density) : MainComponent("MotionComponent") {
        density = _density;
        dx = _dx;
        dy = _dy;
    };
    ~MotionComponent() {};
};

#endif /* MotionComponent_hpp */
