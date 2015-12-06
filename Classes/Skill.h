//
//  Skill.h
//  cppTests
//
//  Created by shum on 18.11.15.
//
//

#ifndef __cppTests__Skill__
#define __cppTests__Skill__

#include <stdio.h>
#include "State.h"
#include "MainComponent.h"

enum SkillName {
    RANGED_ATTACK_LV1_SKILL
};

class Skill : public MainComponent
{
public:
    EventType event_type;
    
    Skill(State* state)
        : MainComponent(SKILL, state)
        {}
    virtual ~Skill() = 0;
    
    virtual void release(Entity* entity) = 0;
};


#endif /* defined(__cppTests__Skill__) */
