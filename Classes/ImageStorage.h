//
//  ImageStorage.h
//  cppTests
//
//  Created by Philip Antonov on 26.09.15.
//
//

#ifndef __cppTests__ImageStorage__
#define __cppTests__ImageStorage__

#include <stdio.h>

using namespace std;

enum ImageName {
    IMAGE_WALL,
    IMAGE_WALL_DROP,
    IMAGE_WALL_DRAG,
    IMAGE_DWARF,
    IMAGE_STONE,
    IMAGE_BACKGROUND,
    
    ANIMATION_DWARF_MOTION,
    ANIMATION_WARRIOR_REST
};

class ImageStorage {
    
private:
    static map<ImageName, string> imageResources;
    
public:
    static string getImage(ImageName key);
};

#endif /* defined(__cppTests__ImageStorage__) */
