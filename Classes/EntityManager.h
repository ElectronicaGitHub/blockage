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
    static vector<Entity*> entities;
    static vector<Entity*> passive_entities;
    
    static void addEntity(Entity* _ent);
    static void addPassiveEntity(Entity* _ent);
    static Entity* getEntityById(string id);
    static MainComponent* getComponentByTypeFromEntity(Entity* entity, ComponentType type);
    static vector<Entity*> getAllEntitiesByComponentType(ComponentType type);
    static vector<Entity*> getAllEntitiesByComponentTypes(vector<ComponentType> types);
    static vector<Entity*> getAllEntities();
    static vector<Entity*> getAllPassiveEntities();
    static void removeEntityById(string id);
    static void removeEntity(Entity* entity);
    static void removeComponentFromEntityById(string id, ComponentType type);
    static void removeComponentFromEntity(Entity* entity, ComponentType type);
    static void addComponentToEntityById(string id, MainComponent* component);
    static void addComponentToEntity(Entity* entity, MainComponent* component);
    static void addStaticComponentToEntity(Entity* entity, MainComponent* component);
    static void addComponentsToEntityById(string id, vector<MainComponent*> components);
    static void addComponentsToEntity(Entity* entity, vector<MainComponent*> components);
    static bool entityByIdHasComponent(string id, ComponentType type);
    static bool entityHasComponent(Entity* entity, ComponentType type);
    static vector<Entity*> getNearestEntities(Entity* entity);
    static vector<Entity*> getNearestEntitiesWithComponentType(Entity* entity, ComponentType type);
    static vector<Entity*> getNearestPassiveEntities(Entity* entity);

};

#endif /* defined(__cppTests__EntityManager__) */
