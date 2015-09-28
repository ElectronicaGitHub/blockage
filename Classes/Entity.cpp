//
//  Entity.cpp
//  cppTests
//
//  Created by Philip Antonov on 26.09.15.
//
//

#include "Entity.h"

Entity::Entity(string _id) {
    id = _id;
}
Entity::Entity(string _id, vector<MainComponent *> _comp) {
    id = _id;
    components = _comp;
};
Entity::~Entity() {};