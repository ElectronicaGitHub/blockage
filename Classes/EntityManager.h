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
using namespace std;

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();
    
    static Entity* GetEntityById(string id);
    static vector<Entity *> GetAllEntitiesByComponentType(string type);
    static vector<Entity *> GetAllEntitiesByComponentTypes(vector<string> types);
    static vector<MainComponent *> GetComponentsByEntityId(string id);
    static vector<MainComponent *> GetComponentsByType(string type);
    static vector<Entity *> GetAllEntities(vector<Entity *> entities);
    static void RemoveEntityById(string id);
    static void RemoveComponentFromEntityById(string id, string type);
    static void RemoveComponentFromEntity(Entity* entity, string type);
    static void AddComponentToEntityById(string id, MainComponent* component);
    static void AddComponentToEntity(Entity* entity, MainComponent* component);
    static void AddComponentsToEntityById(string id, vector<MainComponent*> components);
    static void AddComponentsToEntity(Entity* entity, vector<MainComponent*> components);
    static bool EntityByIdHasComponent(string id, string type);
    static bool EntityHasComponent(Entity* entity, string type);
};

#endif /* defined(__cppTests__EntityManager__) */
