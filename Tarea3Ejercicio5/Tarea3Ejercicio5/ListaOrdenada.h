//
//  ListaOrdenada.h
//  Tarea3Ejercicio5
//
//  Created by Daniel on 09/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea3Ejercicio5__ListaOrdenada__
#define __Tarea3Ejercicio5__ListaOrdenada__

#include <iostream>
#include "ListaEnlazada.h"

template <class T>
class ListaOrdenada : protected ListaEnlazada<T>{
    
public:
    ListaOrdenada();
    ~ListaOrdenada();
    
    void insert(T);
    int getPos(Nodo<T>);
    int getTamano();
    int size();
    void vaciar();
    
    Nodo<T> * deleteAt(int pos);
    Nodo<T> * At(int pos);
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, ListaOrdenada<Tn> &);
    
};

template <class T>
ListaOrdenada<T>::ListaOrdenada():ListaEnlazada<T>(){
    
}

template <class T>
ListaOrdenada<T>::~ListaOrdenada(){
    this->clear();
}

template <class T>
void ListaOrdenada<T>::insert(T value){
    Nodo<T> * nuevo = new Nodo<T>(value);
    this->insertAt(value, getPos(*nuevo));
    delete nuevo;
}

template <class T>
int ListaOrdenada<T>::size(){
    this->size();
}

//template <class T>
//void ListaOrdenada<T>::clear(){
//    this->clear();
//}

template <class T>
int ListaOrdenada<T>::getPos(Nodo<T> n){
    Nodo<T> * aux = this->inicio;
    int i = 0;
    while (aux){
        if(n < *aux){
            return i;
        }
        ++i;
        aux = aux->getSiguiente();
    }
    return i;
}

template <class T>
std::ostream & operator <<(std::ostream & os, ListaOrdenada<T> & n){
    Nodo<T> * aux = n.inicio;
    
    while(aux){
        os << *aux << ", ";
        aux = aux->getSiguiente();
    }
    os << std::endl;
    return os;
}

template <class T>
int ListaOrdenada<T>::getTamano(){
    return this->tamano;
}

template <class T>
void ListaOrdenada<T>::vaciar(){
    this->clear();
}

template <class T>
Nodo<T> * ListaOrdenada<T>::At(int pos){
    return ListaEnlazada<T>::At(pos);
}

template <class T>
Nodo<T> * ListaOrdenada<T>::deleteAt(int pos){
    return ListaEnlazada<T>::deleteAt(pos);
}


#endif /* defined(__Tarea3Ejercicio5__ListaOrdenada__) */
