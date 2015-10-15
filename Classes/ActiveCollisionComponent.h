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

enum CollisionType {
    COL_TOP, COL_BOTTOM, COL_LEFT, COL_RIGHT
};

class ActiveCollisionComponent : public MainComponent {
public:
    ComponentType type = ACTIVE_COLLISION_COMPONENT;
    string entity_type;
    vector<string> collide_with;
    map<CollisionType, bool> collision = {
        { COL_TOP, false },
        { COL_BOTTOM, false },
        { COL_LEFT, false },
        { COL_RIGHT, false }
    };
    ActiveCollisionComponent(string _entity_type, vector<string> _collide_with) : MainComponent(ACTIVE_COLLISION_COMPONENT) {
        entity_type = _entity_type;
        collide_with = _collide_with;
    };
    ActiveCollisionComponent() {};
};

#endif /* defined(__cppTests__ActiveCollisionComponent__) */
