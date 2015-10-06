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
    float g;
    string type = "GravityComponent";
    GravityComponent() : MainComponent("GravityComponent") {
        g = 800;
    };
    ~GravityComponent() {};
};

#endif /* GravityComponent_hpp */
