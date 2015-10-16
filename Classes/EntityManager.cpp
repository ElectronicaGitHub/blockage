//
//  EntityManager.cpp
//  cppTests
//
//  Created by Philip Antonov on 25.09.15.
//
//

#include "EntityManager.h"

using namespace std;

vector<Entity* > EntityManager::entities;

void EntityManager::addEntity(Entity* _ent) {
    entities.push_back(_ent);
}

Entity* EntityManager::getEntityById(string id) {
    Entity* returning_entity;
    for (auto i = 0 ; i != entities.size(); ++i) {
        if (entities[i]->id == id) {
            return entities[i];
        }
    }
    return returning_entity;
}

MainComponent* EntityManager::getComponentByTypeFromEntity(Entity* entity, ComponentType type) {
    for (auto i = 0; i < entity->allComponents().size(); ++i) {
        if (entity->allComponents()[i]->type == type) {
            return entity->allComponents()[i];
        }
    }
    
    return NULL;
};

vector<Entity *> EntityManager::getAllEntitiesByComponentType(ComponentType type) {
    
    vector<Entity *> returning_vector;
    
    for (auto i = 0 ; i != entities.size(); ++i) {
        for (auto j = 0; j != entities[i]->allComponents().size(); ++j) {
            if (entities[i]->allComponents()[j]->type == type) {
                returning_vector.push_back(entities[i]);
            }
        }
    }
    
    return returning_vector;
}

vector<Entity *> EntityManager::getAllEntitiesByComponentTypes(vector<ComponentType> types) {
    vector<Entity *> returning_vector;
    int fullness = types.size();
    
    for (auto i = 0 ; i != entities.size(); ++i) {
        int count = 0;
        for (auto j = 0; j != entities[i]->allComponents().size(); ++j) {
            for (auto k = 0; k != types.size(); ++k) {
                if (entities[i]->allComponents()[j]->type == types[k]) {
                    count+=1;
                }
            }
        }
        if (fullness == count) {
            returning_vector.push_back(entities[i]);
        }
        count = 0;
    }
    
    return returning_vector;
}

vector<MainComponent *> EntityManager::getComponentsByEntityId(string id) {
    Entity* entity = getEntityById(id);
    return entity->allComponents();
}

vector<MainComponent*> EntityManager::getComponentsByType(ComponentType type) {
    vector<MainComponent*> returning_vector, components;
    
    for (auto entity = entities.begin(); entity != entities.end(); ++entity) {
        components = (*entity)->allComponents();
        for (auto component = components.begin(); component != components.end(); ++component) {
            if ((*component)->type == type) {
                returning_vector.push_back(*component);
            }
        }
    }
    
    return returning_vector;
}

vector<Entity *> EntityManager::getAllEntities() {
    return entities;
}

void EntityManager::removeEntityById(string id) {
    for (auto i = 0 ; i != entities.size(); ++i) {
        if (entities[i]->id == id) {
            delete entities[i];
            entities.erase(entities.begin() + i);
            i--;
        }
    }
}

void EntityManager::removeEntity(Entity* entity) {
    for (auto i = 0 ; i != entities.size(); ++i) {
        if (entities[i]->id == entity->id) {
            delete entities[i];
            entities.erase(entities.begin() + i);
            i--;
        }
    }
}

void EntityManager::removeComponentFromEntityById(string id, ComponentType type) {
    Entity* entity = getEntityById(id);
    
    for (auto i = 0 ; i != entity->allComponents().size(); ++i) {
        if (entity->components[i]->type == type) {
            delete entity->allComponents()[i];
            entity->components.erase(entity->allComponents().begin() + i);
            i--;
        }
    }
}

void EntityManager::removeComponentFromEntity(Entity* entity, ComponentType type) {
    for (auto i = 0 ; i != entity->allComponents().size(); ++i) {
        if (entity->allComponents()[i]->type == type) {
            delete entity->allComponents()[i];
            entity->components.erase(entity->allComponents().begin() + i);
            i--;
        }
    }
}

void EntityManager::addComponentToEntityById(string id, MainComponent* component) {
    Entity* entity = getEntityById(id);
    entity->components.push_back(component);
}

void EntityManager::addComponentToEntity(Entity* entity, MainComponent* component) {
    entity->components.push_back(component);
}
void EntityManager::addStaticComponentToEntity(Entity* entity, MainComponent* component) {
    entity->addStaticComponent(component);
}

void EntityManager::addComponentsToEntityById(string id, vector<MainComponent*> components) {
    Entity* entity = getEntityById(id);
    
    for (auto it = components.begin(); it != components.end(); ++it) {
        addComponentToEntity(entity, (*it));
    }

}
void EntityManager::addComponentsToEntity(Entity* entity, vector<MainComponent*> components) {
    for (auto it = components.begin(); it != components.end(); ++it) {
        addComponentToEntity(entity, (*it));
    }
}

bool EntityManager::entityByIdHasComponent(string id, ComponentType type) {
    Entity* entity = getEntityById(id);
    vector<MainComponent*> components = entity->allComponents();
    
    for (auto it = components.begin(); it != components.end(); ++it) {
        if ((*it)->type == type) {
            return true;
        }
    }
    return false;
}

bool EntityManager::entityHasComponent(Entity* entity, ComponentType type) {
    vector<MainComponent*> components = entity->allComponents();
    for (auto it = components.begin(); it != components.end(); ++it) {
        if ((*it)->type == type) {
            return true;
        }
    }
    return false;
}

vector<Entity*> EntityManager::getNearestEntities(Entity* entity) {
    vector<Entity *> returning_vector;
    
    PositionComponent* position = static_cast<PositionComponent* >(getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
    PositionComponent* position_i;
    float x0 = position->x, y0 = position->y, x1, y1;
    
    for (int i = 0 ; i != entities.size(); ++i) {
        position_i = static_cast<PositionComponent* >(getComponentByTypeFromEntity(entities[i], POSITION_COMPONENT));
        x1 = position_i->x;
        y1 = position_i->y;
        if (entity->id != entities[i]->id && (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) < 400) {
            returning_vector.push_back(entities[i]);
        }
    }
    
    return returning_vector;
}

vector<Entity*> EntityManager::getNearestEntitiesWithComponentType(Entity* entity, ComponentType type) {
    vector<Entity *> returning_vector;
    
    PositionComponent* position = static_cast<PositionComponent* >(getComponentByTypeFromEntity(entity, POSITION_COMPONENT));
    PositionComponent* position_i;
    float x0 = position->x, y0 = position->y, x1, y1;
    
    for (int i = 0 ; i != entities.size(); ++i) {
        position_i = static_cast<PositionComponent* >(getComponentByTypeFromEntity(entities[i], POSITION_COMPONENT));
        x1 = position_i->x;
        y1 = position_i->y;
        if ((entity->id != entities[i]->id) && (entityHasComponent(entities[i], type)) && ((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) < 400)) {
            returning_vector.push_back(entities[i]);
        }
    }
    
    return returning_vector;
}