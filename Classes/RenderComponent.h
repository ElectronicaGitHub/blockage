//
//  RenderComponent.h
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#ifndef __cppTests__RenderComponent__
#define __cppTests__RenderComponent__

#include <stdio.h>
#include <sstream>
#include <iomanip>
#include "cocos2d.h"
#include "MainComponent.h"
#include "ImageStorage.h"
#include "AnimationContainer.h"

using namespace cocos2d;

class RenderComponent : public MainComponent {
public:
    cocos2d::Sprite* sprite;
    cocos2d::Layer* layer;
    
    ComponentType type = RENDER_COMPONENT;
    RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size);
    RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size, pair<float,float>texture_size);
    ~RenderComponent() {
        layer->removeChild(sprite);
    };
    
    void animate(AnimationContainer* animation, float delta);
};

#endif /* defined(__cppTests__RenderComponent__) */
