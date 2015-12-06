//
//  CharClass.cpp
//  cppTests
//
//  Created by shum on 15.11.15.
//
//

#include "CharClass.h"

map<int,int> CharClass::xp = {
    {1, 0}, {2, 100}, {3, 300}, {4, 800}, {5, 2500}, {6, 7000}, {7, 24000}, {8, 50000},
    {9, 51000}, {10, 52000}, {11, 53000}, {12, 54000}, {13, 55000}, {14, 60000}, {15, 65000}, {16, 70000}
};

int CharClass::getFullHPValue(int level) {
    return hp[level];
}

void CharClass::readClassInfo() {
    hp = {{1, 100}, {2, 110}};
}
