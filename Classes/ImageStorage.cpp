//
//  ImageStorage.cpp
//  cppTests
//
//  Created by Philip Antonov on 26.09.15.
//
//

#include "ImageStorage.h"

map<ImageName, string> ImageStorage::imageResources= {
    {IMAGE_WALL, "res/ground3.png"},
    {IMAGE_WALL_DROP, "res/ground_drop.png"},
    {IMAGE_WALL_DRAG, "res/ground_drag.png"},
    {IMAGE_DWARF, "res/dwarf.png"},
    {IMAGE_STONE, "res/stone.png"},
    {IMAGE_BACKGROUND, "res/background.png"},
    
    {ANIMATION_DWARF_MOTION, "res/animations/dwarf_motion.plist"},
    {ANIMATION_WARRIOR_REST, "res/animations/sprites.plist"}
};

string ImageStorage::getImage(ImageName key) {
    return imageResources[key];
}
