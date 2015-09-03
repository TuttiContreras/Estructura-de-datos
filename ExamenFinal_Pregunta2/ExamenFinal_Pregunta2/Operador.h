//
//  Operador.h
//  ExamenFinal_Pregunta2
//
//  Created by Daniel on 01/12/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __ExamenFinal_Pregunta2__Operador__
#define __ExamenFinal_Pregunta2__Operador__

#include <iostream>
#include "Llamada.h"
#include <list>

using namespace std;

class Operador{
public:
    Operador();
    string nombre, apellidoP, apellidoM, sexo, direccion, turno;
    int edad, telefono, productividad;
    bool activo, disponible;
    
    list<Llamada> registro;
    
    void nuevaLlamada(Llamada);
    
    bool operator <(Operador * o);
    friend ostream & operator <<(ostream & os, Operador & o);
};

#endif /* defined(__ExamenFinal_Pregunta2__Operador__) */
