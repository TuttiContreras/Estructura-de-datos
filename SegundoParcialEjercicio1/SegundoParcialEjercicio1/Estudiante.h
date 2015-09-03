//
//  Estudiante.h
//  SegundoParcialEjercicio1
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __SegundoParcialEjercicio1__Estudiante__
#define __SegundoParcialEjercicio1__Estudiante__

#include <iostream>
#include "ListaEnlazada.h"
#include "Relacion.h"

class Estudiante{
    
public:
    
    std::string nombre;
    int tiempoTU;
    
    Estudiante();
    Estudiante(std::string, int);
    ~Estudiante();
    
    ListaEnlazada<Relacion *> * relaciones = new ListaEnlazada<Relacion *>;
    
    void nuevaRelacion(Estudiante *, int);
    int porcentajeT();
    float porcentaje();
    
    friend std::ostream & operator <<(std::ostream & os, Estudiante & e);
    bool operator >(const Estudiante &);
};

#endif /* defined(__SegundoParcialEjercicio1__Estudiante__) */
