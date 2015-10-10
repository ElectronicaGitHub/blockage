//
//  DragAndCarryController.cpp
//  cppTests
//
//  Created by Philip Antonov on 08.10.15.
//
//

#include "DragAndCarryController.h"

void DragAndCarryController::tick(EntityManager* entityManager) {
    
    vector<Entity* > players = entityManager->getAllEntitiesByComponentTypes({"DragAndCarryComponent", "ControlsComponent", "PositionComponent"});
    vector<Entity* > draggables = entityManager->getAllEntitiesByComponentTypes({"DraggableComponent", "PositionComponent", "RenderComponent"});
    
    for (auto i = 0; i < players.size(); ++i) {
        Entity* player = players[i];
        
        ControlsComponent* player_controls = static_cast<ControlsComponent* >(entityManager->getComponentByTypeFromEntity(player, "ControlsComponent"));
        DragAndCarryComponent* player_dragger = static_cast<DragAndCarryComponent* >(entityManager->getComponentByTypeFromEntity(player, "DragAndCarryComponent"));
        PositionComponent* player_position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(player, "PositionComponent"));
        
        if (player_dragger->state == "dragging") {
            PositionComponent* draggable_position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(player_dragger->draggingEntity, "PositionComponent"));
            draggable_position->x = player_position->x;
            draggable_position->y = player_position->y + 15;
        }
    
        if (player_controls->keys[EventKeyboard::KeyCode::KEY_Z]) {
            
            if (player_dragger->state == "empty") {
                
                for (auto j = 0; j < draggables.size(); ++j) {
                    
                    Entity* draggable = draggables[j];
                    
                    PositionComponent* draggable_position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(draggable, "PositionComponent"));
//                    RenderComponent* draggable_render = static_cast<RenderComponent* >(entityManager->getComponentByTypeFromEntity(draggable, "RenderComponent"));
                    
                    if (abs(player_position->x - draggable_position->x) <= 100) {
                        player_dragger->draggingEntity = draggable;
                        player_dragger->state = "dragging";
                        
                        entityManager->removeComponentFromEntity(player_dragger->draggingEntity, "PassiveCollisionComponent");
                        entityManager->removeComponentFromEntity(player_dragger->draggingEntity, "MotionComponent");
                        entityManager->removeComponentFromEntity(player_dragger->draggingEntity, "GravityComponent");
                    }
                }
            }
        }
        else if (player_controls->keys[EventKeyboard::KeyCode::KEY_X] && player_dragger->state == "dragging") {
//            entityManager->addComponentToEntity(player_dragger->draggingEntity, new MotionComponent(200 * player_position->orientation, 100));
            entityManager->addComponentToEntity(player_dragger->draggingEntity, new GravityComponent());
            entityManager->addComponentToEntity(player_dragger->draggingEntity, new PassiveCollisionComponent());
            
//            player_dragger->draggingEntity = NULL;
            player_dragger->state = "empty";

        }
    }
}