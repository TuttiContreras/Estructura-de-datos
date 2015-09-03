//
//  main.cpp
//  listaDoble
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ListaDoblementeEnlazada.h"

int main(int argc, const char * argv[]) {
    
    ListaDoblementeEnlazada<int> * numeros = new ListaDoblementeEnlazada<int>;
    numeros->insertBack(1);
    numeros->insertBack(2);
    
    std::cout<< *numeros->ultimo->getAnterior();
    
    std::cout<<*numeros;
    
    
    return 0;
}
