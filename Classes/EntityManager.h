//
//  EntityManager.h
//  cppTests
//
//  Created by Philip Antonov on 25.09.15.
//
//

#ifndef __cppTests__EntityManager__
#define __cppTests__EntityManager__

#include <stdio.h>
#include "Entity.h"
#include "MainComponent.h"
#include "iostream"

using namespace std;

class EntityManager
{
public:
    vector<Entity *> entities;
    
    cocos2d::Layer* currentScene;
    
    EntityManager(cocos2d::Layer* scene) {
        currentScene = scene;
    };
    ~EntityManager() {};
    
    void addEntity(Entity* _ent);
    Entity* getEntityById(string id);
    MainComponent* getComponentByTypeFromEntity(Entity* entity, string type);
    vector<Entity *> getAllEntitiesByComponentType(string type);
    vector<Entity *> getAllEntitiesByComponentTypes(vector<string> types);
    vector<MainComponent *> getComponentsByEntityId(string id);
    vector<MainComponent *> getComponentsByType(string type);
    vector<Entity *> getAllEntities();
    void removeEntityById(string id);
    void removeComponentFromEntityById(string id, string type);
    void removeComponentFromEntity(Entity* entity, string type);
    void addComponentToEntityById(string id, MainComponent* component);
    void addComponentToEntity(Entity* entity, MainComponent* component);
    void addComponentsToEntityById(string id, vector<MainComponent*> components);
    void addComponentsToEntity(Entity* entity, vector<MainComponent*> components);
    bool entityByIdHasComponent(string id, string type);
    bool entityHasComponent(Entity* entity, string type);

};

#endif /* defined(__cppTests__EntityManager__) */
