//
//  RenderController.h
//  cppTests
//
//  Created by Philip Antonov on 27.09.15.
//
//

#ifndef __cppTests__RenderController__
#define __cppTests__RenderController__

#include <stdio.h>
#include "EntityManager.h"
#include "RenderComponent.h"

class RenderController {
public:
    RenderController() {};
    ~RenderController() {};
    
    void tick() {
        EntityManager entityManager;
//        vector<Entity *> rightEntities = entityManager.GetAllEntitiesByComponentType("RenderComponent");
        vector<MainComponent *> rightComponents = entityManager.GetComponentsByType("RenderComponent");
        
        for (int i = 0; i < rightComponents.size(); ++i) {
//            RenderComponent* local_c = (RenderComponent *)rightComponents[i];
            RenderComponent* local_c = static_cast<RenderComponent *>(rightComponents[i]);
            local_c->sprite->setPosition(local_c->coords.first, local_c->coords.second);
//            cout << "I'm render sprite on: (" << local_c->coords.first << "," << local_c->coords.second << ")" << endl;
        }
    }
};

#endif /* defined(__cppTests__RenderController__) */
