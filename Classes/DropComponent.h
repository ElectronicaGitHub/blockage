//
//  DropComponent.h
//  cppTests
//
//  Created by Philip Antonov on 20.10.15.
//
//

#ifndef __cppTests__DropComponent__
#define __cppTests__DropComponent__

#include <stdio.h>
#include "MainComponent.h"
#include "Entity.h"

class DropComponent : public MainComponent {
public:
    ComponentType type = DROP_COMPONENT;
    bool filled = false;
    Entity* fillEmenent;
    
    DropComponent() : MainComponent(DROP_COMPONENT) {};
    ~DropComponent() {};
};

#endif /* defined(__cppTests__DropComponent__) */
