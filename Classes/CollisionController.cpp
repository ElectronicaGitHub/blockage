//
//  CollisionController.cpp
//  cppTests
//
//  Created by Philip Antonov on 06.10.15.
//
//

#include "CollisionController.h"

void CollisionController::tick(EntityManager* entityManager) {
    
    vector<Entity*> active_entities = entityManager->getAllEntitiesByComponentType("ActiveCollisionComponent");
    vector<Entity*> passive_entities = entityManager->getAllEntitiesByComponentType("PassiveCollisionComponent");
    
    for (int i = 0; i < active_entities.size(); i++) {
        ActiveCollisionComponent* comp = static_cast<ActiveCollisionComponent*>(entityManager->getComponentByTypeFromEntity(active_entities[i], "ActiveCollisionComponent"));
        comp->collision["bottom"] = false;
        comp->collision["left"] = false;
        comp->collision["right"] = false;
        comp->collision["top"] = false;
        
        PositionComponent* position = static_cast<PositionComponent*>(entityManager->getComponentByTypeFromEntity(active_entities[i], "PositionComponent"));
        RenderComponent* render_comp1 = static_cast<RenderComponent *>(entityManager->getComponentByTypeFromEntity(active_entities[i], "RenderComponent"));
        
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
            RenderComponent* render_comp2 = static_cast<RenderComponent*>(entityManager->getComponentByTypeFromEntity(passive_entities[j], "RenderComponent"));
            Rect rect2 = render_comp2->sprite->getBoundingBox();
            
            float rect2MinX = rect2.getMinX();
            float rect2MaxX = rect2.getMaxX();
            float rect2MinY = rect2.getMinY();
            float rect2MaxY = rect2.getMaxY();
            
            if (r1bottomLine.intersectsRect(rect2)) {
                position->y = rect2MaxY + rect1.size.height/2;
                cout<<"bottom"<<endl;
                comp->collision["bottom"] = true;
            }
            if (r1leftLine.intersectsRect(rect2)) {
                position->x = rect2MaxX + rect1.size.height/2;
                cout<<"left"<<endl;
                comp->collision["left"] = true;
            }
            if (r1rightLine.intersectsRect(rect2)) {
                position->x = rect2MinX - rect1.size.height/2;
                cout<<"right"<<endl;
                comp->collision["right"] = true;
            }
            if (r1topLine.intersectsRect(rect2)) {
                position->y = rect2MinY - rect1.size.height/2;
                cout<<"top"<<endl;
                comp->collision["top"] = true;
            }
        }
    }
}
