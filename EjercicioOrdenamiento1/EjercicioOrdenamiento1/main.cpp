//
//  main.cpp
//  EjercicioOrdenamiento1
//
//  Created by Daniel on 04/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#define N 10000

void print(int []);
void ordenamientoBurbuja(int v[], int n);
void ordenamientoInsercion(int numbers[], int n);
void ordenamientoSeleccion(int x[], int n);

int main(int argc, const char * argv[])
{
    srand((int)time(NULL));
    //creacion de arreglos
    int arreglo[N] = {};
    for(int i = 0; i< N; i++){
        arreglo[i] = rand() %100;
    }
    
    print(arreglo);
    
    std::cout<<"Escoja un método de ordenamiento:"<<std::endl<<"1) Burbuja"<<std::endl<<"2) Inserción"<<std::endl<<"3) Seleccion"<<std::endl;
    int opcion;
    std::cin>>opcion;
    switch (opcion) {
        case 1:
            ordenamientoBurbuja(arreglo, N);
            print(arreglo);
            break;
            
        default:
            std::cout<<"no es valida la opcion"<<std::endl;
            break;
    }
    
    return 0;
}

void print(int a[]){
    for(int i = 0; i<N; i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}

//nunca usarlo
void ordenamientoBurbuja(int v[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (v[j-1] > v[j])
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            } }
    } }


//funciona con desplasamiento de numeros
void ordenamientoInsercion(int numbers[], int n){
    int i, j, index;
    for(i = 1; i<n; i++){
        index = numbers[1];
        j = i-1;
        while(j>= 0 && numbers[j] < index){
            numbers[j+1] = numbers [j];
            j--;
        }
        numbers[j+1] = index;
    }
}

void ordenamientoSeleccion(int x[], int n){
    int minimo = 0;
    int temp;
    
    for(int i = 0; i<n-1;i++){
        minimo = i;
        for(int j = i+1; j<n; j++){
            if (x[minimo] > x[j]){
                minimo = j;
            }
            temp = x[minimo];
            x[minimo] = x[i];
            x[i] = temp;
        }
    }
}