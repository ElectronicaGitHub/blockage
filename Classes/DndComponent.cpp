//
//  DndComponent.cpp
//  cppTests
//
//  Created by Philip Antonov on 20.10.15.
//
//

#include "DndComponent.h"

map<StateType, State*> DndComponent::states = {
    { DND_EMPTY_STATE, new EmptyState() },
    { DND_DRAGGING_STATE, new DraggingState() }
};

void EmptyState::handleEvent(Entity* entity, MainComponent* component, EventType event) {
    if (event == INPUT_Z) {
        
        PositionComponent* player_position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
        DndComponent* player_dragger = static_cast<DndComponent* >(EntityManager::getComponentByTypeFromEntity(entity, DND_COMPONENT));
        
        vector<Entity*> draggables = EntityManager::getAllEntitiesByComponentType(DRAG_COMPONENT);
        
        for (auto j = 0; j < draggables.size(); ++j) {
            
            Entity* draggable = draggables[j];
            
            PositionComponent* draggable_position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(draggable, POSITION_COMPONENT));
            
            if (abs(player_position->x - draggable_position->x) <= 30 &&
                abs(player_position->y - draggable_position->y) < 20) {
                
                player_dragger->draggingEntity = draggable;
                
                DndComponent* dnd = static_cast<DndComponent*>(component);
                dnd->switchState(DND_DRAGGING_STATE, dnd->states[DND_DRAGGING_STATE], entity);
            }
        }
    }
};
void EmptyState::onEnter(Entity* entity, MainComponent* component) {};
void EmptyState::update(Entity* entity, MainComponent* component) {};
void EmptyState::onExit(Entity* entity, MainComponent* component) {
    
    DndComponent* player_dragger = static_cast<DndComponent* >(EntityManager::getComponentByTypeFromEntity(entity, DND_COMPONENT));
    DragComponent* draggable_component = static_cast<DragComponent* >(EntityManager::getComponentByTypeFromEntity(player_dragger->draggingEntity, DRAG_COMPONENT));
    
    if (draggable_component->droppedToComponent && draggable_component->droppedToComponent->filled) {
        draggable_component->droppedToComponent->filled = false;
    }
    player_dragger->currentStateType = DND_DRAGGING_STATE;
    
    EntityManager::removeComponentFromEntity(player_dragger->draggingEntity, PASSIVE_COLLISION_COMPONENT);
    EntityManager::removeComponentFromEntity(player_dragger->draggingEntity, MOTION_COMPONENT);
    EntityManager::removeComponentFromEntity(player_dragger->draggingEntity, GRAVITY_COMPONENT);
};



void DraggingState::handleEvent(Entity* entity, MainComponent* component, EventType event) {
    if (event == INPUT_Z) {
        
        DndComponent* player_dragger = static_cast<DndComponent* >(EntityManager::getComponentByTypeFromEntity(entity, DND_COMPONENT));
        
        vector<Entity* > droppables = EntityManager::getNearestPassiveEntities(entity);
        
        for (auto i = 0 ; i < droppables.size(); ++i) {
            if (EntityManager::entityHasComponent(droppables[i], DROP_COMPONENT)) {
                Entity* droppable = droppables[i];
                
                PositionComponent* drag_position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(player_dragger->draggingEntity, POSITION_COMPONENT));
                DragComponent* drag_component = static_cast<DragComponent* >(EntityManager::getComponentByTypeFromEntity(player_dragger->draggingEntity, DRAG_COMPONENT));
                
                PositionComponent* drop_position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(droppable, POSITION_COMPONENT));
                DropComponent* drop_component = static_cast<DropComponent* >(EntityManager::getComponentByTypeFromEntity(droppable, DROP_COMPONENT));
                
                float distanceX = abs(drag_position->x - drop_position->x);
                float distanceY = drag_position->y - drop_position->y;
                
                if (distanceX <= 20 && distanceY > 20 && !drop_component->filled) {
                    
                    EntityManager::addComponentToEntity(player_dragger->draggingEntity, new GravityComponent(1, 1, 0));
                    EntityManager::addComponentToEntity(player_dragger->draggingEntity, new PassiveCollisionComponent());
                    
                    drop_component->fillEmenent = player_dragger->draggingEntity;
                    
                    drag_component->droppedTo = droppable;
                    drag_component->droppedToComponent = drop_component;
                    
                    player_dragger->switchState(DND_EMPTY_STATE, player_dragger->states[DND_EMPTY_STATE], entity);
                    
                    break;
                }
            }
        }
    }
};
void DraggingState::onEnter(Entity* entity, MainComponent* component) {};
void DraggingState::update(Entity* entity, MainComponent* component) {
    
    DndComponent* player_dragger = static_cast<DndComponent* >(EntityManager::getComponentByTypeFromEntity(entity, DND_COMPONENT));
    PositionComponent* draggable_position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(player_dragger->draggingEntity, POSITION_COMPONENT));
    PositionComponent* player_position = static_cast<PositionComponent* >(EntityManager::getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
    
    draggable_position->x = player_position->x;
    draggable_position->y = player_position->y + 15;
};
void DraggingState::onExit(Entity* entity, MainComponent* component) {
    
    DndComponent* player_dragger = static_cast<DndComponent* >(EntityManager::getComponentByTypeFromEntity(entity, DND_COMPONENT));
    
    DragComponent* drag_component = static_cast<DragComponent *>(EntityManager::getComponentByTypeFromEntity(player_dragger->draggingEntity, DRAG_COMPONENT));
    PositionComponent* drag_position = static_cast<PositionComponent *>(EntityManager::getComponentByTypeFromEntity(player_dragger->draggingEntity, POSITION_COMPONENT));
    
    PositionComponent* drop_position = static_cast<PositionComponent *>(EntityManager::getComponentByTypeFromEntity(drag_component->droppedTo, POSITION_COMPONENT));
    
    drag_component->droppedToComponent->filled = true;
    
    player_dragger->draggingEntity = NULL;
    player_dragger->currentStateType = DND_EMPTY_STATE;
    
    drag_position->x = drop_position->x;
    drag_position->y = drop_position->y;
};