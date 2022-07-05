//
//  main.cpp
//  DEMO_DAY_01_TIME
//
//  Created by Jingtao Fan on 2022/6/27.
//

#include <iostream>
#include "Time.hpp"


int main(int argc, const char * argv[]) {
    Time t1{1, 2, 3};
    Time t2{4, 5, 6};
    t1.Set(13, 20, 38);
    Time* pT = new Time{};
    delete pT;
    pT = nullptr;
    
    Time* Array = new Time[10];
    delete[] Array;
    Array = nullptr;
    
    std::cout << t1.Hour << std::endl;
    t2.Set(15, 40, 17);
    return 0;
}
