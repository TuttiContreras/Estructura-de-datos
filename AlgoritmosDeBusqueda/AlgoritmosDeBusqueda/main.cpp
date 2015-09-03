//
//  main.cpp
//  AlgoritmosDeBusqueda
//
//  Created by Daniel on 25/08/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Busqueda.h"
#define N 10

using namespace std;

void imprimirMatriz(int** a);

/*template <typename T>
bool busquedaSequencial(T a[], T buscar);
template <typename T>
bool busquedaBinaria(T a[], T buscar, int inicio, int final);

int buscarOcurrencias(int a[], int buscar);
void imprimirVector(int a[]);
*/
int main(int argc, const char * argv[])
{
    /*
    //arreglo con numeros aletorios
    int numeros[N] = {0};
    srand((int)time(NULL));
    for(int i = 0; i <N; ++i){
        numeros[i] = rand() % 1000;
    }
    
    imprimirVector(numeros);
    int elementoBuscar;
    std::cout << "Entre el numero a buscar";
    std::cin >> elementoBuscar;
    
    bool existe = busquedaSequencial(numeros, elementoBuscar);
    
    if(existe){
        std::cout << "El numero " <<elementoBuscar << " si existe en el vector" <<std::endl;
    }
    else{
        std::cout << "El numero " <<elementoBuscar << " no existe en el vector"<<std::endl;
    }
    
    int ocurrencias = buscarOcurrencias(numeros, elementoBuscar);
    
    if(ocurrencias == 0){
        std::cout << "El numero " <<elementoBuscar << " no existe en el vector"<<std::endl;
    }
    else{
        std::cout << "El numero " <<elementoBuscar << " si existe en el vector " << ocurrencias << " veces"<<std::endl;
    }
    
    //busqueda bienaria
    
    std::cout << "busqueda binaria"<< std::endl;
    int acendente[N] = {0};
    for(int i = 0; i <N; ++i){
        acendente[i] = i;
    }
    
    imprimirVector(acendente);
    
    existe = busquedaBinaria(acendente, elementoBuscar, 0, N-1);
    if(existe){
        std::cout << "El numero " <<elementoBuscar << " si existe en el vector" <<std::endl;
    }
    else{
        std::cout << "El numero " <<elementoBuscar << " no existe en el vector"<<std::endl;
    }

    */
    
    //arreglo con numeros aletorios
    int** matriz = new int*[N];
    srand((int)time(NULL));
    for(int i = 0; i <N; ++i){
        matriz[i] = new int[N];
        for(int j = 0; j < N; j++){
            matriz[i][j] = rand() % 1000;
        }
        
    }
    imprimirMatriz(matriz);
    
    Busqueda<int> b;
    
    cout<<"Que numero quiere buscar?"<<endl;
    int buscar;
    cin>>buscar;
    bool encontrado = false;
    
    for(int i = 0; i<N; i++){
        if(b.busquedaSequencial(matriz[i], buscar, N) != -1){
            cout<<"linea: "<<i<<", columna: "<<b.busquedaSequencial(matriz[i], buscar, N)<<endl;
            encontrado = true;
        }
    }
    if (!encontrado){
        cout<<"No existe este numero!"<<endl;
    }
    
    return 0;
}

void imprimirMatriz(int** a){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<a[i][j]<<", ";
        }
        cout<<endl;
    }
}



/*
template <typename T>
bool busquedaSequencial(T a[], T buscar){
    int i = 0;
    bool encontrado = false;
    while((i < N) && (!encontrado)){
        if (a[i] == buscar){
            encontrado = true;
        }
        ++i;
    }
    return encontrado;
}

void imprimirVector(int a[]){
    for(int i=0;i<N;++i){
        std::cout << a[i] << ", ";
    }
    std::cout<<std::endl;
}

int buscarOcurrencias(int a[], int buscar){
    int ocurrecias = 0;
    for(int i =0; i<N;++i){
        if(a[i] == buscar){
            ++ocurrecias;
        }
    }
    return ocurrecias;
}

template <typename T>
bool busquedaBinaria(T a[], T buscar, int inicio, int final){
    int i = (inicio + final)/2;
    if(a[i] == buscar){
        return true;
    }
    else if(inicio == final){
        return false;
    }
    else if (a[i] > buscar){
        return busquedaBinaria(a, buscar, i +1, final);
    }
    else{
        return busquedaBinaria(a, buscar, inicio, i-1);
    }
    return false;
}
*/