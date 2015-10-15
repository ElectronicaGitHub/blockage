//
//  MainComponent.cpp
//  cppTests
//
//  Created by shum on 10.10.15.
//
//

#include <stdio.h>
#include "MainComponent.h"

State* MainComponent::getCurrentState() {
    return currentState;
}

void MainComponent::switchState(State* state, Entity* entity) {
    currentState->onExit(entity, this);
    currentState = state;
    currentState->onEnter(entity, this);
}


