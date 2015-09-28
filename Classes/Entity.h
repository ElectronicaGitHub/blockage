//
//  Entity.h
//  cppTests
//
//  Created by Philip Antonov on 26.09.15.
//
//

#ifndef __cppTests__Entity__
#define __cppTests__Entity__

#include <stdio.h>
#include "MainComponent.h"

using namespace std;

class Entity
{
public:
    string id;
    vector<MainComponent *> components;
    Entity(string _id) {
        id = _id;
    }
    Entity(string _id, vector<MainComponent *> _comp) {
        id = _id;
        components = _comp;
    };
    ~Entity() {};
};

#endif /* defined(__cppTests__Entity__) */
