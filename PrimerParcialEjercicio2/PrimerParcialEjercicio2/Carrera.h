//
//  Carrera.h
//  PrimerParcialEjercicio2
//
//  Created by Daniel on 08/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __PrimerParcialEjercicio2__Carrera__
#define __PrimerParcialEjercicio2__Carrera__

#include <iostream>
#include "Asignatura.h"

class Carrera{
public:
    Carrera();
    Carrera(std::string);
    int numAsign = 5;
    std::string nombre;
    int montoTotal;
    Asignatura* asign;
    void buscarMayor();
    void buscarMayorMonto();
    void imprimir();
};

#endif /* defined(__PrimerParcialEjercicio2__Carrera__) */
