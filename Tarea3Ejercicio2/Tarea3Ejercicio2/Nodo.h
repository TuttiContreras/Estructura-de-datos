//
//  Nodo.h
//  Tarea3Ejercicio2
//
//  Created by Daniel on 07/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea3Ejercicio2__Nodo__
#define __Tarea3Ejercicio2__Nodo__

#include <iostream>

template <class T> class Nodo;
template <class T>
std::ostream & operator <<(std::ostream &, Nodo<T> &);

template <class T>
class Nodo{
private:
    T info;
    Nodo<T> * siguiente;
public:
    Nodo();
    Nodo(T info);
    
    T getInfo();
    void setInfo(T value);
    
    Nodo<T>* getSiguiente();
    void setSiguiente(Nodo<T> * value);
    
    friend std::ostream & operator << <>(std::ostream &, Nodo<T> &);
};

template <class T>
Nodo<T>::Nodo(){
    this ->siguiente = nullptr;
}

template <class T>
Nodo<T>::Nodo(T info){
    this-> info = info;
    this->siguiente = nullptr;
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
std::ostream & operator <<(std::ostream & os, Nodo<T> & nodo){
    os<< nodo.info;
    return os;
}


#endif /* defined(__Tarea3Ejercicio2__Nodo__) */
