//
//  ImageStorage.cpp
//  cppTests
//
//  Created by Philip Antonov on 26.09.15.
//
//

#include "ImageStorage.h"

string ImageStorage::getImage(string key) {
    return imageResources.find(key)->second;
}
