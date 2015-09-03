//
//  main.cpp
//  Tarea5Ejercicio3
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
    
    std::cout<<"Arbol numeros: ";
    std::cout<<*numeros<<std::endl;
    if(numeros->simetrico()){
        std::cout<<"El árbol numeros es simétrico."<<std::endl;
    }
    else{
        std::cout<<"El arbol numeros no es simétrico"<<std::endl;
    }
    
    NodoB<int>* r = new NodoB<int>(3);
    ArbolBinario<int> * simetria = new ArbolBinario<int>(r);
    simetria->insert(5, 3);
    simetria->insert(5, 3);
    simetria->insert(2, simetria->getRaiz()->getIzquierdo());
    simetria->insert(9, simetria->getRaiz()->getIzquierdo());
    simetria->insert(9, simetria->getRaiz()->getDerecho());
    simetria->insert(2, simetria->getRaiz()->getDerecho());
    
    std::cout<<"Arbol simetria: ";
    std::cout<<*simetria<<std::endl;
    if(simetria->simetrico()){
        std::cout<<"El árbol simetria es simétrico."<<std::endl;
    }
    else{
        std::cout<<"El arbol simetria no es simétrico"<<std::endl;
    }
    
    
    delete numeros;
    delete simetria;
    return 0;
}
