//
//  main.cpp
//  Tarea3Ejercicio5
//
//  Created by Daniel on 09/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ListaOrdenada.h"

int main(int argc, const char * argv[]) {
    ListaOrdenada<int> * lista1 = new ListaOrdenada<int>();
    ListaOrdenada<int> * lista2 = new ListaOrdenada<int>();
    
    srand((int)time(NULL));
    int num;
    
    for (int i = 0; i < 100; ++i){
        num = rand()% 1501;
        lista1->insert(num);
    }
    
    for (int j = 99; j> 0; --j){
        if(lista1->At(j)->getInfo() <= 1000){
            break;
        }
        else{
            lista2->insert(lista1->At(j)->getInfo());
        }
    }
    
    std::cout<<"---------Lista completa-----------\n";
    std::cout<<*lista1<<std::endl;
    std::cout<<"---------Lista con numeros mayores a 1000\n";
    std::cout<<*lista2<<std::endl;
    
    delete lista1;
    delete lista2;
    
    return 0;
}
