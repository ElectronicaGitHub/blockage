//
//  DndController.h
//  cppTests
//
//  Created by Philip Antonov on 20.10.15.
//
//

#ifndef __cppTests__DndController__
#define __cppTests__DndController__

#include <stdio.h>
#include "EntityManager.h"
#include "ControlsComponent.h"
#include "DragComponent.h"
#include "DndComponent.h"
#include "PositionComponent.h"
#include "RenderComponent.h"
#include "MotionComponent.h"
#include "GravityComponent.h"
#include "ActiveCollisionComponent.h"
#include "PassiveCollisionComponent.h"
#include "DropComponent.h"

class DndController {
public:
    bool buttonReleased = true;
    DndController() {};
    ~DndController() {};
    void tick(Entity* entity);
};

#endif /* defined(__cppTests__DndController__) */
