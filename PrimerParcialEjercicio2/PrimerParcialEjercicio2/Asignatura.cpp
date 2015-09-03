//
//  Asignatura.cpp
//  PrimerParcialEjercicio2
//
//  Created by Daniel on 08/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Asignatura.h"
Asignatura::Asignatura(){
    srand((int)time(NULL));
    codigo = rand() % 1000;
    numAlum = rand() % 100;
    unidades = rand() % 6;
    montoT = numAlum * unidades * 1500;
}

void Asignatura::imprimir(){
    std::cout<<"-----Asignatura: "<<codigo<<" -----"<<std::endl;
    std::cout<<"Numero de alumnos: "<<numAlum<<std::endl;
    if(montoT <= montoMin){
        int falt = montoMin - montoT;
        falt = falt/numAlum;
        std::cout<<"Cada alumno debe pagar un exceso de: "<<falt<<" MXN, para que se abra la asignatura"<<std::endl;
    }
}