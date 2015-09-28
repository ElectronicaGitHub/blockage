//
//  Component.h
//  cppTests
//
//  Created by Philip Antonov on 25.09.15.
//
//

#ifndef __cppTests__Component__
#define __cppTests__Component__

#include <stdio.h>
using namespace std;

class MainComponent
{
public:
    string type;
    MainComponent() {};
    MainComponent(string _type) {
        type = _type;
    };
    ~MainComponent() {};
};

#endif /* defined(__cppTests__Component__) */
