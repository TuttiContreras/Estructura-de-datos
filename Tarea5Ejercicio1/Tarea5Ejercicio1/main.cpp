//
//  main.cpp
//  Tarea5Ejercicio1
//
//  Created by Daniel on 13/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ArbolBinario.h"

template <class T>
ArbolBinario<T> * arbolSumas(ArbolBinario<T>* original);
template <class T>
void arbolSumas(ArbolBinario<T>* original, NodoB<T>* papa, NodoB<T>* father);

int main(int argc, const char * argv[]) {
    
    ArbolBinario<int> * numeros = new ArbolBinario<int>;
    
    numeros->insert(3, nullptr);
    numeros->insert(5, 3);
    numeros->insert(4, 3);
    numeros->insert(1, 5);
    
    std::cout<<*numeros;
    std::cout<<std::endl;
    std::cout<<"Arbol de sumas: "<<std::endl;
    std::cout<<*arbolSumas(numeros);
    delete numeros;
    return 0;
}

template <class T>
ArbolBinario<T> * arbolSumas(ArbolBinario<T>* original){
    ArbolBinario<T>* nuevo = new ArbolBinario<T>(original->suma());
    arbolSumas(original, nuevo->getRaiz(), original->getRaiz());
    return nuevo;
}

template <class T>
void arbolSumas(ArbolBinario<T>* original, NodoB<T>* papa, NodoB<T>* father){
    if(father->getIzquierdo()){
        papa->setIzquierdo(original->suma(father->getIzquierdo()));
        arbolSumas(original, papa->getIzquierdo(), father->getIzquierdo());
    }
    if(father->getDerecho()){
        papa->setDerecho(original->suma(father->getDerecho()));
        arbolSumas(original, papa->getDerecho(), father->getDerecho());
    }
}