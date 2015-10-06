//
//  RenderController.h
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#ifndef __cppTests__RenderController__
#define __cppTests__RenderController__

#include <stdio.h>
#include "EntityManager.h"
#include "RenderComponent.h"
#include "PositionComponent.h"

class RenderController {
public:
    RenderController() {};
    ~RenderController() {};
    
    void tick(EntityManager* entityManager, float delta);
};

#endif /* defined(__cppTests__RenderController__) */
