//
//  Entity.h
//  cppTests
//
//  Created by Philip Antonov on 26.09.15.
//
//

#ifndef __cppTests__Entity__
#define __cppTests__Entity__

#include <stdio.h>
#include "MainComponent.h"
#include "PositionComponent.h"
#include "MotionComponent.h"
#include "JumpingComponent.h"
#include "RenderComponent.h"
#include "ControlsComponent.h"
#include "GravityComponent.h"
#include "ActiveCollisionComponent.h"
#include "PassiveCollisionComponent.h"
#include "RangedAttackComponent.h"
#include "ImageStorage.h"
#include "EntityManager.h"

using namespace std;

enum EntityType {
    PLAYER_ENTITY,
    BRICK_ENTITY, STONE_ENTITY
};

class Entity
{
public:
    string id;
    Entity(string _id, vector<MainComponent* > _comp)
        : id(_id)
        , components(_comp)
        {}
    virtual ~Entity(){}
    
    vector<MainComponent*> allComponents(void) {
        vector<MainComponent*> static_components, allComponents;
        static_components = getStaticComponents();
        allComponents.reserve( components.size() + static_components.size() );
        allComponents.insert( allComponents.end(), components.begin(), components.end() );
        allComponents.insert( allComponents.end(), static_components.begin(), static_components.end() );
        return allComponents;
    }
    
protected:
    vector<MainComponent*> components;
    virtual vector<MainComponent*> getStaticComponents() = 0;
    virtual void addStaticComponent(MainComponent* component) = 0;

    friend EntityManager;
};

#endif /* defined(__cppTests__Entity__) */
