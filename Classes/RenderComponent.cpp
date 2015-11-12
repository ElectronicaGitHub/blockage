//
//  RenderComponent.cpp
//  cppTests
//
//  Created by shum on 30.10.15.
//
//

#include <stdio.h>
#include "RenderComponent.h"

RenderComponent::RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size, string startAnimation) : MainComponent(RENDER_COMPONENT) {
    layer = _layer;
    tile_size = size;
    currentAnimation = startAnimation;
    
//    Size contentSize = sprite->getContentSize();
    
    animatedSprite = SkeletonAnimation::createWithFile("res/animations/warrior/skeleton.json", "res/animations/warrior/skeleton.atlas", 1);
    animatedSprite->setAnimation(0, currentAnimation, true);
    animatedSprite->setSkin("default");
//    animatedSprite->setDebugBonesEnabled(true);
//    animatedSprite->setDebugSlotsEnabled(true);
//    animatedSprite->setScale(0.2, 0.2);
//    animatedSprite->setContentSize({20, 20});
    
    spAttachment* a = animatedSprite->getAttachment("boundingbox", "global");
    spSlot* sl = animatedSprite->findSlot("global");
    
//    cout << sl->bone->skeleton->data->width << " :: " << sl->bone->skeleton->data->height << endl;
    
    
    animatedSprite->setScaleX(size.first / sl->bone->skeleton->data->width);
    animatedSprite->setScaleY(size.second / sl->bone->skeleton->data->height);
    
    layer->addChild(animatedSprite);
};

RenderComponent::RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size, pair<float,float>texture_size) : MainComponent(RENDER_COMPONENT) {
    layer = _layer;
    
    sprite = Sprite::create(ImageStorage::getImage(image));
    sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
    
    Size contentSize = sprite->getContentSize();
    
//    sprite->getTexture()->setTexParameters({GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT});
    
//    sprite->setTextureRect(cocos2d::Rect(0, 0, contentSize.width * (size.first / texture_size.first), contentSize.height * (size.second / texture_size.second)));
    
    contentSize = sprite->getContentSize();
    float scaleX = size.first / contentSize.width, scaleY = size.second / contentSize.height;
    sprite->setScaleX(scaleX);
    sprite->setScaleY(scaleY);
    
    layer->addChild(sprite);
};

void RenderComponent::animate(string animation) {
    
    if (animation != currentAnimation) {
        
        animatedSprite->setAnimation(0, animation, true);
        
        currentAnimation = animation;
    }

};
