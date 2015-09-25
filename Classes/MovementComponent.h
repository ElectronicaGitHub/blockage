//
//  MovementComponent.h
//  cppTests
//
//  Created by Philip Antonov on 25.09.15.
//
//

#ifndef __cppTests__MovementComponent__
#define __cppTests__MovementComponent__

#include <stdio.h>
#include "Component.h"

class MovementComponent : public MainComponent
{
public:
    string type = "MovementComponent";
    pair<int, int> coords;
    MovementComponent(pair<int,int> _c);
    ~MovementComponent();
};

#endif /* defined(__cppTests__MovementComponent__) */
