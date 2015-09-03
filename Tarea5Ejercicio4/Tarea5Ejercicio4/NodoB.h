//
//  NodoBB.h
//  Arboles
//
//  Created by Daniel on 20/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Arboles__NodoBB__
#define __Arboles__NodoBB__

#include <iostream>

template <class T> class NodoB;
template <class T>
std::ostream & operator <<(std::ostream &, NodoB<T> &);

template <class T>
class NodoB{
private:
    T info;
    
    NodoB<T> * izquierdo;
    NodoB<T> * derecho;
    NodoB<T> * padre;
    
public:
    NodoB();
    NodoB(T info);
    ~NodoB();
    
    T getInfo();
    void setInfo(T value);
    
    
    NodoB<T>* getIzquierdo();
    NodoB<T>* getDerecho();
    NodoB<T>* getPadre();
    void setIzquierdo(NodoB<T> * value);
    void setDerecho(NodoB<T> * value);
    void setPadre(NodoB<T> * value);
    
    friend std::ostream & operator << <>(std::ostream &, NodoB<T> &);
};

template <class T>
NodoB<T>::NodoB(){
    this->izquierdo = this->derecho = this->padre = nullptr;
}

template <class T>
NodoB<T>::NodoB(T info){
    this-> info = info;
    this->izquierdo = this->derecho = this->padre = nullptr;
}

template <class T>
NodoB<T>::~NodoB(){
    izquierdo = derecho = padre = nullptr;
}

template <class T>
T NodoB<T>::getInfo(){
    return info;
}

template <class T>
void NodoB<T>::setInfo(T value){
    info = value;
}

template <class T>
NodoB<T>* NodoB<T>::getIzquierdo(){
    return izquierdo;
}

template <class T>
NodoB<T>* NodoB<T>::getDerecho(){
    return derecho;
}

template <class T>
NodoB<T>* NodoB<T>::getPadre(){
    return padre;
}

template <class T>
void NodoB<T>::setIzquierdo(NodoB<T> *value){
    izquierdo = value;
}

template <class T>
void NodoB<T>::setDerecho(NodoB<T> *valor){
    derecho = valor;
}

template <class T>
void NodoB<T>::setPadre(NodoB<T> *value){
    padre = value;
}

template <class T>
std::ostream & operator <<(std::ostream & os, NodoB<T> & NodoB){
    os << NodoB.info;
    return os;
}


#endif /* defined(__Arboles__NodoBBB__) */
