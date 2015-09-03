//
//  Mensaje.h
//  Tarea4Ejercicio3
//
//  Created by Daniel on 17/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea4Ejercicio3__Mensaje__
#define __Tarea4Ejercicio3__Mensaje__

#include <iostream>

class Mensaje{
public:
    Mensaje();
    Mensaje(int, int, std::string);
    int dirDestino, dirOrigen;
    std::string mnsj;
    
    friend std::ostream & operator <<(std::ostream &, Mensaje &);
};

#endif /* defined(__Tarea4Ejercicio3__Mensaje__) */