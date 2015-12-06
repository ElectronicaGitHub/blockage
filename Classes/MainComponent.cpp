//
//  MainComponent.cpp
//  cppTests
//
//  Created by shum on 10.10.15.
//
//

#include <stdio.h>
#include "MainComponent.h"

MainComponent::~MainComponent() {
}

State* MainComponent::getCurrentState() {
    return currentState;
}

void MainComponent::switchState(State* state, Entity* entity) {
    currentState->onExit(entity, this);
    currentState = state;
    currentState->onEnter(entity, this);
}

void MainComponent::updateState(Entity* entity) {
    currentState->update(entity, this);
}
void MainComponent::updateState(Entity* entity, float delta) {
    currentState->update(entity, this, delta);
}


