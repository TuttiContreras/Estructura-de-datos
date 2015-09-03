//
//  Pila.h
//  Pila
//
//  Created by Daniel on 09/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Pila__Pila__
#define __Pila__Pila__

#include <iostream>
#include "../../ListasEnlazadas/ListasEnlazadas/ListaEnlazada.h"

template <class T>
class Pila : protected ListaEnlazada<T>{
public:
    Pila();
    ~Pila();
    
    void push(T value);
    
    int size();
    bool empty();
    
    Nodo<T> * pop();
    Nodo<T> * top();
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, Pila<Tn> & pila);
    
};

template <class T>
Pila<T>::Pila() : ListaEnlazada<T>(){
    
}

template <class T>
Pila<T>::~Pila(){
    this->clear();
}

template <class T>
bool Pila<T>::empty(){
    return ListaEnlazada<T>::empty();
}

template <class T>
int Pila<T>::size(){
    return ListaEnlazada<T>::size();
}

template <class T>
void Pila<T>::push(T value){
    this->insertFront(value);
}

template <class T>
Nodo<T> * Pila<T>::pop(){
    return this->start();
}

template <class T>
std::ostream & operator <<(std::ostream & os, Pila<T> & pila){
    
    Nodo<T> * aux = pila.inicio;
    while (aux){
        os << *aux << std::endl;
        aux = aux->getSiguiente();
    }
}

#endif /* defined(__Pila__Pila__) */
