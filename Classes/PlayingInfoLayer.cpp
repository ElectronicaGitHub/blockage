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
    vector<Entity*> entities = EntityManager::getAllEntitiesByComponentType(LIFECYCLE_COMPONENT);
    for (int i = 0 ; i != entities.size(); ++i) {
        Entity* entity = entities[i];
        LifecycleComponent* lifecycle = static_cast<LifecycleComponent* >(EntityManager::getComponentByTypeFromEntity(entity, LIFECYCLE_COMPONENT));
        PositionComponent* position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
        string label_str = to_string(lifecycle->hp) + "/" + to_string(lifecycle->getFullHPValue());
        
        if (!lifecycle->hp_label) {
            lifecycle->hp_label = Label::createWithTTF(label_str, "fonts/arial.ttf", 7);
            lifecycle->hp_label->setColor(Color3B(250, 0, 0));
            this->addChild(lifecycle->hp_label);
        }
        
        lifecycle->hp_label->setPosition(Point(position->x + 9, position->y + 10));
        lifecycle->hp_label->setString(label_str);
    }
}
