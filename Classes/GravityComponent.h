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
    float gravity, friction, downfall;
    ComponentType type = GRAVITY_COMPONENT;
    GravityComponent(float _downfall)
        : MainComponent(GRAVITY_COMPONENT)
        , gravity(800)
        , friction(1.2f)
        , downfall(_downfall)
    {}
    ~GravityComponent() {}
};

#endif /* GravityComponent_hpp */
