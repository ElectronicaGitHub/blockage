//
//  Entity.h
//  cppTests
//
//  Created by Philip Antonov on 25.09.15.
//
//

#ifndef __cppTests__Entity__
#define __cppTests__Entity__

#include <stdio.h>
#include "string"
#include "MainComponent.h"

using namespace std;

class Entity
{
public:
    string id;
    vector<MainComponent *> components;
    Entity(string _id);
    Entity(string _id, vector<MainComponent *> _comp);
    ~Entity();
};

#endif /* defined(__cppTests__Entity__) */
