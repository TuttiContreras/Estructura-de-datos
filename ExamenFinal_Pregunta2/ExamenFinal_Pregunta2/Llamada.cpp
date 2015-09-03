//
//  Llamada.cpp
//  ExamenFinal_Pregunta2
//
//  Created by Daniel on 01/12/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Llamada.h"

Llamada::Llamada(Operador* o){
    atendio = o;
//    turno = o->turno;
    srand((int)time(NULL));
    hora = rand() % 24;
    dia = rand() % 30;
    mes = rand() % 12;
    ano = 2014;
    duracion = rand() % 300;
}