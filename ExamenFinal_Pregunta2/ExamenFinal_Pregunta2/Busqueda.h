//
//  Busqueda.h
//  AlgoritmosDeBusqueda
//
//  Created by Daniel on 28/08/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __AlgoritmosDeBusqueda__Busqueda__
#define __AlgoritmosDeBusqueda__Busqueda__

#include <iostream>


template <class T>
class Busqueda{
public:
    Busqueda();
    int busquedaSequencial(T a[], T buscar, int N);
    int busquedaBinaria(T a[], T buscar, int inicio, int final);
    
};

template <class T>
Busqueda<T>::Busqueda(){
    
}

template <class T>
int Busqueda<T>::busquedaBinaria(T a[], T buscar, int inicio, int final){
    
    if(inicio > final){
        return -1;
    }
    else{
        int i = (inicio + final)/2;
        if(a[i] == buscar){
            return i;
        }
        else if(buscar > a[i]){
            return busquedaBinaria(a, buscar, i +1, final);
        }
        else{
            return busquedaBinaria(a, buscar, inicio, i-1);
        }
        
    }
    return -1;
    
}

template <class T>
int Busqueda<T>::busquedaSequencial(T a[], T buscar, int N){
    int i = 0;
    bool encontrado = false;
    while((i < N) && (!encontrado)){
        if (a[i] == buscar){
            encontrado = true;
            return i;
        }
        ++i;
    }
    return -1;
}



#endif /* defined(__AlgoritmosDeBusqueda__Busqueda__) */
