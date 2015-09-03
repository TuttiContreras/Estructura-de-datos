//
//  main.cpp
//  Tarea1Ejercicio2
//
//  Created by Daniel on 26/08/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#define N 6

void imprimir(int **a);
bool resolver(int **a, int x, int y);

int main(int argc, const char * argv[])
{
    /*construir laberinto
     * 1 casilla disponible
     * 0 casilla prohibida
     * 2 camino correcto
     * 3 camino erroneo
     */
    int** matriz = new int*[N];
    for(int i = 0; i < N; i++){
        matriz[i] = new int[N];
        for(int j = 0; j<N; j++){
            matriz[i][j] = 0;
        }
    }
    
    matriz[0][0] = 1;
    matriz[0][1] = 1;
    matriz[1][1] = 1;
    matriz[1][2] = 1;
    matriz[1][3] = 1;
    matriz[1][4] = 1;
    matriz[2][4] = 1;
    matriz[3][4] = 1;
    matriz[4][4] = 1;
    matriz[5][4] = 1;
    matriz[5][5] = 1;
    matriz[2][1] = 1;
    matriz[3][1] = 1;
    matriz[3][2] = 1;
    matriz[4][1] = 1;
    /*fin construccion laberinto*/
    
    
    
    imprimir(matriz);
    std::cout<<std::endl;
    std::cout<<std::endl;
    
    if(resolver(matriz, 0,0)){
        imprimir(matriz);
    }
    else{
        std::cout<<"Impossible";
    }
    
    return 0;
}

void imprimir(int **a){
    std::cout<<std::endl;
    for(int i = 0; i<N; i++){
        for(int j = 0; j < N; j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

bool resolver(int **a, int x, int y){
        if((x == N-1) &&(y == N-1))
        {
            a[x][y] = 2;
            std::cout<<"Completado";
            return true;
        }
        else if((x+1< N)&&(a[x+1][y] == 1)){
            std::cout<<"Abajo, ";
            a[x][y] = 2;
            return resolver(a, x+1, y);
        }
        else if((y+1< N)&&(a[x][y+1] == 1)){
            std::cout<<"Derecha, ";
            a[x][y] = 2;
            return resolver(a, x, y+1);
        }
        else if((x-1 >= 0)&&(a[x-1][y] == 1)){
            std::cout<<"Arriba, ";
            a[x][y] = 2;
            return resolver(a, x -1, y);
        }
        else if((y-1 >= 0)&&(a[x][y-1] == 1)){
            std::cout<<"Izquierda, ";
            a[x][y] = 2;
            return resolver(a, x, y-1);
        }
        //regresar
        else if((x+1< N)&&(a[x+1][y] == 2)){
            std::cout<<"regresar Abajo, ";
            a[x][y] = 3;
            return resolver(a, x +1, y);
        }
        else if((y+1< N)&&(a[x][y+1] == 2)){
            std::cout<<"regresar Derecha, ";
            a[x][y] = 3;
            return resolver(a, x, y+1);
        }
        else if((x-1>= 0)&&(a[x-1][y] == 2)){
            std::cout<<"regresar Arriba, ";
            a[x][y] = 3;
            return resolver(a, x-1, y);
        }
        else if((y-1 >= 0)&&(a[x][y-1] == 2)){
            std::cout<<"regresar Izquierda, ";
            a[x][y] = 3;
            return resolver(a, x, y-1);
        }
        else{
            std::cout<<"x = "<<x<<", y = "<<y<<", break"<<std::endl;
            return false;
        }
    
}