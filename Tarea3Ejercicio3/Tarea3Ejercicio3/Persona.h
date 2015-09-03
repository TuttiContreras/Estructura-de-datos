//
//  Persona.h
//  Tarea3Ejercicio3
//
//  Created by Daniel on 07/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea3Ejercicio3__Persona__
#define __Tarea3Ejercicio3__Persona__

#include <iostream>

class Persona{
private:
    std::string nombre, apellido;
    int edad;
    
public:
    Persona(){};
    Persona(int i);
    friend std::ostream & operator <<(std::ostream & os, Persona p);
    
};



#endif /* defined(__Tarea3Ejercicio3__Persona__) */
