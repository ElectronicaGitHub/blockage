//
//  GameStateManager.cpp
//  cppTests
//
//  Created by shum on 17.10.15.
//
//

#include "GameStateManager.h"

cocos2d::Scene* GameStateManager::currentScene;
cocos2d::Layer* GameStateManager::bg_layer;
cocos2d::Layer* GameStateManager::animate_layer;
cocos2d::Layer* GameStateManager::info_layer;

cocos2d::Director* GameStateManager::director = cocos2d::Director::getInstance();

void GameStateManager::runGame() {
    currentScene = cocos2d::Scene::create();
    
    bg_layer = PlayingBGLayer::create();
    animate_layer = PlayingAnimateLayer::create();
    info_layer = PlayingInfoLayer::create();
    
    currentScene->addChild(bg_layer);
    currentScene->addChild(animate_layer);
    currentScene->addChild(info_layer);
    
    director->runWithScene(currentScene);
}

cocos2d::Layer* GameStateManager::getAnimateLayer() {
    return animate_layer;
}