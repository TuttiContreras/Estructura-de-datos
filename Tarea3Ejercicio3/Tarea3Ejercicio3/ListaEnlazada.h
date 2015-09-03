//
//  ListaEnlazada.h
//  Tarea3Ejercicio3
//
//  Created by Daniel on 07/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea3Ejercicio3__ListaEnlazada__
#define __Tarea3Ejercicio3__ListaEnlazada__

#include <iostream>
#include "Nodo.h"

template <class T>
class ListaEnlazada{
    
public:
    
    Nodo<T>* inicio = nullptr;
    int tamano = 0;
    
    ListaEnlazada();
    ~ListaEnlazada();
    
    
    Nodo<T> * start();
    int size();
    bool empty();
    
    virtual void insertAt(T value, int pos);
    void insertFront(T value);
    void insertBack(T value);
    
    Nodo<T> * deleteAt(int pos);
    Nodo<T> * deleteFront();
    Nodo<T> * deleteBack();
    void clear();
    
    Nodo<T> * search(T value);
    Nodo<T> * searchPrev(T value);
    Nodo<T> * At(int pos);
    Nodo<T> * Prev(int pos);
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, ListaEnlazada<Tn> &);
};

template <class T>
ListaEnlazada<T>::ListaEnlazada(){
    
}
template <class T>
ListaEnlazada<T>::~ListaEnlazada(){
    clear();
}

template <class T>
Nodo<T> * ListaEnlazada<T>::start(){
    return inicio;
}

template <class T>
int ListaEnlazada<T>::size(){
    return tamano;
}

template <class T>
bool ListaEnlazada<T>::empty(){
    return (tamano == 0);
}

template <class T>
void ListaEnlazada<T>::insertAt(T value, int pos){
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
        Nodo<T> * prev = Prev(pos);
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(prev->getSiguiente());
        prev->setSiguiente(nuevo);
    }
    ++tamano;
}

template <class T>
void ListaEnlazada<T>::insertFront(T value){
    insertAt(value, 0);
}

template <class T>
void ListaEnlazada<T>::insertBack(T value){
    insertAt(value, tamano);
}

template <class T>
Nodo<T> * ListaEnlazada<T>::deleteAt(int pos){
    if(pos < 0 || pos >= tamano){
        return nullptr;
    }
    
    Nodo<T> * borrado = nullptr;
    
    // Borrar al inicio
    if(pos == 0){
        borrado = inicio;
        inicio = inicio->getSiguiente();
    }
    else {// Borrar en cualquier otra pos
        Nodo<T> * prev = Prev(pos);
        borrado = prev->getSiguiente();
        prev->setSiguiente(borrado->getSiguiente());
    }
    
    borrado->setSiguiente(nullptr);
    --tamano;
    
    return borrado;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::deleteFront(){
    return deleteAt(0);
}

template <class T>
Nodo<T> * ListaEnlazada<T>::deleteBack(){
    return deleteAt(tamano-1);
}

template <class T>
void ListaEnlazada<T>::clear(){
    Nodo<T> * aux;
    while(inicio){
        aux = inicio;
        inicio = inicio->getSiguiente();
        delete aux;
    }
    
    tamano = 0;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::search(T value){
    Nodo<T> * aux = inicio;
    while(aux && (aux->getinfo() != value)){
        aux = aux->getSiguiente();
    }
    
    return aux;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::searchPrev(T value){
    Nodo<T> * aux = inicio;
    Nodo<T> * prev = aux;
    while(aux && (aux->getinfo() != value)){
        prev = aux;
        aux = aux->getSiguiente();
    }
    
    return prev;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::At(int pos){
    int i = 0;
    Nodo<T> * aux = nullptr;
    
    if(pos < 0 || pos >= tamano){
        return aux;
    }
    
    aux = inicio;
    while(i < pos){
        aux = aux->getSiguiente();
        ++i;
    }
    
    return aux;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::Prev(int pos){
    int i = 0;
    Nodo<T> * aux = nullptr;
    
    if(pos < 0 || pos > tamano){
        return aux;
    }
    
    aux = inicio;
    while(i < pos -1){
        aux = aux->getSiguiente();
        ++i;
    }
    
    return aux;
}

template <class T>
std::ostream & operator <<(std::ostream & os, ListaEnlazada<T> & lista){
    Nodo<T> * aux = lista.inicio;
    
    while(aux){
        os << *aux <<std::endl;
        aux = aux->getSiguiente();
    }
    
    return os;
}


#endif /* defined(__Tarea3Ejercicio3__ListaEnlazada__) */
