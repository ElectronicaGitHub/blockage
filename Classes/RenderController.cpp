//
//  RenderController.cpp
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#include "RenderController.h"

void RenderController::tick(Entity* entity, float delta) {
    if (EntityManager::entityHasComponent(entity, RENDER_COMPONENT)) {
        RenderComponent* render = static_cast<RenderComponent* >(EntityManager::getComponentByTypeFromEntity(entity, RENDER_COMPONENT));
        PositionComponent* position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
        
        render->sprite->setPosition(position->x, position->y);
        render->sprite->setScaleX(abs(render->sprite->getScaleX()) * position->orientation);
    }
}
