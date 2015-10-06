//
//  PassiveCollisionComponent.h
//  cppTests
//
//  Created by Philip Antonov on 06.10.15.
//
//

#ifndef __cppTests__PassiveCollisionComponent__
#define __cppTests__PassiveCollisionComponent__

#include <stdio.h>
#include "MainComponent.h"

class PassiveCollisionComponent : public MainComponent {
public:
    string type = "PassiveCollisionComponent";
    PassiveCollisionComponent() : MainComponent("PassiveCollisionComponent") {};
    ~PassiveCollisionComponent() {};
};

#endif /* defined(__cppTests__PassiveCollisionComponent__) */
