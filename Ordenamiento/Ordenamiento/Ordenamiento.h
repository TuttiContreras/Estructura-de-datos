//
//  Ordenamiento.h
//  Ordenamiento
//
//  Created by Daniel on 01/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Ordenamiento__Ordenamiento__
#define __Ordenamiento__Ordenamiento__

#include <iostream>

template <class T>
class Ordenamiento{
public:
    static void ordenamientoBurbuja(T [], int , bool(*)(T,T));
    static void ordenamientoinsercion(T [], int, bool(*)(T,T));
    static void ordenamientoSeleccion(T [], int , bool(*) (T,T));
    
    static void ordenamientoQuickSort(T [], bool(*)(T,T), int, int);
    static void ordenamientoMergeSort(T [], bool(*)(T,T), int, int, int);
    static void merge(T [], int, int, int, bool(*)(T,T), int);
    
    static bool asc(T, T);
    static bool desc(T,T);
};


template <class T>
bool Ordenamiento<T>::asc(T a, T b){
    return a>b;
}
template <class T>
bool Ordenamiento<T>::desc(T a, T b){
    return a<b;
}

template <class T>
void Ordenamiento<T>::ordenamientoBurbuja(T v[], int n, bool compara (T,T)){
    T temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            //if (v[j-1] > v[j])
            if(compara(v[j-1], v[j]))
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            } }
    }
}
template <class T>
void Ordenamiento<T>::ordenamientoinsercion(T v[], int n, bool compara (T,T)){
    T index;
    for (int i=1; i < n; i++)
    {
        index = v[i];
        int j = i-1;
        while (j >= 0 && compara(v[j], index))
        {
            v[j + 1] = v[j];
            j--; }
        v[j+1] = index;
    }
}
template <class T>
void Ordenamiento<T>::ordenamientoSeleccion(T v[], int n, bool compara (T,T)){
    int minimo = 0;
    T temp;
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            //if (v[minimo] > v[j])
            if(compara(v[minimo], v[j])){
                minimo = j;
            }
        }
        temp = v[minimo];
        v[minimo] = v[i];
        v[i] = temp;
    }
}

template <class T>
void Ordenamiento<T>::ordenamientoQuickSort(T a[], bool compara (T,T), int primero, int ultimo){
    int izquierdo = primero;
    int derecho = ultimo;
    int temp;
    //Se selecciona pivote
    int pivote = a[primero];
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && (!compara(a[izquierdo], pivote ))) izquierdo++;
            while ( compara(a[derecho], pivote )) derecho--;
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = a[derecho];
                a[derecho] = a[izquierdo];
                a[izquierdo] = temp;
            }
        }
        
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = a[derecho];
        a[derecho] = a[primero];
        a[primero] = temp;
        // Paso recursivo
        ordenamientoQuickSort ( a,compara, primero, derecho-1);
        ordenamientoQuickSort ( a, compara, izquierdo, ultimo);
    }
}

template <class T>
void Ordenamiento<T>::ordenamientoMergeSort(T v[], bool compara (T,T), int l, int n, int N){
    int m = (n+l)/2;
    if (n > l)
    {
        ordenamientoMergeSort (v, compara, l, m, N);
        ordenamientoMergeSort (v, compara, m+1, n, N);
        merge (v, l, m, n, compara, N);
    }
    
}

template <class T>
void Ordenamiento<T>::merge(T v[], int l, int m, int n, bool compara(T,T), int N){
    int i, j, k;
    T aux[N]; //Vectorauxiliar
    for(i=m+1;i>l;i--)
        aux[i-1] = v[i-1];
    
    for (j=m; j<n; j++)
            aux[n+m-j] = v[j+1];
    
    for(k=l;k<=n;k++) //Mezcla
        if (!compara(aux[i], aux[j]))
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
    
}


#endif /* defined(__Ordenamiento__Ordenamiento__) */
