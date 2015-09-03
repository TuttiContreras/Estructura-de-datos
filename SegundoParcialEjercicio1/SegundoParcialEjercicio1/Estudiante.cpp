//
//  Estudiante.cpp
//  SegundoParcialEjercicio1
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Estudiante.h"

Estudiante::Estudiante(){
    
}

Estudiante::Estudiante(std::string n, int t){
    nombre = n;
    tiempoTU = t;
}

Estudiante::~Estudiante(){
    delete relaciones;
}

void Estudiante::nuevaRelacion(Estudiante * e, int t){
    bool existe = false;
    for(int i = 0; i < relaciones->size(); ++i){
        if (relaciones->At(i)->getInfo()->estudianteU == e->nombre) {
            existe = true;
            break;
        }
    }
    if (!existe) {
        
        Relacion * r = new Relacion(e->nombre, t);
        relaciones->insertBack(r);
        e->nuevaRelacion(this, t);
    }
    
}

bool Estudiante::operator>(const Estudiante & e){
    if(this->relaciones->size() > e.relaciones->size()){
        return true;
    }
    return false;
}

int Estudiante::porcentajeT(){
    float t = 0;
    for (int i = 0; i < relaciones->size(); ++i) {
        t += relaciones->At(i)->getInfo()->tiempo;
    }
    t = t*100/tiempoTU;
    return t;
}

float Estudiante::porcentaje(){
    float t = 0;
    for (int i = 0; i < relaciones->size(); ++i) {
        t += relaciones->At(i)->getInfo()->tiempo;
    }
    t = t/relaciones->size();
    return t;
}

std::ostream & operator <<(std::ostream & os, Estudiante & e){
    os << "Nombre: " << e.nombre <<std::endl;
    os << "Realciones: " <<std::endl;
    for (int i = 0; i < e.relaciones->size(); ++i){
        std::cout<<*e.relaciones->At(i)->getInfo();
    }
    return os;
}

