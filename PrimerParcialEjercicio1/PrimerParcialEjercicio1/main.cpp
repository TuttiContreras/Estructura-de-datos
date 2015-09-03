
//
//  main.cpp
//  PrimerParcialEjercicio1
//
//  Created by Daniel on 08/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#define N  2
#define M  3

void imprimir(int**);
int sumaMatriz(int**, int, int, int);

int main(int argc, const char * argv[])
{
    //generar matriz
    int **matriz = new int* [M];
    srand((int)time(NULL));
    for(int i = 0; i <M; ++i){
        matriz[i] = new int[N];
        for (int j = 0; j< N; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
    
    imprimir(matriz);
    
    int res = sumaMatriz(matriz, 0, 0, 0);
    std::cout<<"El resultado de la suma es: "<<res<<std::endl;
    
    return 0;
}

int sumaMatriz(int** m, int res, int fila, int col){
    if((fila == N) && (col == M)){
        return res;
    }
    else if (col == M){
        return sumaMatriz(m, res, fila+1, 0);
    }
    else{
        res = res + m[col][fila];
        return sumaMatriz(m, res, fila, col+1);
    }
}

void imprimir(int **m){
    for(int i = 0; i< M; i++){
        for (int j = 0; j< N; j++){
            std::cout<<m[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}