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

using namespace cocos2d;

class RenderComponent : public MainComponent {
public:
    cocos2d::Sprite* sprite;
    cocos2d::PhysicsBody* spriteBody;
    map<string, bool> states;
    string type = "RenderComponent";
    pair<int, int> coords;
    RenderComponent(cocos2d::Layer* _this, string sprite_name, pair<float, float> _coords, pair<float, float> size, string entity_type) : MainComponent("RenderComponent") {
        
        coords = _coords;
        
        // инициализация
        
        sprite = Sprite::create(sprite_name);
        sprite = Sprite::create(sprite_name);
        sprite->setPosition(coords.first, coords.second);
        sprite->setAnchorPoint(Vec2(0.5, 0.5));
        
        // подстройка под указанный размер
        
        Size contentSize = sprite->getContentSize();
        float scale = size.first / contentSize.width;
        sprite->setScale(scale);
        
        // физическая модель
        
        spriteBody = PhysicsBody::createBox(sprite->getContentSize() * scale, cocos2d::PhysicsMaterial(0, 0.5, 0));
        sprite->setPhysicsBody(spriteBody);
        
        spriteBody->setVelocityLimit(300);
    
        if (entity_type != "sprite") {
            spriteBody->setDynamic(false);
        }
        
        _this->addChild(sprite, 0);
    };
    ~RenderComponent() {};
};

#endif /* defined(__cppTests__RenderComponent__) */
