//
//  GameStateManager.cpp
//  cppTests
//
//  Created by shum on 17.10.15.
//
//

#include "GameStateManager.h"

cocos2d::Scene* GameStateManager::currentScene;
cocos2d::Director* GameStateManager::director = cocos2d::Director::getInstance();

void GameStateManager::runGame() {
    currentScene = cocos2d::Scene::create();
    
    cocos2d::Layer* bg_layer = PlayingBGLayer::create();
    cocos2d::Layer* animate_layer = PlayingAnimateLayer::create();
    
    currentScene->addChild(bg_layer);
    currentScene->addChild(animate_layer);
    
    director->runWithScene(currentScene);
}