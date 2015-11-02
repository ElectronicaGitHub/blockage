//
//  AnimationComponent.h
//  cppTests
//
//  Created by shum on 01.11.15.
//
//

#ifndef __cppTests__AnimationComponent__
#define __cppTests__AnimationComponent__

#include <stdio.h>
#include "cocos2d.h"
#include "MainComponent.h"
#include "AnimationContainer.h"
#include "ImageStorage.h"
#include "State.h"

using namespace cocos2d;
using namespace std;

class AnimationComponent : public MainComponent {
public:
    ComponentType type = ANIMATION_COMPONENT;
    AnimationComponent(map<vector<StateType>, AnimationContainer*> _animationMap)
    : MainComponent(ANIMATION_COMPONENT)
    , animationMap( _animationMap)
    {}
    ~AnimationComponent(){}
    
    AnimationContainer* getAnimation(vector<StateType> states);
private:
    map<vector<StateType>, AnimationContainer*> animationMap;
};

#endif /* defined(__cppTests__AnimationComponent__) */
