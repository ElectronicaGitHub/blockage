//
//  LifecycleController.h
//  cppTests
//
//  Created by shum on 06.12.15.
//
//

#ifndef __cppTests__LifecycleController__
#define __cppTests__LifecycleController__

#include <stdio.h>
#include "EntityManager.h"
#include "LifecycleComponent.h"
#include "SkillReleaseComponent.h"

using namespace std;

class LifecycleController {
public:
    LifecycleController() {};
    ~LifecycleController() {};
    
    void tick(Entity* entity, float delta);
};

#endif /* defined(__cppTests__LifecycleController__) */
