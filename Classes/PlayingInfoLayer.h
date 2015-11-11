//
//  PlayingInfoLayer.h
//  cppTests
//
//  Created by shum on 12.11.15.
//
//

#ifndef __cppTests__PlayingInfoLayer__
#define __cppTests__PlayingInfoLayer__

#include <stdio.h>
#include "cocos2d.h"

#include "ImageStorage.h"
#include "EntityManager.h"

using namespace std;
using namespace cocos2d;

class PlayingInfoLayer : public cocos2d::Layer {
public:
    virtual bool init() override;
    virtual void update(float delta) override;
    
    CREATE_FUNC(PlayingInfoLayer);
};

#endif /* defined(__cppTests__PlayingInfoLayer__) */
