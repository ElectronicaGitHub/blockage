//
//  DropComponent.h
//  cppTests
//
//  Created by Philip Antonov on 13.10.15.
//
//

#ifndef __cppTests__DropComponent__
#define __cppTests__DropComponent__

#include <stdio.h>
#include "MainComponent.h"
#include "Entity.h"

class DropComponent : public MainComponent {
public:
    string type = "DropComponent";
    bool filled = false;
    Entity* fillEmenent;
    
    DropComponent() : MainComponent("DropComponent") {};
    ~DropComponent() {};
};

#endif /* defined(__cppTests__DropComponent__) */
