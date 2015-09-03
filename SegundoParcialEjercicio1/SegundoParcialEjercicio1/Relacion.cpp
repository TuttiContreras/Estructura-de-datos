//
//  Relacion.cpp
//  SegundoParcialEjercicio1
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Relacion.h"

Relacion::Relacion(){
    
}

Relacion::Relacion(std::string uno, int t){
    estudianteU = uno;
    tiempo = t;
}

std::ostream & operator <<(std::ostream & os, Relacion & r){
    os<< "Relacion con: " << r.estudianteU << "  Duracion: " << r.tiempo<<std::endl;
    return os;
}