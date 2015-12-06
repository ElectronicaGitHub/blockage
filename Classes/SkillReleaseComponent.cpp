//
//  SkillReleaseComponent.cpp
//  cppTests
//
//  Created by shum on 15.11.15.
//
//

#include "SkillReleaseComponent.h"

void SkillReleaseComponent::release(Entity* entity, EventType event) {
    if (current_skills[event]) {
        current_skills[event]->release(entity);
    }
}

void SkillReleaseComponent::setSkill(EventType event, Skill* skill) {
    current_skills[event] = skill;
}

void SkillReleaseComponent::updateSkills(Entity* entity, float delta) {
    for (auto i = current_skills.begin(); i != current_skills.end(); i++) {
        if (i->second) {
            i->second->updateState(entity, delta);
        }
    }
}