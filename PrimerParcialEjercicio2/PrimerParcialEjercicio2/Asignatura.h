//
//  Asignatura.h
//  PrimerParcialEjercicio2
//
//  Created by Daniel on 08/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __PrimerParcialEjercicio2__Asignatura__
#define __PrimerParcialEjercicio2__Asignatura__

#include <iostream>
class Asignatura{
public:
    Asignatura();
    int codigo, numAlum, montoT, unidades;
    int montoMin = 1500*45;
    void imprimir();
};

#endif /* defined(__PrimerParcialEjercicio2__Asignatura__) */
