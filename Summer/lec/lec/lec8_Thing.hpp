//
//  lec8_inheritance.hpp
//  lec
//
//  Created by Z.Q. Zhang on 2022/6/24.
//

#ifndef lec8_inheritance_hpp
#define lec8_inheritance_hpp

#include <stdio.h>
class Thing {
    int x;
public:
    Thing(int newx=0) :x(newx) {}
    int getx()const;
    void setx(int newx);
};
#endif /* lec8_inheritance_hpp */
