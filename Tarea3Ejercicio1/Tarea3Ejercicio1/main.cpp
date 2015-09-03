//
//  main.cpp
//  Tarea3Ejercicio1
//
//  Created by Daniel on 07/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ListaEnlazada.h"
#define N 100

int main(int argc, const char * argv[]) {
    
    srand((int) time(NULL));
    int num;
    ListaEnlazada<int> * lista = new ListaEnlazada<int>();
    
    for(int i = 0; i < N; ++i){
        num = rand() %100;
        lista->insertBack(num);
    }
    
    std::cout<<"Orden original: "<<std::endl;
    std::cout<<*lista<<std::endl;
    
    std::cout<<"Orden inverso: "<<std::endl;
    for(int i = N-1; i >= 0; --i){
        std::cout<< * (lista->At(i))<<", ";
    }
    
    delete lista;
    return 0;
}
