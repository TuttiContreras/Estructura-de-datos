//
//  Nodo.h
//  listaDoble
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __listaDoble__Nodo__
#define __listaDoble__Nodo__

#include <iostream>

template <class T> class Nodo;
template <class T>
std::ostream & operator <<(std::ostream &, Nodo<T> &);

template <class T>
class Nodo{
private:
    T info;
    Nodo<T> * siguiente;
    Nodo<T> * anterior;
public:
    Nodo();
    Nodo(T info);
    
    T getInfo();
    void setInfo(T value);
    
    Nodo<T>* getSiguiente();
    void setSiguiente(Nodo<T> * value);
    
    Nodo<T>* getAnterior();
    void setAnterior(Nodo<T> * value);
    
    friend std::ostream & operator << <>(std::ostream &, Nodo<T> &);
};

template <class T>
Nodo<T>::Nodo(){
    this ->siguiente = nullptr;
    this ->anterior = nullptr;
}

template <class T>
Nodo<T>::Nodo(T info){
    this-> info = info;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

template <class T>
T Nodo<T>::getInfo(){
    return info;
}

template <class T>
void Nodo<T>::setInfo(T value){
    info = value;
}

template <class T>
Nodo<T>* Nodo<T>::getSiguiente(){
    return siguiente;
}

template <class T>
void Nodo<T>::setSiguiente(Nodo<T> *value){
    siguiente = value;
}

template <class T>
Nodo<T>* Nodo<T>::getAnterior(){
    return anterior;
}

template <class T>
void Nodo<T>::setAnterior(Nodo<T> *value){
    anterior = value;
}


template <class T>
std::ostream & operator <<(std::ostream & os, Nodo<T> & nodo){
    os<< nodo.info;
    return os;
}

#endif /* defined(__listaDoble__Nodo__) */
