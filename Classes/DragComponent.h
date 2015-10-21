//
//  DragComponent.h
//  cppTests
//
//  Created by Philip Antonov on 20.10.15.
//
//

#ifndef __cppTests__DragComponent__
#define __cppTests__DragComponent__

#include <stdio.h>
#include "MainComponent.h"
#include "DropComponent.h"

class DropComponent;

class DragComponent : public MainComponent {
public:
    ComponentType type = DRAG_COMPONENT;
    bool dragged = false;
    Entity* draggedBy;
    Entity* droppedTo;
    DropComponent* droppedToComponent;
    
    DragComponent()
    : MainComponent(DRAG_COMPONENT)
    {}
    ~DragComponent() {}
};

#endif /* defined(__cppTests__DragComponent__) */
