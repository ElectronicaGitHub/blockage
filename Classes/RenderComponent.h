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
#include <iostream>
#include <sstream>
#include <iomanip>
#include "cocos2d.h"
#include "MainComponent.h"
#include "ImageStorage.h"

#include "spine/spine-cocos2dx.h"

using namespace cocos2d;
using namespace spine;

class RenderComponent : public MainComponent {
public:
    cocos2d::Sprite* sprite;
    spine::SkeletonAnimation* animatedSprite;
    cocos2d::Layer* layer;
    pair<float, float> tile_size;
    
    string currentAnimation;
    
    ComponentType type = RENDER_COMPONENT;
    RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size, string startAnimation);
    RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size, pair<float,float>texture_size);
    ~RenderComponent() {
        layer->removeChild(sprite);
    };
    
    void animate(string animation);
};

#endif /* defined(__cppTests__RenderComponent__) */
