//
//  main.cpp
//  Apuntadores
//
//  Created by Daniel on 22/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Moto.h"

#define C 4
#define F 5

int main(int argc, const char * argv[])
{

    
    int numero = 100;
    int * intpntr = &numero;
    
    std::cout<<"Numero = "<<numero<<"\nIntptr = "<<intpntr<<"\n&numero = "<<&numero<<"\n&intptr = "<<&intpntr<<"\n*intptr = "<<*intpntr<<std::endl;
    
    //new y delete, new[] delete[]
    //usan malloc y free respectivamente
    
    int const N = 10;
    int * const numeros = new int[N];
    //lo mismo que: int numero[N]
    
    for (int i = 0; i < N; i++){
        numeros[i] = i;
    }
    
    int * final = numeros+N;
    std::cout<<"nuermos = "<< numeros<<std::endl;
    std::cout<<"&nuermos[0] = "<< &numeros[0] <<std::endl;
    std::cout<<"final = "<< final<<std::endl;
    
    for (int * aux = numeros; aux < final; ++aux){
        std::cout<< aux << " = " << *aux <<std::endl;
    }
    
    delete [] numeros;
    
    std::cout<<std::endl<<"-------Taller--------\n";
    
    Auto ** taller = new Auto * [2];
    *(taller) = new Moto();
    *(taller + 1) = new Auto();
    
    Auto ** fin = taller+2;
    for (Auto ** aux = taller; aux < fin; ++aux)
    {
        std::cout<< **aux;
        (*aux)->Corre();
    }
    delete *(taller+1);
    delete *taller;
    delete [] taller;
    
    srand((int)time(NULL));
    
    
    
    return 0;
}

