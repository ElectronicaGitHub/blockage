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
        
        render->animatedSprite->setPosition(position->x, position->y);
        render->animatedSprite->setScaleX(abs(render->animatedSprite->getScaleX()) * position->orientation);
        
        // ОТРИСОВКА ТОЧЕК ДЛЯ ДЕБАГА

//        DrawNode* d1 = DrawNode::create();
//        DrawNode* d2 = DrawNode::create();
//        DrawNode* d3 = DrawNode::create();
//        DrawNode* d4 = DrawNode::create();
//        
//        Vec2 pos = render->animatedSprite->getPosition();
//        
//        Vec2 pos1 = { pos.x - render->animatedSprite->getBoundingBox().size.width / 2, pos.y - render->animatedSprite->getBoundingBox().size.height / 3 };
//        Vec2 pos2 = { pos.x - render->animatedSprite->getBoundingBox().size.width / 2, pos.y + render->animatedSprite->getBoundingBox().size.height * 2 / 3 };
//        Vec2 pos3 = { pos.x + render->animatedSprite->getBoundingBox().size.width / 2, pos.y - render->animatedSprite->getBoundingBox().size.height / 3 };
//        Vec2 pos4 = { pos.x + render->animatedSprite->getBoundingBox().size.width / 2, pos.y + render->animatedSprite->getBoundingBox().size.height * 2 / 3 };
//        
//        d1->drawDot(pos1, 0.5f, Color4F::BLACK);
//        d2->drawDot(pos2, 0.5f, Color4F::BLACK);
//        d3->drawDot(pos3, 0.5f, Color4F::BLACK);
//        d4->drawDot(pos4, 0.5f, Color4F::BLACK);
//        
//        render->layer->addChild(d1);
//        render->layer->addChild(d2);
//        render->layer->addChild(d3);
//        render->layer->addChild(d4);
//        
        
        AnimationComponent* animation = static_cast<AnimationComponent* >(EntityManager::getComponentByTypeFromEntity(entity, ANIMATION_COMPONENT));
        if (animation) {
            
            vector<StateType> state_types = EntityManager::getStateTypesFromEntity(entity);
            
            MotionComponent* motion = static_cast<MotionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, MOTION_COMPONENT));
            if (abs(motion->dx) > 10) {
                state_types.push_back(MOTION_STATE);
            }
            
            render->animate(animation->getAnimation(state_types));
        }
    }
}
