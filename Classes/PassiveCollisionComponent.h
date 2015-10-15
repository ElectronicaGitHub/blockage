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
    ComponentType type = PASSIVE_COLLISION_COMPONENT;
    PassiveCollisionComponent() : MainComponent(PASSIVE_COLLISION_COMPONENT) {};
    ~PassiveCollisionComponent() {};
};

#endif /* defined(__cppTests__PassiveCollisionComponent__) */
