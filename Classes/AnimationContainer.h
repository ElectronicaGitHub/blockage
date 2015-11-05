//
//  Animation.h
//  cppTests
//
//  Created by shum on 01.11.15.
//
//

#ifndef __cppTests__Animation__
#define __cppTests__Animation__

#include <stdio.h>
#include "ImageStorage.h"

using namespace cocos2d;

class AnimationContainer
{
public:
    int framesNumber, currentFrame;
    float frameSwitcher, frameTime;
    string frameName;
    
    AnimationContainer(ImageName plist, int _framesNumber, float _frameTime, string _frameName) {
        framesNumber = _framesNumber;
        frameTime = _frameTime;
        frameName = _frameName;
        currentFrame = 1;
        frameSwitcher = 100;
        
//        SpriteFrameCache* cache = SpriteFrameCache::getInstance();
//        cache->addSpriteFramesWithFile(ImageStorage::getImage(ANIMATION_DWARF_MOTION));
    }
    ~AnimationContainer(){}
};

#endif /* defined(__cppTests__Animation__) */
