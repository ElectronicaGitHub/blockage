//
//  StoneEntity.cpp
//  cppTests
//
//  Created by shum on 12.10.15.
//
//

#include "StoneEntity.h"

vector<MainComponent*> StoneEntity::static_components = {
    new GravityComponent(-1)
};