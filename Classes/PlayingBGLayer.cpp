//
//  PlayingBGLayer.cpp
//  cppTests
//
//  Created by shum on 12.11.15.
//
//

#include "PlayingBGLayer.h"

bool PlayingBGLayer::init() {
    if ( !Layer::init() ) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    cocos2d::Sprite* sprite = cocos2d::Sprite::create(ImageStorage::getImage(IMAGE_BACKGROUND));
    sprite->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    sprite->setScale(0.5);
    
    Size contentSize = sprite->getContentSize();
    sprite->setScaleX(visibleSize.width / contentSize.width);
    sprite->setScaleY(visibleSize.height / contentSize.height);
    
    this->addChild(sprite);
    
    return true;
}