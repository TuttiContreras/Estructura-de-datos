//
//  Cliente.h
//  ExamenFinal_Pregunta2
//
//  Created by Daniel on 01/12/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __ExamenFinal_Pregunta2__Cliente__
#define __ExamenFinal_Pregunta2__Cliente__

#include <iostream>
#include "Llamada.h"
#include <list>

using namespace std;

class Cliente{
public:
    Cliente();
    Cliente(int);
    Cliente(string _nombre, string _apellidoP, string _apellidoM, string _sexo, string _direccion, int _edad, int _telefono):nombre(_nombre), apellidoP(_apellidoP), apellidoM(_apellidoM), sexo(_sexo), direccion(_direccion), edad(_edad), telefono(_telefono){};
    
    string nombre, apellidoP, apellidoM, sexo, direccion;
    int edad, telefono;
    
    list<Llamada> registro;
    
    void realizarLlamada(Operador*);
};

#endif /* defined(__ExamenFinal_Pregunta2__Cliente__) */
