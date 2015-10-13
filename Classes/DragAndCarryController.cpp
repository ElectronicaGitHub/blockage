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
    
        // DRAG
        if (player_controls->keys[EventKeyboard::KeyCode::KEY_Z]) {
            
            if (player_dragger->state == "empty") {
                
                for (auto j = 0; j < draggables.size(); ++j) {
                    
                    Entity* draggable = draggables[j];
                    
                    PositionComponent* draggable_position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(draggable, "PositionComponent"));
                    DraggableComponent* draggable_component = static_cast<DraggableComponent* >(entityManager->getComponentByTypeFromEntity(draggable, "DraggableComponent"));
                    
                    if (abs(player_position->x - draggable_position->x) <= 30 &&
                        abs(player_position->y - draggable_position->y) < 20) {
                        
                        if (draggable_component->droppedToComponent && draggable_component->droppedToComponent->filled) {
                            draggable_component->droppedToComponent->filled = false;
                        }
                        
                        player_dragger->draggingEntity = draggable;
                        player_dragger->state = "dragging";
                        
                        entityManager->removeComponentFromEntity(player_dragger->draggingEntity, "PassiveCollisionComponent");
                        entityManager->removeComponentFromEntity(player_dragger->draggingEntity, "MotionComponent");
                        entityManager->removeComponentFromEntity(player_dragger->draggingEntity, "GravityComponent");
                    }
                }
            }
        }
        
        // DROP
        else if (player_controls->keys[EventKeyboard::KeyCode::KEY_X] && player_dragger->state == "dragging") {
            
            vector<Entity* > droppables = entityManager->getAllEntitiesByComponentTypes({"DropComponent", "RenderComponent", "PositionComponent"});
            
            for (auto i = 0 ; i < droppables.size(); ++i) {
                Entity* droppable = droppables[i];
                
                vector<pair<float, Entity*>> results;
                
                PositionComponent* drag_position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(player_dragger->draggingEntity, "PositionComponent"));
                DraggableComponent* drag_component = static_cast<DraggableComponent* >(entityManager->getComponentByTypeFromEntity(player_dragger->draggingEntity, "DraggableComponent"));
                
                PositionComponent* drop_position = static_cast<PositionComponent* >(entityManager->getComponentByTypeFromEntity(droppable, "PositionComponent"));
                DropComponent* drop_component = static_cast<DropComponent* >(entityManager->getComponentByTypeFromEntity(droppable, "DropComponent"));
                
                float distanceX = abs(drag_position->x - drop_position->x);
                float distanceY = drag_position->y - drop_position->y;
                
                if (distanceX <= 20 && distanceY > 20 && !drop_component->filled) {
                    
                    entityManager->addComponentToEntity(player_dragger->draggingEntity, new GravityComponent());
                    entityManager->addComponentToEntity(player_dragger->draggingEntity, new PassiveCollisionComponent());
                    
                    drop_component->fillEmenent = player_dragger->draggingEntity;
                    drop_component->filled = true;
                    
                    player_dragger->draggingEntity = NULL;
                    player_dragger->state = "empty";
                    
                    drag_position->x = drop_position->x;
                    drag_position->y = drop_position->y;
                    
                    drag_component->droppedTo = droppable;
                    drag_component->droppedToComponent = drop_component;
                
                    break;
                }
            }
            
//

        }
    }
}












