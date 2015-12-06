//
//  LifecycleController.cpp
//  cppTests
//
//  Created by shum on 06.12.15.
//
//

#include "LifecycleController.h"

void LifecycleController::tick(Entity* entity, float delta) {
    if (EntityManager::entityHasComponent(entity, LIFECYCLE_COMPONENT)) {
        LifecycleComponent* lifecycle = static_cast<LifecycleComponent* >(EntityManager::getComponentByTypeFromEntity(entity, LIFECYCLE_COMPONENT));
        SkillReleaseComponent* skill_release = static_cast<SkillReleaseComponent* >(EntityManager::getComponentByTypeFromEntity(entity, SKILL_RELEASE_COMPONENT));
        
        skill_release->updateSkills(entity, delta);
    }
}
