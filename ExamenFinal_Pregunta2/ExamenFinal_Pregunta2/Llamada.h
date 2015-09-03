//
//  Llamada.h
//  ExamenFinal_Pregunta2
//
//  Created by Daniel on 01/12/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __ExamenFinal_Pregunta2__Llamada__
#define __ExamenFinal_Pregunta2__Llamada__

#include <iostream>

class Operador;

using namespace std;

class Llamada{
private:
    
public:
    Llamada(Operador*);
    
    string turno;
    int hora, dia, mes, ano, duracion;
    Operador* atendio;
};

#endif /* defined(__ExamenFinal_Pregunta2__Llamada__) */
