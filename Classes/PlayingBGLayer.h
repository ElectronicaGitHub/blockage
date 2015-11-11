//
//  PlayingBGLayer.h
//  cppTests
//
//  Created by shum on 12.11.15.
//
//

#ifndef __cppTests__PlayingBGLayer__
#define __cppTests__PlayingBGLayer__

#include <stdio.h>
#include "cocos2d.h"

#include "ImageStorage.h"

using namespace std;
using namespace cocos2d;

class PlayingBGLayer : public cocos2d::Layer {
public:
    virtual bool init() override;
    
    CREATE_FUNC(PlayingBGLayer);
};

#endif /* defined(__cppTests__PlayingBGLayer__) */
