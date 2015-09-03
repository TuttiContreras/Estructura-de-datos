//
//  main.cpp
//  Pila
//
//  Created by Daniel on 09/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Pila.h"

int main(int argc, const char * argv[]) {
    
    Pila<int> * pila = new Pila<int>();
    
    pila->push(1);
    pila->push(2);
    
    std::cout<< "tamano de la pila: " << pila->size() <<std::endl;
    
    
    return 0;
}
