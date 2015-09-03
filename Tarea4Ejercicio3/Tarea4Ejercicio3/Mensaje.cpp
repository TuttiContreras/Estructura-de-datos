//
//  Mensaje.cpp
//  Tarea4Ejercicio3
//
//  Created by Daniel on 17/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Mensaje.h"

Mensaje::Mensaje(){
    mnsj = "vacío";
    dirDestino = 0;
    dirOrigen = 0;
}

Mensaje::Mensaje(int o, int d, std::string m){
    mnsj = m;
    dirOrigen= o;
    dirDestino = d;
}

std::ostream & operator <<(std::ostream & os, Mensaje & m){
    os << m.mnsj << std::endl;
    return os;
}