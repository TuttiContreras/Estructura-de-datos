//
//  main.cpp
//  QuickSort
//
//  Método de Ordenamiento
//
//  Created by Daniel on 18/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#define N 10

void merge(int [], int, int, int);
void mergeSort(int [], int, int);
void quickSort(int [], int, int);

int main(int argc, const char * argv[])
{
    
    
    
    return 0;
}

void quickSort(int a[], int primero, int ultimo){
    int izquierdo = primero;
    int derecho = ultimo;
    int temp;
    
    int pivote = a[primero];
    
    if(primero <ultimo){
        while (izquierdo < derecho){
            while ( (izquierdo < derecho) && (a[izquierdo] <= pivote )) izquierdo++;
            while ( a[derecho] > pivote ) derecho--;
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = a[derecho];
                a[derecho] = a[izquierdo];
                a[izquierdo] = temp;
            }
        }
    }
}

void mergeSort(int v[], int l, int n){
    int m = (n+l)/2;
    if(n > l){
        mergeSort(v, l, m);
        mergeSort(v, m+1, n);
        merge(v, l, m, n);
    }
    
}

void merge (int v[], int l, int m, int n)
{
    int i, j, k;
    int aux[N];
    for(i=m+1;i>l;i--)!! //Vectorauxiliar aux[i-1] = v[i-1];
        for (j=m; j<n; j++)
            aux[n+m-j] = v[j+1];
    for(k=l;k<=n;k++)!! //Mezcla if (aux[i]<aux[j])
        v[k] = aux[i++];
    else
        }