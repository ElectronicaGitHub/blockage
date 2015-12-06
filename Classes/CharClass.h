//
//  CharClass.h
//  cppTests
//
//  Created by shum on 15.11.15.
//
//

#ifndef __cppTests__CharClass__
#define __cppTests__CharClass__

#include <stdio.h>

using namespace std;

enum ClassName {
    MELEE_APPRENTICE, RANGE_APPRENTICE, WORKER
};

class CharClass
{
public:
    ClassName name;
    CharClass(ClassName _name)
    : name(_name)
    {
        readClassInfo();
    }
    ~CharClass();
    
    int getFullHPValue(int level);
    
private:
    map<int,int> hp;
    static map<int, int> xp;
    
    void readClassInfo();
};

#endif /* defined(__cppTests__CharClass__) */
