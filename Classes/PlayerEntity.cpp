//
//  PlayerEntity.cpp
//  cppTests
//
//  Created by shum on 12.10.15.
//
//

#include "PlayerEntity.h"

vector<MainComponent*> PlayerEntity::static_components = {
    new MotionComponent(0, 0, 170),
    new PositionComponent(200, 300, 1),
    new GravityComponent(1.4f, 1.1f, 0),
    new ControlsComponent(),
    new JumpingComponent(),
    new ActiveCollisionComponent("player", {"player", "block"}),
    new RangedAttackComponent(30.0f, 10),
    new AnimationComponent({
        { {},               new AnimationContainer(ANIMATION_WARRIOR_REST, 6, 0.3, "sprite") },
        { { MOTION_STATE }, new AnimationContainer(ANIMATION_DWARF_MOTION, 8, 0.1, "dwarf_motion") }
    })
};