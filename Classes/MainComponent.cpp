//
//  MainComponent.cpp
//  cppTests
//
//  Created by shum on 10.10.15.
//
//

#include <stdio.h>
#include "MainComponent.h"
#include "iostream"

MainComponent::~MainComponent() {
}

State* MainComponent::getCurrentState() {
    return currentState;
}

void MainComponent::switchState(StateType state_type, State* state, Entity* entity) {
    currentState->onExit(entity, this);
    currentState = state;
    currentStateType = state_type;
    currentState->onEnter(entity, this);
}


