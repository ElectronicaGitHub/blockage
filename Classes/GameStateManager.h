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
    static cocos2d::Scene* currentScene;
    static cocos2d::Director* director;
    
    static void runGame(void);
};

#endif /* defined(__cppTests__GameStateManager__) */
