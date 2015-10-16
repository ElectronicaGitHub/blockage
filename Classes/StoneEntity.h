//
//  StoneEntity.h
//  cppTests
//
//  Created by shum on 12.10.15.
//
//

#ifndef __cppTests__StoneEntity__
#define __cppTests__StoneEntity__

#include <stdio.h>
#include "Entity.h"

using namespace std;

class StoneEntity : public Entity
{
public:
    StoneEntity() : Entity("stone" + to_string(rand()), {}){}
    ~StoneEntity(){}
    
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

#endif /* defined(__cppTests__StoneEntity__) */
