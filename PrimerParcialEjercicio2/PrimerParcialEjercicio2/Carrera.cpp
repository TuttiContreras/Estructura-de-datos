//
//  Carrera.cpp
//  PrimerParcialEjercicio2
//
//  Created by Daniel on 08/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Carrera.h"

Carrera::Carrera(){
    nombre = "vacio";
}
Carrera::Carrera(std::string _nombre){
    nombre = _nombre;
    Asignatura* asign = new Asignatura[numAsign];
    montoTotal = 0;
    for(int i = 0; i< numAsign; i++){
        montoTotal = montoTotal + asign[i].montoT;
    }
}


void Carrera::imprimir(){
    std::cout<<"-----Carrera: "<<nombre<<"-----"<<std::endl;
    std::cout<<"Monto total: "<<montoTotal<<std::endl;
    buscarMayorMonto();
}


void Carrera::buscarMayorMonto(){
    Asignatura temp = asign[0];
    for(int i = 0; i<numAsign; i++){
        if(asign[i].montoT > temp.montoT){
            temp = asign[i];
        }
    }
    std::cout<<"Asignatura con mayor monto total recaudado: "<<temp.codigo<<std::endl;
}