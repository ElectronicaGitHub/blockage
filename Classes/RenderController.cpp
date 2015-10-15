//
//  RenderController.cpp
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#include "RenderController.h"

void RenderController::tick(float delta) {
    vector<Entity*> entities = EntityManager::getAllEntitiesByComponentTypes({RENDER_COMPONENT, POSITION_COMPONENT});
    for (int i = 0; i < entities.size(); ++i) {
        Entity* entity = entities[i];
        RenderComponent* render = static_cast<RenderComponent* >(EntityManager::getComponentByTypeFromEntity(entity, RENDER_COMPONENT));
        PositionComponent* position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
        
        render->sprite->setPosition(position->x, position->y);
        render->sprite->setScaleX(abs(render->sprite->getScaleX()) * position->orientation);
    }
}
