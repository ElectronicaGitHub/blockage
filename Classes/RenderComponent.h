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
#include "ImageStorage.h"

using namespace cocos2d;

class RenderComponent : public MainComponent {
public:
    cocos2d::Sprite* sprite;
    cocos2d::Layer* layer;
    
    ComponentType type = RENDER_COMPONENT;
    RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size) : MainComponent(RENDER_COMPONENT) {
        layer = _layer;
        
        sprite = Sprite::create(ImageStorage::getImage(image));
        sprite->setAnchorPoint(Vec2(0.5, 0.5));
        
        // подстройка под указанный размер
        Size contentSize = sprite->getContentSize();
        sprite->setScaleX(size.first / contentSize.width);
        sprite->setScaleY(size.second / contentSize.width);
        
        layer->addChild(sprite);
    };
    ~RenderComponent() {
        layer->removeChild(sprite);
    };
};

#endif /* defined(__cppTests__RenderComponent__) */
