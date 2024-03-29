//
//  RenderComponent.cpp
//  cppTests
//
//  Created by shum on 30.10.15.
//
//

#include <stdio.h>
#include "RenderComponent.h"

RenderComponent::RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size) : MainComponent(RENDER_COMPONENT) {
    layer = _layer;
    tile_size = size;
    
    sprite = Sprite::create(ImageStorage::getImage(image));
    
    Size contentSize = sprite->getContentSize();
    sprite->setScaleX(size.first / contentSize.width);
    sprite->setScaleY(size.second / contentSize.height);
    
    layer->addChild(sprite);
    
    // Вот это здесь ЯХ быть не должно, но когда это пишешь в конструкторе контейнера анимации, вместо картинки черный квадрат. ХЗ че за хрень, надо разобраться
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile(ImageStorage::getImage(WARRIOR_STAY));
    cache->addSpriteFramesWithFile(ImageStorage::getImage(WARRIOR_RUN));
};

RenderComponent::RenderComponent(cocos2d::Layer* _layer, ImageName image, pair<float, float> size, pair<float,float>texture_size) : MainComponent(RENDER_COMPONENT) {
    layer = _layer;
    
    sprite = Sprite::create(ImageStorage::getImage(image));
    sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
    
    Size contentSize = sprite->getContentSize();
    
    sprite->getTexture()->setTexParameters({GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT});
    
    sprite->setTextureRect(cocos2d::Rect(0, 0, contentSize.width * (size.first / texture_size.first), contentSize.height * (size.second / texture_size.second)));
    
    contentSize = sprite->getContentSize();
    float scaleX = size.first / contentSize.width, scaleY = size.second / contentSize.height;
    sprite->setScaleX(scaleX);
    sprite->setScaleY(scaleY);
    
    layer->addChild(sprite);
};

void RenderComponent::animate(AnimationContainer* animation, float delta) {
    switchCurrentAnimation(animation);
    
    stringstream ss;
    ss << setw(2) << setfill('0') << animation->currentFrame;
    
    animation->frameSwitcher += delta;
    if (animation->frameSwitcher > animation->frameTime) {
        SpriteFrameCache* cache = SpriteFrameCache::getInstance();
        SpriteFrame* frame = cache->getSpriteFrameByName(animation->frameName + "_" + ss.str() + ".png");
        
        sprite->setSpriteFrame(frame);
        
        animation->currentFrame = (animation->currentFrame == animation->framesNumber) ? 1 : animation->currentFrame + 1;
        animation->frameSwitcher = 0;
    }
};

void RenderComponent::switchCurrentAnimation(AnimationContainer* animation) {
    if (animation != currentAnimation) {
        if (currentAnimation) {
            currentAnimation->currentFrame = 1;
            currentAnimation->frameSwitcher = 100;
        }
        currentAnimation = animation;
        
        SpriteFrameCache* cache = SpriteFrameCache::getInstance();
        SpriteFrame* frame = cache->getSpriteFrameByName(animation->frameName + "_01.png");
        
        Size contentSize = frame->getOriginalSize();
        sprite->setScaleX(tile_size.first / contentSize.width);
        sprite->setScaleY(tile_size.second / contentSize.height);
    }
}