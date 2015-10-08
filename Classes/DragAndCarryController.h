//
//  DragAndCarryController.h
//  cppTests
//
//  Created by Philip Antonov on 08.10.15.
//
//

#ifndef __cppTests__DragAndCarryController__
#define __cppTests__DragAndCarryController__

#include <stdio.h>
#include "EntityManager.h"
#include "ControlsComponent.h"
#include "DraggableComponent.h"
#include "DragAndCarryComponent.h"
#include "PositionComponent.h"
#include "RenderComponent.h"
#include "MotionComponent.h"
#include "GravityComponent.h"
#include "ActiveCollisionComponent.h"
#include "PassiveCollisionComponent.h"

class DragAndCarryController {
public:
    DragAndCarryController() {};
    ~DragAndCarryController() {};
    void tick(EntityManager* entityManager);
};

#endif /* defined(__cppTests__DragAndCarryController__) */
