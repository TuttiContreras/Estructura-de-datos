//
//  main.cpp
//  Tarea1Ejercicio3
//
//  Created by Daniel on 27/08/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>

void imprimir(int x, int y);
int factorial(int a, int num);
int numTotalCaminos(int x, int y);

int main(int argc, const char * argv[])
{
    /* Creación de tablero*/
    int x, y;
    std::cout<<"Indique el numero de filas"<<std::endl;
    std::cin>>x;
    std::cout<<"Indique el numero de columnas"<<std::endl;
    std::cin>>y;
    
    imprimir(x, y);
    if(numTotalCaminos(x, y) == 0){
        std::cout<<"El robot no puede llegar a la casilla inferior derecha, no hay suficiente espacio"<<std::endl;
    }
    else{
        std::cout<<"Total de caminos posibles: "<<numTotalCaminos(x, y)<<std::endl;
    }
    
    
    return 0;
}

void imprimir(int x, int y){
    for(int i =0; i<x; i++){
        for(int j = 0; j<y; j++){
            std::cout<<"0 ";
        }
        std::cout<<std::endl;
    }
}

int numTotalCaminos(int x, int y){
    int res;
    if(((x-1)%2 != 0)|| ((y-1)%3 != 0)){
        res = 0;
    }
    else{
        int totalMovimientosAbajo = (x-1)/2;
        int totalMovimientosDerecha = (y-1)/3;
        int totalMovimientos = totalMovimientosAbajo + totalMovimientosDerecha;
        
        res = (factorial(totalMovimientos, 1))/(factorial(totalMovimientosAbajo, 1)*factorial(totalMovimientosDerecha, 1));
    }
    
    return res;
}

int factorial(int a, int num){
    if(a == 1){
    return num;
    }
    else{
        return factorial(a-1, num*a);
    }
}