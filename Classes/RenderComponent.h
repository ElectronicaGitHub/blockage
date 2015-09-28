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
#include "cocos2d.h"
#include "MainComponent.h"

class RenderComponent : public MainComponent {
public:
    cocos2d::Sprite* sprite;
    string type = "RenderComponent";
    pair<int, int> coords;
    RenderComponent(cocos2d::Layer* _this, string sprite_name, pair<float, float> _coords) : MainComponent("RenderComponent") {
        
        coords = _coords;
        
        sprite = cocos2d::Sprite::create(sprite_name);
        sprite->setPosition(coords.first, coords.second);
        
        _this->addChild(sprite, 0);
    };
    ~RenderComponent() {};
};

#endif /* defined(__cppTests__RenderComponent__) */
