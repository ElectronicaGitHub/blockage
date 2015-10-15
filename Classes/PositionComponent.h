//
//  PositionComponent.hpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#ifndef __cppTests__PositionComponent__
#define __cppTests__PositionComponent__

#include <stdio.h>
#include "MainComponent.h"

class PositionComponent : public MainComponent
{
public:
    float x;
    float y;
    int orientation;
    ComponentType type = POSITION_COMPONENT;
    PositionComponent(float _x, float _y, int _orientation)
        : MainComponent(POSITION_COMPONENT)
        , x(_x)
        , y(_y)
        , orientation(_orientation)
        {}
    ~PositionComponent() {}
};

#endif /* defined(__cppTests__PositionComponent__) */