//
//  JumpingComponent.hpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#ifndef JumpingComponent_hpp
#define JumpingComponent_hpp

#include <stdio.h>
#include "MainComponent.h"

class JumpingComponent : public MainComponent
{
public:
    float jumpA;
    bool isJump;
    string type = "JumpingComponent";
    JumpingComponent() : MainComponent("JumpingComponent") {
        jumpA = 250;
        isJump = false;
    };
    ~JumpingComponent() {};
};

#endif /* JumpingComponent_hpp */
