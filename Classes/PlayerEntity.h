//
//  PlayerEntity.h
//  cppTests
//
//  Created by shum on 12.10.15.
//
//

#ifndef __cppTests__PlayerEntity__
#define __cppTests__PlayerEntity__

#include <stdio.h>
#include "Entity.h"

using namespace std;

class PlayerEntity : public Entity
{
public:
    PlayerEntity() : Entity("player", {}){}
    ~PlayerEntity(){}
    
private:
    static vector<MainComponent*> static_components;
    
protected:
    vector<MainComponent*> getStaticComponents() {
        return static_components;
    }
    void addStaticComponent(MainComponent* component) {
        static_components.push_back(component);
    }
};

#endif /* defined(__cppTests__PlayerEntity__) */
