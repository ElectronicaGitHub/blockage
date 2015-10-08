//
//  DragAndCarryComponent.h
//  cppTests
//
//  Created by Philip Antonov on 08.10.15.
//
//

#ifndef __cppTests__DragAndCarryComponent__
#define __cppTests__DragAndCarryComponent__

#include <stdio.h>
#include "MainComponent.h"
#include "Entity.h"

class DragAndCarryComponent : public MainComponent {
public:
    
    // Доступные состояния
    // *********************************
    // *  empty - не несет блок, пуст  *
    // *  dragging - несет блок        *
    // *  releasing - кидает блок      *
    // *********************************
    
    string state = "empty";
    bool buttonPressed = false;
    Entity* draggingEntity;
    string type = "DragAndCarryComponent";
    DragAndCarryComponent() : MainComponent("DragAndCarryComponent") {};
    ~DragAndCarryComponent() {};
};

#endif /* defined(__cppTests__DragAndCarryComponent__) */
