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

class ImageStorage {
    
    
public:
    ImageStorage() {};
    ~ImageStorage() {};

private:
    map<string, string> imageResources = {
        {"wall", "res/wall.png"},
        {"dwarf", "res/dwarf.png"}
    };
    
public:
    string getImage(string key);
};

#endif /* defined(__cppTests__ImageStorage__) */
