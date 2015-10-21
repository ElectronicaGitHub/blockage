//
//  DndController.cpp
//  cppTests
//
//  Created by Philip Antonov on 20.10.15.
//
//

#include "DndController.h"

void DndController::tick(Entity* entity) {
    
    if (EntityManager::entityHasComponent(entity, DND_COMPONENT)) {
        
        ControlsComponent* player_controls = static_cast<ControlsComponent* >(EntityManager::getComponentByTypeFromEntity(entity, CONTROLS_COMPONENT));
        DndComponent* player_dragger = static_cast<DndComponent* >(EntityManager::getComponentByTypeFromEntity(entity, DND_COMPONENT));
        
        if (player_dragger->currentStateType == DRAGGING_STATE) {
            PositionComponent* draggable_position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(player_dragger->draggingEntity, POSITION_COMPONENT));
            PositionComponent* player_position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
            
            draggable_position->x = player_position->x;
            draggable_position->y = player_position->y + 15;
        }
        
        if (player_controls->keys[EventKeyboard::KeyCode::KEY_Z] && !buttonPressed) {
            // DRAG
            if (player_dragger->currentStateType == EMPTY_STATE) {
                player_dragger->getCurrentState()->handleEvent(entity, player_dragger, INPUT_Z);
            }
            // DROP
            else if (player_dragger->currentStateType == DRAGGING_STATE) {
                player_dragger->getCurrentState()->handleEvent(entity, player_dragger, INPUT_Z);
            }
            buttonPressed = true;
        }
        
        // BUTTON RELEASED
        else if (!player_controls->keys[EventKeyboard::KeyCode::KEY_Z] && buttonPressed) {
            buttonPressed = false;
        }
    }
}

