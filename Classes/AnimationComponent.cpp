//
//  AnimationComponent.cpp
//  cppTests
//
//  Created by shum on 01.11.15.
//
//

#include "AnimationComponent.h"
#include "iostream"

string AnimationComponent::getAnimation(vector<StateType> states) {
    
    for (auto it = animationMap.begin(); it != animationMap.end(); ++it) {
        
        int count_from = it->first.size();
        int count = 0;
        
        for (int j = 0; j < it->first.size(); ++j) {
            
            StateType from = it->first[j];
            
            for (int k = 0; k < states.size(); ++k) {
                
                StateType to = states[k];
                if (from == to) count++;
            }
        }
        
        if (count_from == count) {
            return it->second;
        }
    }
    return "stay";
};
