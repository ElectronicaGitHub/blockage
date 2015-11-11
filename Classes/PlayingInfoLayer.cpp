//
//  PlayingInfoLayer.cpp
//  cppTests
//
//  Created by shum on 12.11.15.
//
//

#include "PlayingInfoLayer.h"

bool PlayingInfoLayer::init() {
    if ( !Layer::init() ) {
        return false;
    }
    
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->scheduleUpdate();
    return true;
}

void PlayingInfoLayer::update(float delta) {
    vector<Entity*> entities = EntityManager::getAllEntitiesByComponentType(HP_COMPONENT);
    for (int i = 0 ; i != entities.size(); ++i) {
        Entity* entity = entities[i];
        HPComponent* hp = static_cast<HPComponent* >(EntityManager::getComponentByTypeFromEntity(entity, HP_COMPONENT));
        PositionComponent* position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
        
        if (!hp->label) {
            hp->label = Label::createWithTTF(to_string(hp->value), "fonts/arial.ttf", 7);
            hp->label->setColor(Color3B(250, 0, 0));
            this->addChild(hp->label);
        }
        
        hp->label->setPosition(Point(position->x + 9, position->y + 10));
    }
}
