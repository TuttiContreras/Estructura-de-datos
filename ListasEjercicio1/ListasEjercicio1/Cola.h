//
//  Cola.h
//  ListasEjercicio1
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __ListasEjercicio1__Cola__
#define __ListasEjercicio1__Cola__

#include <iostream>
#include "listaEnlazada.h"

template <class T>
class Cola : protected ListaEnlazada<T>{
public:
    int prioridad;
    
    Cola();
    Cola(int);
    ~Cola();
    Nodo<T> * deQue();
    void enQue(T value);
    Nodo<T> * inicio;
    Nodo<T> * ultimo;
    
    void clear();
    int size();
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, Cola<Tn> &);
};

template <class T>
Cola<T>::Cola() : ListaEnlazada<T>(){
    
}

template<class T>
Cola<T>::Cola(int p){
    prioridad = p;
}

template <class T>
Cola<T>::~Cola<T>(){
    clear();
}
template <class T>
int Cola<T>::size(){
    return ListaEnlazada<T>::size();
}

template <class T>
Nodo<T> * Cola<T>::deQue(){
    return this->deleteFront();
}

template <class T>
void Cola<T>::enQue(T value){
    this->insertBack(value);
}

template <class T>
void Cola<T>::clear(){
    ListaEnlazada<T>::clear();
}

template <class T>
std::ostream & operator <<(std::ostream & os, Cola<T> & lista){
    for (auto p : lista)
    {
        os << p << std::endl;
    }
    
    return os;
}

#endif /* defined(__ListasEjercicio1__Cola__) */
