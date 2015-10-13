//
//  DraggableComponent.h
//  cppTests
//
//  Created by Philip Antonov on 08.10.15.
//
//

#ifndef __cppTests__DraggableComponent__
#define __cppTests__DraggableComponent__

#include <stdio.h>
#include "DropComponent.h"

class DraggableComponent : public MainComponent {
public:
    string type = "DraggableComponent";
    bool dragged = false;
    Entity* draggedBy;
    Entity* droppedTo;
    DropComponent * droppedToComponent;
    DraggableComponent()
    : MainComponent("DraggableComponent")
    {}
    ~DraggableComponent() {}
};

#endif /* defined(__cppTests__DraggableComponent__) */
