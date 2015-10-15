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
    float gravity, friction;
    ComponentType type = GRAVITY_COMPONENT;
    GravityComponent()
        : MainComponent(GRAVITY_COMPONENT)
        , gravity(800)
        , friction(1.4f)
    {}
    ~GravityComponent() {}
};

#endif /* GravityComponent_hpp */
