//
//  RangedAttackController.cpp
//  cppTests
//
//  Created by shum on 06.10.15.
//
//

#include "RangedAttackController.h"

void RangedAttackController::tick(Entity* entity, cocos2d::Layer* layer, float delta) {
    if (EntityManager::entityHasComponent(entity, RANGED_ATTACK_COMPONENT)) {
        RangedAttackComponent* attack = static_cast<RangedAttackComponent* >(EntityManager::getComponentByTypeFromEntity(entity, RANGED_ATTACK_COMPONENT));
        
        if (EntityManager::entityHasComponent(entity, CONTROLS_COMPONENT)) {
            ControlsComponent* control = static_cast<ControlsComponent* >(EntityManager::getComponentByTypeFromEntity(entity, CONTROLS_COMPONENT));
            PositionComponent* position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
            MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
            bool fire = control->keys[EventKeyboard::KeyCode::KEY_SPACE];
            
            if (fire && attack->cooldownCounter == attack->cooldown) {
                Entity* stone = new StoneEntity();
                EntityManager::addEntity(stone);
                
                EntityManager::addComponentsToEntity(stone, {
                    new MotionComponent(250 * position->orientation + motion->dx, 250),
                    new PositionComponent(position->x, position->y, 1),
                    new RenderComponent(layer, IMAGE_STONE, pair<float, float>(7, 7)),
                    new ActiveCollisionComponent("player", {"player", "block"})
                });
                
                cout << EntityManager::entities.size() << endl;
                
                attack->cooldownCounter = 0;
            }
        }
        
        if (attack->cooldownCounter < attack->cooldown) {
            attack->cooldownCounter++;
        }
    }
}