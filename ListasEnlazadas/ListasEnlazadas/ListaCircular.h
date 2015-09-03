//
//  ListaCircular.h
//  ListasEnlazadas
//
//  Created by Daniel on 06/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __ListasEnlazadas__ListaCircular__
#define __ListasEnlazadas__ListaCircular__

#include <iostream>
#include "ListaEnlazada.h"

template <class T>
class ListaCircular: public ListaEnlazada<T>{
    virtual void insertAt(T,int);
    int tamano = 0;
    Nodo<T>* inicio = nullptr;
    
};


template <class T>
void ListaCircular<T>::insertAt(T value, int pos){
    if(pos < 0 || pos > tamano){
        return;
    }
    
    // Insertar al inicio de la lista
    if(pos ==0){
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo ->setSiguiente(inicio);
        inicio = nuevo;
    }
    else{
        Nodo<T> * prev = ListaEnlazada<T>::Prev(pos);
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(prev->getSiguiente());
        prev->setSiguiente(nuevo);
    }
    ++tamano;
}

#endif /* defined(__ListasEnlazadas__ListaCircular__) */
