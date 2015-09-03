//
//  Ciudad.cpp
//  Grafo
//
//  Created by Vicente Cubells Nonell on 03/11/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include "Ciudad.h"

Ciudad::Ciudad() : Ciudad("Sin definir", 0)
{
    
}

Ciudad::Ciudad(std::string nombre, int hab)
: nombre(nombre), habitantes(hab)
{
    
}

std::ostream & operator <<(std::ostream & os, Ciudad  ciudad)
{
    os << ciudad.nombre << "(" << ciudad.habitantes << ")";
    
    return os;
}