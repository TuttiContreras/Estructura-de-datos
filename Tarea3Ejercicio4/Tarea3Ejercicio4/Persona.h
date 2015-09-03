//
//  Persona.h
//  Tarea3Ejercicio4
//
//  Created by Daniel on 09/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea3Ejercicio4__Persona__
#define __Tarea3Ejercicio4__Persona__

#include <iostream>

class Persona{
private:
    std::string nombre, apellido;
    int edad;
    
public:
    Persona(){};
    Persona(int i);
    friend std::ostream & operator <<(std::ostream & os, Persona p);
    bool operator < (const Persona &);
    
};

#endif /* defined(__Tarea3Ejercicio4__Persona__) */
