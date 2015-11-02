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
        
        
        AnimationComponent* animation = static_cast<AnimationComponent* >(EntityManager::getComponentByTypeFromEntity(entity, ANIMATION_COMPONENT));
        if (animation) {
            vector<StateType> animation_key = {};
            
            MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
            if (abs(motion->dx) > 5) {
                animation_key.push_back(MOTION_STATE);
            }
            
            render->animate(animation->getAnimation(animation_key), delta);
        }
    }
}
