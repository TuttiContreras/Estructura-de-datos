//
//  ListaDoblementeEnlazada.h
//  Tarea4Ejercicio4
//
//  Created by Daniel on 18/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea4Ejercicio4__ListaDoblementeEnlazada__
#define __Tarea4Ejercicio4__ListaDoblementeEnlazada__

#include <iostream>
#include "Nodo.h"

template <class T>
class ListaDoblementeEnlazada {
protected:
    Nodo<T> * inicio = nullptr;
    int tamano = 0;
    
    /* Iterador de la lista */
    class Iterator {
        ListaDoblementeEnlazada<T> * data;
        int position;
    public:
        Iterator(ListaDoblementeEnlazada<T> * _data, int _position):data(_data),position(_position) {}
        
        Nodo<T> operator*() const { return *(data->At(position)); }
        const Iterator& operator++() { ++position; return *this; }
        bool operator!=(const Iterator& it) const { return position != it.position; }
    };
    
public:
    ListaDoblementeEnlazada();
    ~ListaDoblementeEnlazada();
    
    Nodo<T> * start();
    virtual int size();
    virtual bool empty();
    
    virtual void insertAt(T value, int pos);
    void insertFront(T value);
    void insertBack(T value);
    
    virtual Nodo<T> * deleteAt(int pos);
    Nodo<T> * deleteFront();
    Nodo<T> * deleteBack();
    virtual void clear();
    
    virtual Nodo<T> * search(T value);
    virtual Nodo<T> * searchPrev(T value);
    Nodo<T> * At(int pos);
    Nodo<T> * AtPrev(int pos);
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, ListaDoblementeEnlazada<Tn> &);
    
    Nodo<T> * operator[](const int index);
    
    Iterator begin() { return { this, 0 }; }
    Iterator end()   { return { this, tamano }; }
    
};

template <class T>
ListaDoblementeEnlazada<T>::ListaDoblementeEnlazada()
{
    //    inicio = nullptr;
    //    tamano = 0;
}

template <class T>
ListaDoblementeEnlazada<T>::~ListaDoblementeEnlazada()
{
    clear();
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::start()
{
    return inicio;
}

template <class T>
int ListaDoblementeEnlazada<T>::size()
{
    return tamano;
}

template <class T>
bool ListaDoblementeEnlazada<T>::empty()
{
    return (tamano == 0);
}

template <class T>
void ListaDoblementeEnlazada<T>::insertAt(T value, int pos)
{
    if (pos < 0 || pos > tamano) {
        return;
    }
    
    /* Insertar al inicio de la lista */
    if(tamano == 0){
        Nodo<T> * nuevo = new Nodo<T>(value);
        inicio = nuevo;
    }
    else if (pos == 0)
    {
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
    }
    else { /* Insertar en cualquier otra posición */
        Nodo<T> * prev = AtPrev(pos);
        
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(prev->getSiguiente());
//        nuevo->setAnterior(prev);
        if(pos != tamano){
//            prev->getSiguiente()->setAnterior(nuevo);
        }
        prev->setSiguiente(nuevo);
    }
    
    ++tamano;
}

template <class T>
void ListaDoblementeEnlazada<T>::insertFront(T value)
{
    insertAt(value, 0);
}

template <class T>
void ListaDoblementeEnlazada<T>::insertBack(T value)
{
    insertAt(value, tamano);
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::deleteAt(int pos)
{
//    if (pos < 0 || pos >= tamano) {
//        return nullptr;
//    }
//    
//    Nodo<T> * borrado = nullptr;
//    
//    /* Borra al inicio */
//    if (pos == 0) {
//        borrado = inicio;
//        inicio->getSiguiente()->setAnterior(nullptr);
//        inicio = inicio->getSiguiente();
//    }
//    else { /* Borrar en cualquier otra posición */
//        Nodo<T> * prev = AtPrev(pos);
//        borrado = prev->getSiguiente();
//        if(pos != tamano-1){
//          borrado->getSiguiente()->setAnterior(prev);
//        }
//        prev->setSiguiente( borrado->getSiguiente() );
//    }
//    
//    borrado->setSiguiente(nullptr);
//    --tamano;
//    
//    
//    return borrado;
    
    if (pos < 0 || pos >= tamano) {
        return nullptr;
    }
    
    Nodo<T> * borrado = nullptr;
    
    /* Borra al inicio */
    if (pos == 0) {
        borrado = inicio;
        inicio = inicio->getSiguiente();
    }
    else { /* Borrar en cualquier otra posición */
        Nodo<T> * prev = AtPrev(pos);
        borrado = prev->getSiguiente();
        prev->setSiguiente( borrado->getSiguiente() );
    }
    
    borrado->setSiguiente(nullptr);
    
    --tamano;
    
    return borrado;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::deleteFront()
{
    return deleteAt(0);
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::deleteBack()
{
    return deleteAt(tamano-1);
}

template <class T>
void ListaDoblementeEnlazada<T>::clear()
{
    Nodo<T> * aux;
    
    while (inicio) {
        aux = inicio;
        inicio = inicio->getSiguiente();
        aux->setSiguiente(nullptr);
//        aux->setAnterior(nullptr);
        delete aux;
    }
    
    inicio = nullptr;
    
    tamano = 0;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::search(T value)
{
    Nodo<T> * aux = inicio;
    
    while (aux && (aux->getInfo() != value) ) {
        aux = aux->getSiguiente();
    }
    
    return aux;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::searchPrev(T value)
{
    Nodo<T> * aux = inicio;
    Nodo<T> * prev = aux;
    
    while (aux && (aux->getInfo() != value) ) {
        prev = aux;
        aux = aux->getSiguiente();
    }
    
    return prev;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::At(int pos)
{
    int i = 0;
    Nodo<T> * aux = nullptr;
    
    if (pos < 0 || pos >= tamano) {
        return aux;
    }
    
    aux = inicio;
    
    while (i < pos) {
        aux = aux->getSiguiente();
        ++i;
    }
    
    return aux;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::AtPrev(int pos)
{
    int i = 0;
    Nodo<T> * aux = nullptr;
    
    if (pos < 0 || pos > tamano) {
        return aux;
    }
    
    aux = inicio;
    
    while (i < pos-1) {
        aux = aux->getSiguiente();
        ++i;
    }
    
    return aux;
}

template <class T>
std::ostream & operator <<(std::ostream & os, ListaDoblementeEnlazada<T> & lista)
{
    //    Nodo<T> * aux = lista.inicio;
    //
    //    while (aux) {
    //        os << *aux << std::endl;
    //        aux = aux->getSiguiente();
    //    }
    
    
    for (auto p : lista)
    {
        os << p;
    }
    
    return os;
}

template <class T>
Nodo<T> * ListaDoblementeEnlazada<T>::operator[](const int index) {
    return At(index);
};


#endif /* defined(__Tarea4Ejercicio4__ListaDoblementeEnlazada__) */
