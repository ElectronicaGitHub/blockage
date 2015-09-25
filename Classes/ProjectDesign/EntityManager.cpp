class EntityManager
{
public:
    EntityManager() {};
    ~EntityManager() {};
    
    static Entity* GetEntityById(string id) {
        Entity* returning_entity;
        for (auto i = 0 ; i != entities.size(); ++i) {
            if (entities[i]->id == id) {
                return entities[i];
            }
        }
        return returning_entity;
    }
    
    static vector<Entity *> GetAllEntitiesByComponentType(string type) {
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
    
    static vector<Entity *> GetAllEntitiesByComponentTypes(vector<string> types) {
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
        
        cout << "GetAllEntitiesByComponentTypes entities count : " << returning_vector.size() << endl;
        
        return returning_vector;
    }
    
    static vector<Component *> GetComponentsByEntityId(string id) {
        vector<Component *> returning_vector;
        
        Entity* entity = GetEntityById(entities, id);
        returning_vector = entity->components;
        
        cout << "GetComponentsByEntityId components count : " << returning_vector.size() << endl;
        return returning_vector;
    }
    
    static vector<Component *> GetComponentsByType(string type) {
        vector<Component *> returning_vector;
        
        for (auto entity = entities.begin(); entity != entities.end(); ++entity) {
            for (auto component = (*entity)->components.begin(); component != (*entity)->components.end(); ++component) {
                if ((*component)->type == type) {
                    returning_vector.push_back(*component);
                }
            }
        }
        
        cout << "GetComponentsByType components of type " << type << " count : " << returning_vector.size() << endl;
        return returning_vector;
    }
    
    static vector<Entity *> GetAllEntities(vector<Entity *> entities) {
        vector<Entity *> returning_vector = entities;
        
        cout << "GetAllEntities entities count : " << returning_vector.size() << endl;
        
        return returning_vector;
    }
    
    static void RemoveEntityById(string id) {
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
    
    static void RemoveComponentFromEntityById(string id, string type) {
        Entity* entity = GetEntityById(entities, id);
        
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
    
    static void RemoveComponentFromEntity(Entity* entity, string type) {
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
    
    static void AddComponentToEntityById(string id, Component* component) {
        Entity* entity = GetEntityById(entities, id);
        
        cout << "AddComponentToEntityById components count : " << entity->components.size();
        
        entity->components.push_back(component);
        
        cout << ", after : " << entity->components.size() << endl;
    }
    
    static void AddComponentToEntity(Entity* entity, Component* component) {
        
        // cout << "AddComponentToEntity components count : " << entity->components.size();
        
        entity->components.push_back(component);
        
        // cout << ", after : " << entity->components.size() << endl;
    }
    
    static void AddComponentsToEntityById(string id, vector<Component*> components) {
        Entity* entity = GetEntityById(entities, id);
        
        cout << "AddComponentsToEntityById components count : " << entity->components.size();
        
        for (auto it = components.begin(); it != components.end(); ++it) {
            // for (auto i = 0; i != components.size(); ++i) {
            AddComponentToEntity(entities, entity, (*it));
        }
        
        cout << ", after : " << entity->components.size() << endl;
    }
    static void AddComponentsToEntity(Entity* entity, vector<Component*> components) {
        
        cout << "AddComponentsToEntity components count : " << entity->components.size();
        
        for (auto it = components.begin(); it != components.end(); ++it) {
            // for (auto i = 0; i != components.size(); ++i) {
            AddComponentToEntity(entities, entity, (*it));
        }
        
        cout << ", after : " << entity->components.size() << endl;
    }
    
    static bool EntityByIdHasComponent(string id, string type) {
        bool value = false;
        
        Entity* entity = GetEntityById(entities, id);
        
        for (auto it = entity->components.begin(); it != entity->components.end(); ++it) {
            if ((*it)->type == type) {
                value = true;
            }
        }
        cout << "EntityByIdHasComponent, entity component hasness : " << value << endl;
        
        return value;
    }
    
    static bool EntityHasComponent(Entity* entity, string type) {
        bool value = false;
        
        for (auto it = entity->components.begin(); it != entity->components.end(); ++it) {
            if ((*it)->type == type) {
                value = true;
            }
        }
        cout << "EntityHasComponent, entity component hasness : " << value << endl;
        
        return value;
    }
};