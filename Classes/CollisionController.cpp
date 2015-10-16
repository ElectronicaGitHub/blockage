//
//  CollisionController.cpp
//  cppTests
//
//  Created by Philip Antonov on 06.10.15.
//
//

#include "CollisionController.h"

void CollisionController::tick() {
    
    vector<Entity*> active_entities = EntityManager::getAllEntitiesByComponentType(ACTIVE_COLLISION_COMPONENT);
    vector<Entity*> passive_entities = EntityManager::getAllEntitiesByComponentType(PASSIVE_COLLISION_COMPONENT);
    
    for (int i = 0; i < active_entities.size(); i++) {
        Entity* entity = active_entities[i];
        ActiveCollisionComponent* comp = static_cast<ActiveCollisionComponent*>(EntityManager::getComponentByTypeFromEntity(entity, ACTIVE_COLLISION_COMPONENT));
        comp->collision[COL_BOTTOM] = false;
        comp->collision[COL_LEFT] = false;
        comp->collision[COL_RIGHT] = false;
        comp->collision[COL_TOP] = false;
        
        PositionComponent* position = static_cast<PositionComponent*>(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
        RenderComponent* render_comp1 = static_cast<RenderComponent *>(EntityManager::getComponentByTypeFromEntity(entity, RENDER_COMPONENT));
        
        Rect rect1 = render_comp1->sprite->getBoundingBox();
        float rect1MinX = rect1.getMinX();
        float rect1MaxX = rect1.getMaxX();
        float rect1MinY = rect1.getMinY();
        float rect1MaxY = rect1.getMaxY();
        
        Rect r1bottomLine = Rect(rect1MinX + controlPanelSize, rect1MinY - controlPanelSize, rect1.size.width - 2 * controlPanelSize, controlPanelSize);
        Rect r1topLine =    Rect(rect1MinX + controlPanelSize, rect1MaxY                   , rect1.size.width - 2 * controlPanelSize, controlPanelSize);
        
        Rect r1leftLine =   Rect(rect1MinX,                    rect1MinY + controlPanelSize, controlPanelSize, rect1.size.height - 2 * controlPanelSize);
        Rect r1rightLine =  Rect(rect1MaxX,                    rect1MinY + controlPanelSize, controlPanelSize, rect1.size.height - 2 * controlPanelSize);
        
        for (int j = 0; j < passive_entities.size(); j++) {
            RenderComponent* render_comp2 = static_cast<RenderComponent*>(EntityManager::getComponentByTypeFromEntity(passive_entities[j], RENDER_COMPONENT));
            Rect rect2 = render_comp2->sprite->getBoundingBox();
            
            float rect2MinX = rect2.getMinX();
            float rect2MaxX = rect2.getMaxX();
            float rect2MinY = rect2.getMinY();
            float rect2MaxY = rect2.getMaxY();
            
            if (r1bottomLine.intersectsRect(rect2)) {
                position->y = rect2MaxY + rect1.size.height/2;
                comp->collision[COL_BOTTOM] = true;
                
                if (EntityManager::entityHasComponent(entity, JUMPING_COMPONENT)) {
                    JumpingComponent* jumping = static_cast<JumpingComponent* >(EntityManager::getComponentByTypeFromEntity(entity, JUMPING_COMPONENT));
                    jumping->getCurrentState()->handleEvent(entity, jumping, COLLISION_BOTTOM);
                }
            }
            if (r1leftLine.intersectsRect(rect2)) {
                position->x = rect2MaxX + rect1.size.height/2;
                comp->collision[COL_LEFT] = true;
            }
            if (r1rightLine.intersectsRect(rect2)) {
                position->x = rect2MinX - rect1.size.height/2;
                comp->collision[COL_RIGHT] = true;
            }
            if (r1topLine.intersectsRect(rect2)) {
                position->y = rect2MinY - rect1.size.height/2;
                comp->collision[COL_TOP] = true;
            }
        }
    }
}
