//
//  BrickEntity.h
//  cppTests
//
//  Created by shum on 15.10.15.
//
//

#ifndef __cppTests__BrickEntity__
#define __cppTests__BrickEntity__

#include <stdio.h>
#include "Entity.h"

using namespace std;

class BrickEntity : public Entity
{
public:
    BrickEntity() : Entity("brick", {}){}
    ~BrickEntity(){}
    
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

#endif /* defined(__cppTests__BrickEntity__) */
