//
//  RenderController.cpp
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#include "RenderController.h"

void RenderController::tick(EntityManager* entityManager, float delta) {
    vector<Entity*> entities = entityManager->getAllEntitiesByComponentTypes({"RenderComponent", "PositionComponent"});
    for (int i = 0; i < entities.size(); ++i) {
        Entity* entity = entities[0];
        RenderComponent* render = static_cast<RenderComponent* >(entityManager->getComponentByTypeFromEntity(entity, "RenderComponent"));
        PositionComponent* position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(entity, "PositionComponent"));
        
        render->sprite->setPosition(position->x, position->y);
        render->sprite->setScaleX(abs(render->sprite->getScaleX()) * position->orientation);
    }
}
