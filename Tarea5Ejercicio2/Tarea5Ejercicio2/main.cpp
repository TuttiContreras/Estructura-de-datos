//
//  main.cpp
//  Tarea5Ejercicio2
//
//  Created by Daniel on 13/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ArbolBinario.h"

int main(int argc, const char * argv[]) {
    
    ArbolBinario<int> * numeros = new ArbolBinario<int>;
    
    numeros->insert(3, nullptr);
    numeros->insert(5, 3);
    numeros->insert(4, 3);
    numeros->insert(1, 5);
    numeros->insert(2, 5);
    
    std::cout<<*numeros;
    std::cout<<std::endl<<"Reflexion:"<<std::endl;
    std::cout<<*(numeros->getReflexion());
    delete numeros;
    return 0;
}
