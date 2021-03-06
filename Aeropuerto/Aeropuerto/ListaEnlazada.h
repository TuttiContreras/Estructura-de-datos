//
//  ListaEnlazada.h
//  SegundoParcialEjercicio1
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __SegundoParcialEjercicio1__ListaEnlazada__
#define __SegundoParcialEjercicio1__ListaEnlazada__

#include <iostream>
#include "Nodo.h"

template <class T>
class ListaEnlazada {
protected:
    Nodo<T> * inicio = nullptr;
    int tamano = 0;
    
    /* Iterador de la lista */
    class Iterator {
        ListaEnlazada<T> * data;
        int position;
    public:
        Iterator(ListaEnlazada<T> * _data, int _position):data(_data),position(_position) {}
        
        Nodo<T> operator*() const { return *(data->At(position)); }
        const Iterator& operator++() { ++position; return *this; }
        bool operator!=(const Iterator& it) const { return position != it.position; }
    };
    
public:
    ListaEnlazada();
    ~ListaEnlazada();
    
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
    friend std::ostream & operator <<(std::ostream &, ListaEnlazada<Tn> &);
    
    Nodo<T> * operator[](const int index);
    
    Iterator begin() { return { this, 0 }; }
    Iterator end()   { return { this, tamano }; }
    
};

template <class T>
ListaEnlazada<T>::ListaEnlazada()
{
    //    inicio = nullptr;
    //    tamano = 0;
}

template <class T>
ListaEnlazada<T>::~ListaEnlazada()
{
    clear();
}

template <class T>
Nodo<T> * ListaEnlazada<T>::start()
{
    return inicio;
}

template <class T>
int ListaEnlazada<T>::size()
{
    return tamano;
}

template <class T>
bool ListaEnlazada<T>::empty()
{
    return (tamano == 0);
}

template <class T>
void ListaEnlazada<T>::insertAt(T value, int pos)
{
    if (pos < 0 || pos > tamano) {
        return;
    }
    
    /* Insertar al inicio de la lista */
    if (pos == 0)
    {
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
    }
    else { /* Insertar en cualquier otra posición */
        Nodo<T> * prev = AtPrev(pos);
        
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(prev->getSiguiente());
        prev->setSiguiente(nuevo);
    }
    
    ++tamano;
}

template <class T>
void ListaEnlazada<T>::insertFront(T value)
{
    insertAt(value, 0);
}

template <class T>
void ListaEnlazada<T>::insertBack(T value)
{
    insertAt(value, tamano);
}

template <class T>
Nodo<T> * ListaEnlazada<T>::deleteAt(int pos)
{
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
Nodo<T> * ListaEnlazada<T>::deleteFront()
{
    return deleteAt(0);
}

template <class T>
Nodo<T> * ListaEnlazada<T>::deleteBack()
{
    return deleteAt(tamano-1);
}

template <class T>
void ListaEnlazada<T>::clear()
{
    Nodo<T> * aux;
    
    while (inicio) {
        aux = inicio;
        inicio = inicio->getSiguiente();
        aux->setSiguiente(nullptr);
        delete aux;
    }
    
    inicio = nullptr;
    
    tamano = 0;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::search(T value)
{
    Nodo<T> * aux = inicio;
    
    while (aux && (aux->getInfo() != value) ) {
        aux = aux->getSiguiente();
    }
    
    return aux;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::searchPrev(T value)
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
Nodo<T> * ListaEnlazada<T>::At(int pos)
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
Nodo<T> * ListaEnlazada<T>::AtPrev(int pos)
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
std::ostream & operator <<(std::ostream & os, ListaEnlazada<T> & lista)
{
    //    Nodo<T> * aux = lista.inicio;
    //
    //    while (aux) {
    //        os << *aux << std::endl;
    //        aux = aux->getSiguiente();
    //    }
    
    for (auto p : lista)
    {
        os << p << std::endl;
    }
    
    return os;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::operator[](const int index) {
    return At(index);
}

#endif /* defined(__SegundoParcialEjercicio1__ListaEnlazada__) */
