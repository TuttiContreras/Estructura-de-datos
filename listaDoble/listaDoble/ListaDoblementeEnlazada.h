//
//  ListaDoblementeEnlazada.h
//  listaDoble
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __listaDoble__ListaDoblementeEnlazada__
#define __listaDoble__ListaDoblementeEnlazada__

#include <iostream>
#include "Nodo.h"

template <class T>
class ListaDoblementeEnlazada{
    
public:
    
    Nodo<T>* inicio = nullptr;
    Nodo<T>* ultimo = nullptr;
    int tamano = 0;
    
    ListaDoblementeEnlazada();
    ~ListaDoblementeEnlazada();
    
    
    Nodo<T> * start();
    int size();
    bool empty();
    
    void insertAt(T value, int pos);
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
    friend std::ostream & operator <<(std::ostream &, ListaDoblementeEnlazada<Tn> &);
};

template <class T>
ListaDoblementeEnlazada<T>::ListaDoblementeEnlazada(){
    
}
template <class T>
ListaDoblementeEnlazada<T>::~ListaDoblementeEnlazada(){
    clear();
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::start(){
    return inicio;
}

template <class T>
int ListaDoblementeEnlazada<T>::size(){
    return tamano;
}

template <class T>
bool ListaDoblementeEnlazada<T>::empty(){
    return (tamano == 0);
}

template <class T>
void ListaDoblementeEnlazada<T>::insertAt(T value, int pos){
    if(pos < 0 || pos > tamano){
        return;
    }
    
    // Insertar al inicio de la lista
    if(pos ==0){
        if(this->tamano == 0){
            Nodo<T> * nuevo = new Nodo<T>(value);
            this->inicio = this->ultimo = nuevo;
            this->inicio->setSiguiente(nuevo);
            this->inicio->setAnterior(nuevo);
        }
        else{
            Nodo<T> * nuevo = new Nodo<T>(value);
            nuevo->setSiguiente(this->inicio);
            nuevo->setAnterior(this->ultimo);
            this->inicio->setAnterior(nuevo);
            this->ultimo->setSiguiente(nuevo);
            this->inicio = nuevo;
        }
        
        
    }
    else if (pos == (this->tamano - 1)) {
        
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(this->ultimo);
        nuevo->setAnterior(this->ultimo->getAnterior());
        this->ultimo->getAnterior()->setSiguiente(nuevo);
        this->ultimo->setAnterior(nuevo);
        
    }
    else if(pos == this->tamano)
    {
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setAnterior(this->ultimo);
        nuevo->setSiguiente(this->inicio);
        this->ultimo->setSiguiente(nuevo);
        this->inicio->setAnterior(nuevo);
        this->ultimo = nuevo;
    }
    else
    { /* Insertar en cualquier otra posición */
        Nodo<T> * anterior = this->At(pos)->getAnterior();
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(anterior->getSiguiente());
        nuevo->setAnterior(anterior);
        anterior->getSiguiente()->setAnterior(nuevo);
        anterior->setSiguiente(nuevo);
    }
    ++tamano;
}

template <class T>
void ListaDoblementeEnlazada<T>::insertFront(T value){
    insertAt(value, 0);
}

template <class T>
void ListaDoblementeEnlazada<T>::insertBack(T value){
    insertAt(value, tamano);
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::deleteAt(int pos){
    if (pos < 0 || pos >= this->tamano) {
        return nullptr;
    }
    
    Nodo<T> * borrado = nullptr;
    
    /* Borra al inicio */
    if (pos == 0) {
        borrado = this->inicio;
        
        if (this->tamano == 1) {
            this->inicio->setSiguiente(nullptr);
            this->inicio->setAnterior(nullptr);
            this->inicio = this->ultimo = nullptr;
        }
        else {
            this->inicio = this->inicio->getSiguiente();
            this->ultimo->setSiguiente(this->inicio);
            this->inicio->setAnterior(this->ultimo);
        }
    }
    else { /* Borrar en cualquier otra posición */
        Nodo<T> * prev = this->At(pos)->getAnterior();
        
        if (prev->getSiguiente() == this->ultimo) {
            this->ultimo = prev;
            borrado = this->ultimo->getSiguiente();
            this->ultimo->setSiguiente(this->inicio);
            this->inicio->setAnterior(this->ultimo);
            borrado->setSiguiente(nullptr);
            borrado->setAnterior(nullptr);
        }
        else
        {
            borrado = prev->getSiguiente();
            borrado->getAnterior()->setSiguiente(borrado->getSiguiente());
            borrado->getSiguiente()->setAnterior(borrado->getAnterior());
            borrado->setSiguiente(nullptr);
            borrado->setAnterior(nullptr);
        }
    }
    --this->tamano;
    return borrado;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::deleteFront(){
    return deleteAt(0);
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::deleteBack(){
    return deleteAt(tamano-1);
}

template <class T>
void ListaDoblementeEnlazada<T>::clear(){
    Nodo<T> * aux;
    while(inicio){
        aux = inicio;
        inicio = inicio->getSiguiente();
        delete aux;
    }
    
    tamano = 0;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::search(T value){
    Nodo<T> * aux = inicio;
    while(aux && (aux->getinfo() != value)){
        aux = aux->getSiguiente();
    }
    
    return aux;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::searchPrev(T value){
    Nodo<T> * aux = inicio;
    Nodo<T> * prev = aux;
    while(aux && (aux->getinfo() != value)){
        prev = aux;
        aux = aux->getSiguiente();
    }
    
    return prev;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::At(int pos){
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
Nodo<T> * ListaDoblementeEnlazada<T>::Prev(int pos){
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
std::ostream & operator <<(std::ostream & os, ListaDoblementeEnlazada<T> & lista){
    Nodo<T> * aux = lista.inicio;
    
    while (aux && aux != lista.ultimo) {
        os << *aux;
        aux = aux->getSiguiente();
    }
    
    if (aux) {
        os << *aux;
    }
    return os;
}


#endif /* defined(__listaDoble__ListaDoblementeEnlazada__) */
