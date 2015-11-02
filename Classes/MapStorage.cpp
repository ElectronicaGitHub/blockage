//
//  MapStorage.cpp
//  cppTests
//
//  Created by Philip Antonov on 03.10.15.
//
//

#include "MapStorage.h"

int MapStorage::mapSizeX = 70;
int MapStorage::mapSizeY = 50;

map<EntityType, vector<array<int, 4>>> MapStorage::map = {
    {
        BRICK_ENTITY, {
            {0, 0, 70, 2}, {0, 49, 70, 1}, {0, 2, 1, 47}, {69, 2, 1, 47},
            {1, 6, 40, 1}, {30, 12, 40, 1}, {1, 18, 40, 1}, {30, 24, 40, 1}, {1, 30, 40, 1}
        },
    },
    {
        DROP_BRICK_ENTITY, {
            {29, 24, 1, 1}, {41, 30, 1, 1}
        }
    }
};