//
//  MotionController.hpp
//  cppTests
//
//  Created by Gennadiy Shumilkin on 06.10.15.
//
//

#ifndef MotionController_hpp
#define MotionController_hpp

#include <stdio.h>
#include "EntityManager.h"
#include "MotionComponent.h"
#include "PositionComponent.h"
#include "GravityComponent.h"
#include "ActiveCollisionComponent.h"

using namespace std;

class MotionController {
public:
    MotionController() {};
    ~MotionController() {};
    
    void tick(float delta);
};

#endif /* MotionController_hpp */
