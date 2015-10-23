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
        DndComponent* dnd = static_cast<DndComponent* >(EntityManager::getComponentByTypeFromEntity(entity, DND_COMPONENT));
        dnd->getCurrentState()->update(entity, dnd);
        
    }
}

