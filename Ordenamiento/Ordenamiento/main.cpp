//
//  main.cpp
//  Ordenamiento
//
//  Created by Daniel on 01/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Ordenamiento.h"
#include "Libro.h"
#include "Contrato.h"

//Crear un menu sin necesidad de un switch
typedef bool (*t_compara)(int, int);
typedef void (*t_algoritmo)(int[], int, t_compara);


template <typename T>
void imprime(T [], int);

int main(int argc, const char * argv[])
{
    const int N = 10;
    srand((int)time(NULL));
    /*Ordenar enternos*/
    
    int enteros[N];
    
    for(int i = 0; i< N; i++){
        enteros[i] = rand() % 100;
    }
    
    std::cout<<"-------Ordenamiento de Enteros--------\n";
    
    t_algoritmo algoritmo[3];
    algoritmo[0] = Ordenamiento<int>::ordenamientoBurbuja;
    algoritmo[1] = Ordenamiento<int>::ordenamientoinsercion;
    algoritmo[2] = Ordenamiento<int>::ordenamientoSeleccion;
    
    t_compara compara[2];
    compara[0] = Ordenamiento<int>::asc;
    compara[1] = Ordenamiento<int>::desc;
    
    //Ordenamiento<int>::ordenamientoQuickSort(enteros, Ordenamiento<int>::asc, 0, N-1);
    //Ordenamiento<int>::ordenamientoMergeSort(enteros, Ordenamiento<int>::asc, 0, N-1, N);
    //Ordenamiento<int>::ordenamientoBurbuja(enteros, N, Ordenamiento<int>::desc);
    
    std::cout<<"Escoja el Tipo de ordenamiento\n";
    std::cout<<"1- Burbuja\n2- Insercion\n3- Seleccion\n";
    int opcion;
    std::cin>>opcion;
    std::cout<<"1-Ascendente\n2- Desendente\n";
    int tipo;
    std::cin>>tipo;
    
    imprime(enteros, N);
    
    //llamar a la funcion desde el arreglo de funciones
    algoritmo[opcion-1](enteros, N, compara[tipo-1]);
    
    imprime(enteros, N);
    
    /*Ordenar float*/
    float flotantes[N];
    
    for(int i = 0; i< N; i++){
        flotantes[i] = (rand() % 100) *0.1;
    }
    
    std::cout<<"\n----------Ordenamiento de Flotantes--------\n";
    imprime(flotantes, N);
    Ordenamiento<float>::ordenamientoBurbuja(flotantes, N, Ordenamiento<float>::desc);
    imprime(flotantes, N);

    /*Ordenar clase del usuario*/
    const int nlibros = 3;
    Libro biblioteca[nlibros];
    biblioteca[0] =  Libro("Amanecer", "jfk", 250, 2010);
    biblioteca[1] =  Libro("luna", "jfk", 300, 2010);
    biblioteca[2] =  Libro("crepusculo", "jfk", 450, 2010);
    //imprime(biblioteca, nlibros);
    
    //Ordenamiento<Libro>::ordenamientoinsercion(biblioteca, nlibros, Ordenamiento<Libro>::desc);
    //imprime(biblioteca, nlibros);
    
    
    /*ejercicio 2*/
    std::cout<<"\n-------ejercicio 2----------"<<std::endl;
    const int nContratos = 3;
    Contrato contratos[nContratos];
    contratos[0] = Contrato(1, 20, 3, 1991);
    contratos[1] = Contrato(2, 29, 3, 1994);
    contratos[2] = Contrato(3, 19, 3, 1991);
    imprime(contratos, nContratos);
    Ordenamiento<Contrato>::ordenamientoinsercion(contratos, nContratos, Ordenamiento<Contrato>::asc);
    imprime(contratos, nContratos);

    //ejercicio de aritmetica de apuntadores
    std::cout<<"-----------Ejercicio con apuntadores------------\n";
    
    int n;
    std::cout<<"De cuantos numeros quiere su arreglo?\n";
    std::cin>>n;
    
    int * numeros = new int [n];
    int * final = numeros + n;
    int i = 0;
    
    //llenar el arreglo:
    for (int * aux = numeros; aux < final; ++aux){
        std::cout<<"numeros["<<i++<<"] = ";
        std::cin>>*aux;
    }
    
    //ordenar el arreglo con una funcion en linea como parametro
    Ordenamiento<int>::ordenamientoinsercion(numeros, n, [](int a, int b){return a > b;});
    i = 0;
    
    //imprimir arreglo ordenado
    std::cout<<"Arreglo ordenado:\n";
    for(int *aux = numeros; aux < final; ++aux){
        std::cout<<"nuemros["<<i++<<"] = "<< *aux<<std::endl;
    }
    
    return 0;
}


template <typename T>
void imprime(T v[], int n){
    for(int i = 0; i<n; i++){
        std::cout<<v[i]<<" ";
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