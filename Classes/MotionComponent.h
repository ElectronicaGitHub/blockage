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
    
    ComponentType type = MOTION_COMPONENT;
    MotionComponent(float _controlVelosity)
        : MainComponent(MOTION_COMPONENT)
        , dx(0)
        , dy(0)
        , controlVelosity(_controlVelosity)
        {}
    MotionComponent(float _dx, float _dy)
        : MainComponent(MOTION_COMPONENT)
        , dx(_dx)
        , dy(_dy)
        {}
    ~MotionComponent() {}
};

#endif /* MotionComponent_hpp */
