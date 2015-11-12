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
    new PositionComponent(100, 100, 1),
    new GravityComponent(1.4f, 1.1f, 0),
    new ControlsComponent(),
    new JumpingComponent(),
//    new ActiveCollisionComponent("player", {"player", "block"}),
    new RangedAttackComponent(30.0f, 10),
    new AnimationComponent({
        { {},               "stay" },
        { { MOTION_STATE }, "walk" }
    })
};