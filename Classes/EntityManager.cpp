//
//  EntityManager.cpp
//  cppTests
//
//  Created by Philip Antonov on 25.09.15.
//
//

#include "EntityManager.h"

using namespace std;

void EntityManager::addEntity(Entity* _ent) {
    entities.push_back(_ent);
    
    cout << "Entity Added" << endl;
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

MainComponent* EntityManager::getComponentByTypeFromEntity(Entity* entity, string type) {
    MainComponent* returning_component;
    
    for (auto i = 0; i < entity->components.size(); ++i) {
        if (entity->components[i]->type == type) {
            returning_component = entity->components[i];
        }
    }
    
    return returning_component;
};

vector<Entity *> EntityManager::getAllEntitiesByComponentType(string type) {
    
    vector<Entity *> returning_vector;
    
    for (auto i = 0 ; i != entities.size(); ++i) {
        for (auto j = 0; j != entities[i]->components.size(); ++j) {
            if (entities[i]->components[j]->type == type) {
                returning_vector.push_back(entities[i]);
            }
        }
    }
    
    cout << "GetAllEntitiesByComponentType entities count : " << returning_vector.size() << endl;
    
    return returning_vector;
}

vector<Entity *> EntityManager::getAllEntitiesByComponentTypes(vector<string> types) {
    vector<Entity *> returning_vector;
    int fullness = types.size();
    
    for (auto i = 0 ; i != entities.size(); ++i) {
        int count = 0;
        for (auto j = 0; j != entities[i]->components.size(); ++j) {
            for (auto k = 0; k != types.size(); ++k) {
                if (entities[i]->components[j]->type == types[k]) {
                    count+=1;
                }
            }
        }
        if (fullness == count) {
            returning_vector.push_back(entities[i]);
        }
        count = 0;
    }
    
    //        cout << "GetAllEntitiesByComponentTypes entities count : " << returning_vector.size() << endl;
    
    return returning_vector;
}

vector<MainComponent *> EntityManager::getComponentsByEntityId(string id) {
    vector<MainComponent *> returning_vector;
    
    Entity* entity = getEntityById(id);
    returning_vector = entity->components;
    
    cout << "GetComponentsByEntityId components count : " << returning_vector.size() << endl;
    return returning_vector;
}

vector<MainComponent *> EntityManager::getComponentsByType(string type) {
    vector<MainComponent *> returning_vector;
    
    for (auto entity = entities.begin(); entity != entities.end(); ++entity) {
        for (auto component = (*entity)->components.begin(); component != (*entity)->components.end(); ++component) {
            if ((*component)->type == type) {
                returning_vector.push_back(*component);
            }
        }
    }
    
    //        cout << "GetComponentsByType components of type " << type << " count : " << returning_vector.size() << endl;
    return returning_vector;
}

vector<Entity *> EntityManager::getAllEntities() {
    vector<Entity *> returning_vector = entities;
    
    cout << "GetAllEntities entities count : " << returning_vector.size() << endl;
    
    return returning_vector;
}

void EntityManager::removeEntityById(string id) {
    cout << "RemoveEntityById entities count before remove : " << entities.size();
    for (auto i = 0 ; i != entities.size(); ++i) {
        if (entities[i]->id == id) {
            delete entities[i];
            entities.erase(entities.begin() + i);
            i--;
        }
    }
    cout << ", after remove : " << entities.size() << endl;
}

void EntityManager::removeComponentFromEntityById(string id, string type) {
    Entity* entity = getEntityById(id);
    
    cout << "RemoveComponentFromEntityById entities count before remove : " << entity->components.size();
    for (auto i = 0 ; i != entity->components.size(); ++i) {
        if (entity->components[i]->type == type) {
            delete entity->components[i];
            entity->components.erase(entity->components.begin() + i);
            i--;
        }
    }
    cout << ", after remove : " << entity->components.size() << endl;
}

void EntityManager::removeComponentFromEntity(Entity* entity, string type) {
    cout << "RemoveComponentFromEntity entities count before remove : " << entity->components.size();
    for (auto i = 0 ; i != entity->components.size(); ++i) {
        if (entity->components[i]->type == type) {
            delete entity->components[i];
            entity->components.erase(entity->components.begin() + i);
            i--;
        }
    }
    cout << ", after remove : " << entity->components.size() << endl;
}

void EntityManager::addComponentToEntityById(string id, MainComponent* component) {
    Entity* entity = getEntityById(id);
    
    cout << "AddComponentToEntityById components count : " << entity->components.size();
    
    entity->components.push_back(component);
    
    cout << ", after : " << entity->components.size() << endl;
}

void EntityManager::addComponentToEntity(Entity* entity, MainComponent* component) {
    
    cout << "AddComponentToEntity components count : " << entity->components.size();
    
    entity->components.push_back(component);
    
    cout << ", after : " << entity->components.size() << endl;
    
    delete component;
}

void EntityManager::addComponentsToEntityById(string id, vector<MainComponent*> components) {
    Entity* entity = getEntityById(id);
    
    cout << "AddComponentsToEntityById components count : " << entity->components.size();
    
    for (auto it = components.begin(); it != components.end(); ++it) {
        // for (auto i = 0; i != components.size(); ++i) {
        addComponentToEntity(entity, (*it));
    }
    
    cout << ", after : " << entity->components.size() << endl;
}
void EntityManager::addComponentsToEntity(Entity* entity, vector<MainComponent*> components) {
    
    cout << "AddComponentsToEntity components count : " << entity->components.size();
    
    for (auto it = components.begin(); it != components.end(); ++it) {
        // for (auto i = 0; i != components.size(); ++i) {
        addComponentToEntity(entity, (*it));
    }
    
    cout << ", after : " << entity->components.size() << endl;
}

bool EntityManager::entityByIdHasComponent(string id, string type) {
    bool value = false;
    
    Entity* entity = getEntityById(id);
    
    for (auto it = entity->components.begin(); it != entity->components.end(); ++it) {
        if ((*it)->type == type) {
            value = true;
        }
    }
    cout << "EntityByIdHasComponent, entity component hasness : " << value << endl;
    
    return value;
}

bool EntityManager::entityHasComponent(Entity* entity, string type) {
    bool value = false;
    
    for (auto it = entity->components.begin(); it != entity->components.end(); ++it) {
        if ((*it)->type == type) {
            value = true;
        }
    }
    //        cout << "EntityHasComponent, entity component hasness : " << value << endl;
    
    return value;
}