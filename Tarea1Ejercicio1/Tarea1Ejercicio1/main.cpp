//
//  main.cpp
//  Tarea1Ejercicio1
//
//  Created by Daniel on 26/08/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "math.h"
using namespace std;

int potencia(int f, int c,int a, int cont);

int main(int argc, const char * argv[])
{
    int N;
    cout<<"De que tamaño la matriz?";
    cin>>N;
    int matriz [N][N];
    
    for (int fila = 0; fila < N; fila++) {
        for(int columna = 0; columna < N; columna++){
            matriz[fila][columna] = potencia(fila,columna,1,0);
        }
        
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j < N; j++){
            cout<<matriz[i][j] << " ";
        }
        cout<< endl;
    }
    return 0;
}

int potencia(int f, int c,int a, int cont){
    if((cont == f)|| (cont == c)){
        return a;
    }
    else{
        a = a*2;
        return potencia(f,c,a,cont+1);
    }
}