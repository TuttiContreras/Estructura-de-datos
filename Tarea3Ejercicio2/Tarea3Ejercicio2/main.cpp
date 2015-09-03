//
//  main.cpp
//  Tarea3Ejercicio2
//
//  Created by Daniel on 07/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ListaEnlazada.h"


int main(int argc, const char * argv[]) {
    
    int n, m;
    float temp;
    std::cout<<"Escoga el tamano de la primera lista: ";
    std::cin>>n;
    std::cout<<"Escoga el tamano de la segunda lista: ";
    std::cin>>m;
    
    ListaEnlazada<float> * lista1 = new ListaEnlazada<float>();
    ListaEnlazada<float> * lista2 = new ListaEnlazada<float>();
    ListaEnlazada<float> * productos = new ListaEnlazada<float>();
    
    std::cout<<"-----Lista 1: -------"<<std::endl;
    for(int i = 0; i < n; i++){
        std::cout<<"Número "<<i<<": ";
        std::cin>>temp;
        lista1->insertBack(temp);
    }
    
    std::cout<<"-----Lista 2: -------"<<std::endl;
    for(int i = 0; i < m; i++){
        std::cout<<"Número "<<i<<": ";
        std::cin>>temp;
        lista2->insertBack(temp);
    }
    
    for (int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            productos->insertBack((lista2->At(i)->getInfo() * lista1->At(j)->getInfo()));
        }
    }
    std::cout<<"Producto de todos los elementos de la lista 2 por todos los elementos de la lista 1"<<std::endl;
    std::cout<<*productos;
    
    delete lista1;
    delete lista2;
    delete productos;
    
    return 0;
}
