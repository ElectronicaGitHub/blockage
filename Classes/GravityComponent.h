//
//  GravityComponent.hpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#ifndef GravityComponent_hpp
#define GravityComponent_hpp

#include <stdio.h>
#include "MainComponent.h"

class GravityComponent : public MainComponent
{
public:
    float gravity, friction_ground, friction_air, downfall;
    ComponentType type = GRAVITY_COMPONENT;
    GravityComponent(float _friction_ground, float _friction_air, float _downfall)
        : MainComponent(GRAVITY_COMPONENT)
        , gravity(800)
        , friction_ground(_friction_ground)
        , friction_air(_friction_air)
        , downfall(_downfall)
    {}
    ~GravityComponent() {}
};

#endif /* GravityComponent_hpp */
