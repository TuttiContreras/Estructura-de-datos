//
//  Persona.cpp
//  Tarea5Ejercicio4
//
//  Created by Daniel on 13/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Persona.h"

Persona::Persona(){
    nombre =apellidoM = apellidoP = sexo = "vacio";
    edad = fechaFallecido = 0;
    muerto = true;
}

Persona::Persona(int i){
    std::cout<<"Nombre: ";
    std::cin>>nombre;
    std::cout<<"Apellido Paterno: ";
    std::cin>>apellidoP;
    std::cout<<"Apellido Materno: ";
    std::cin>>apellidoM;
    std::cout<<"Sexo: ";
    std::cin>>sexo;
    std::cout<<"Edad: ";
    std::cin>>edad;
    fechaFallecido = NULL;
    muerto = false;
}

void Persona::Matar(){
    std::cout<<"Fecha de muerte: ";
    std::cin>>fechaFallecido;
    muerto = true;
}

void Persona::imprimir(){
    std::cout<< nombre << " " << apellidoP << " " << apellidoM << std::endl;
    std::cout<< "Edad: " << edad << "Sexo: " << sexo;
    if (muerto) {
        std::cout<<"Fallecido en: " << fechaFallecido<<std::endl;
    }
    std::cout<<std::endl;
}

int Persona::getFechaF(){
    return fechaFallecido;
}

std::string& Persona::getNombre(){
    return nombre;
}

std::string& Persona::getApellidoP(){
    return apellidoP;
}

std::string& Persona::getApellidoM(){
    return apellidoM;
}

bool Persona::getMuerto(){
    return muerto;
}

bool Persona::operator<(int ano){
    return (fechaFallecido != 0 && fechaFallecido < ano);
}

bool Persona::operator ==(Persona & p){
    if (p.nombre == nombre && p.apellidoP == apellidoP && p.apellidoM == apellidoM) {
        return true;
    }
    return false;
}

std::ostream & operator <<(std::ostream & os, Persona & p){
    if(p.muerto){
        os << "+ ";
    }
    os << p.nombre << " " << p.apellidoP[0] << ". " << p.apellidoM[0] << ".";
    return os;
}