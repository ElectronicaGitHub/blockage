//
//  RangedAttackController.cpp
//  cppTests
//
//  Created by shum on 06.10.15.
//
//

#include "RangedAttackController.h"

void RangedAttackController::tick(EntityManager* entityManager, ImageStorage* imageStorage, float delta) {
    vector<Entity*> entities = entityManager->getAllEntitiesByComponentTypes({"RangedAttackComponent"});
    for (int i = 0; i < entities.size(); ++i) {
        Entity* entity = entities[i];
        
        RangedAttackComponent* attack = static_cast<RangedAttackComponent* >(entityManager->getComponentByTypeFromEntity(entity, "RangedAttackComponent"));
        
        if (entityManager->entityHasComponent(entity, "ControlsComponent")) {
            ControlsComponent* control = static_cast<ControlsComponent* >(entityManager->getComponentByTypeFromEntity(entity, "ControlsComponent"));
            PositionComponent* position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(entity, "PositionComponent"));
            bool fire = control->keys[EventKeyboard::KeyCode::KEY_SPACE];
            
            if (fire && attack->cooldownCounter == attack->cooldown) {
                Entity* stone = new Entity("stone", vector<MainComponent *> {
                    new RenderComponent(entityManager->currentScene,
                                        imageStorage->getImage("stone"),
                                        pair<float, float>(position->x, position->y),
                                        pair<float, float>(7, 7),
                                        "sprite"),
//                    new MotionComponent(250 * position->orientation, 250),
                    new PositionComponent(position->x, position->y, 1),
                    new GravityComponent(),
                    new ActiveCollisionComponent("player", {"player", "block"})
                });
                entityManager->addComponentToEntity(stone, new MotionComponent(250 * position->orientation, 250));
                entityManager->addEntity(stone);
                
                attack->cooldownCounter = 0;
            }
        }
        
        if (attack->cooldownCounter < attack->cooldown) {
            attack->cooldownCounter++;
        }
    }
}