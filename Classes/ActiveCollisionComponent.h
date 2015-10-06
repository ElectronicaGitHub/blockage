//
//  ActiveCollisionComponent.h
//  cppTests
//
//  Created by Philip Antonov on 06.10.15.
//
//

#ifndef __cppTests__ActiveCollisionComponent__
#define __cppTests__ActiveCollisionComponent__

#include <stdio.h>
#include "MainComponent.h"

using namespace std;

class ActiveCollisionComponent : public MainComponent {
public:
    string type = "ActiveCollisionComponent";
    string entity_type;
    vector<string> collide_with;
    map<string, bool> collision = {
        { "top", false },
        { "bottom", false },
        { "left", false },
        { "right", false }
    };
    ActiveCollisionComponent(string _entity_type, vector<string> _collide_with) : MainComponent("ActiveCollisionComponent") {
        entity_type = _entity_type;
        collide_with = _collide_with;
    };
    ActiveCollisionComponent() {};
};

#endif /* defined(__cppTests__ActiveCollisionComponent__) */
