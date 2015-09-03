//
//  main.cpp
//  Arboles
//
//  Created by Daniel on 20/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ArbolBinario.h"

int main(int argc, const char * argv[]) {
    
    ArbolBinario<int> * numeros = new ArbolBinario<int>();
    
    numeros->insert(1, nullptr);
    numeros->insert(2, numeros->getRaiz());
    numeros->insert(3, numeros->getRaiz());
    
//    numeros->insert(16, 2);
//    numeros->insert(29, 3);
//    numeros->insert(34, 16);
//    
//    numeros->insert(1, 34);
    
    numeros->preOrden(numeros->getRaiz());
    std::cout<<std::endl;
    numeros->inOrden(numeros->getRaiz());
    std::cout<<std::endl;
    numeros->postOrden(numeros->getRaiz());
    std::cout<<std::endl;
    
    std::cout<<*numeros<<std::endl;
    
    std::cout<<*numeros->suma();
    
    // Busqueda
    NodoB<int> * encontrar = numeros->buscar(4);
    if (encontrar) {
        std::cout<<"El nodo si existe"<<std::endl;
    }
    
    
    NodoB<int> * suma_ineficiente = numeros->suma();
    
    std::cout<<" SUMA = "<<*suma_ineficiente<<std::endl;
    
    int suma_eficiente = numeros->acumular(numeros->getRaiz());
    std::cout<<"Eficiente: "<<suma_eficiente << std::endl;
    
    delete suma_ineficiente;
    delete numeros;
    return 0;
}
