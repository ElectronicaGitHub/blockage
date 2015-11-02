//
//  MapStorage.h
//  cppTests
//
//  Created by Philip Antonov on 03.10.15.
//
//

#ifndef __cppTests__MapStorage__
#define __cppTests__MapStorage__

#include <stdio.h>
#include <array>
#include "Entity.h"

using namespace std;

class MapStorage {
public:
    static int mapSizeX, mapSizeY;
    static map<EntityType, vector<array<int, 4>>> map;
};

#endif /* defined(__cppTests__MapStorage__) */
