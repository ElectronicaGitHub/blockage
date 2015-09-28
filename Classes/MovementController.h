//
//  MovementController.h
//  cppTests
//
//  Created by Philip Antonov on 26.09.15.
//
//

#ifndef __cppTests__MovementController__
#define __cppTests__MovementController__

#include <stdio.h>
#include "EntityManager.h"
#include "RenderComponent.h"
#include "ControlsComponent.h"

using namespace std;

class MovementController {
public:
    MovementController() {};
    ~MovementController() {};
    
    void tick() {
        EntityManager entityManager;
        vector<Entity*> entities = entityManager.GetAllEntitiesByComponentTypes({"MovementComponent", "ControlsComponent"});
        
        for (int i = 0; i < entities.size(); ++i) {
            
            ControlsComponent* control = static_cast<ControlsComponent* >(entityManager.GetComponentByTypeFromEntity(entities[i], "ControlsComponent"));
            RenderComponent* render = static_cast<RenderComponent* >(entityManager.GetComponentByTypeFromEntity(entities[i], "RenderComponent"));
            if (control->keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_A]) {
                render->coords.first--;
            }
            if (control->keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_D]) {
                render->coords.first++;
            }
            if (control->keys[EventKeyboard::KeyCode::KEY_UP_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_W]) {
                render->coords.second++;
            }
            if (control->keys[EventKeyboard::KeyCode::KEY_DOWN_ARROW] || control->keys[EventKeyboard::KeyCode::KEY_S]) {
                render->coords.second--;
            }
        }
    }
};

#endif /* defined(__cppTests__MovementController__) */
