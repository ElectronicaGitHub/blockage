//
//  AnimationComponent.cpp
//  cppTests
//
//  Created by shum on 01.11.15.
//
//

#include "AnimationComponent.h"

AnimationContainer* AnimationComponent::getAnimation(vector<StateType> states) {
    return animationMap.find(states)->second;
};
