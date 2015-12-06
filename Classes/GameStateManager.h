//
//  GameStateManager.h
//  cppTests
//
//  Created by shum on 17.10.15.
//
//

#ifndef __cppTests__GameStateManager__
#define __cppTests__GameStateManager__

#include "cocos2d.h"
#include "PlayingScene.h"

class GameStateManager
{
public:
    static void runGame(void);
    static cocos2d::Layer* getAnimateLayer(void);
    
private:
    static cocos2d::Scene* currentScene;
    static cocos2d::Layer* bg_layer;
    static cocos2d::Layer* animate_layer;
    static cocos2d::Layer* info_layer;
    
    static cocos2d::Director* director;
};

#endif /* defined(__cppTests__GameStateManager__) */
