//
//  main.cpp
//  Cola
//
//  Created by Daniel on 13/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Cola.h"

#define N 3

int main(int argc, const char * argv[]) {
    Cola<int> * num = new Cola<int>();
    
    num->enQue(3);
    num->enQue(6);
    num->enQue(10);
    
    std::cout<< *num;
    
    
    Cola<Cola<int> *> * prioridades = new Cola<Cola<int> *>();
    
    
    
    
    delete num;
    return 0;
}
