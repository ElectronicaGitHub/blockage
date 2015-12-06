//
//  SkillReleaseComponent.h
//  cppTests
//
//  Created by shum on 15.11.15.
//
//

#ifndef __cppTests__SkillReleaseComponent__
#define __cppTests__SkillReleaseComponent__

#include <stdio.h>
#include "MainComponent.h"
#include "Skill.h"

using namespace std;

class SkillReleaseComponent : public MainComponent
{
public:
    map<EventType, Skill*> current_skills = {
        {INPUT_Z, 0}, {INPUT_X, 0}, {INPUT_C, 0}, {INPUT_V, 0}
    };
    ComponentType type = SKILL_RELEASE_COMPONENT;
    SkillReleaseComponent()
    : MainComponent(SKILL_RELEASE_COMPONENT)
    {}
    ~SkillReleaseComponent() {}
    
    void release(Entity* entity, EventType event);
    void setSkill(EventType event, Skill* skill);
    void updateSkills(Entity* entity, float delta);
};

#endif /* defined(__cppTests__SkillReleaseComponent__) */
