//
//  main.cpp
//  PrimerParcialEjercicio2
//
//  Created by Daniel on 08/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Asignatura.h"
#include "Carrera.h"

int main(int argc, const char * argv[])
{
    Carrera carreras[2];
    carreras[0] =  Carrera("ITC");
    carreras[1] = Carrera("INT");
    
    /*
    Asignatura asignaturas[10];
    for (int i = 0; i< 5; i++) {
        asignaturas[i] = carreras[0].asign[i];
    }
    for (int i = 0; i< 5; i++) {
        asignaturas[i] = carreras[0].asign[i];
    }
    */
    
    return 0;
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

void porcentajes(){
    int cant;
    for (int i = 0; i< 10; i++) {
}
}