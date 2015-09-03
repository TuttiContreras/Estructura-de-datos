//
//  Persona.cpp
//  Tarea3Ejercicio3
//
//  Created by Daniel on 07/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Persona.h"

Persona::Persona(int i){
    std::cout<<"Nombre: ";
    std::cin>>nombre;
    
    std::cout<<"Apellido: ";
    std::cin>>apellido;
    
    std::cout<<"Edad: ";
    std::cin>>edad;
}

std::ostream & operator <<(std::ostream & os, Persona p){
    os << p.nombre <<" "<<p.apellido << " " << p.edad;
    return os;
}