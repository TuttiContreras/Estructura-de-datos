//
//  Libro.cpp
//  Ordenamiento
//
//  Created by Daniel on 01/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Libro.h"

std::ostream & operator <<(std::ostream & os, Libro & libro){
    os << libro.titulo << std::endl;
    return os;
}

bool Libro::operator > (Libro & libro){
    return titulo > libro.titulo;
}