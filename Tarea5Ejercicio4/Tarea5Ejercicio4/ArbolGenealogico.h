//
//  ArbolGenealogico.h
//  Tarea5Ejercicio4
//
//  Created by Daniel on 13/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea5Ejercicio4__ArbolGenealogico__
#define __Tarea5Ejercicio4__ArbolGenealogico__

#include <iostream>
#include "ArbolBinario.h"
#include "Persona.h"

class ArbolGenealogico{
private:
    ArbolBinario<Persona> *arbol;
public:
    ArbolGenealogico();
    ~ArbolGenealogico();
    
    Persona getPatriarca();
    void agregarHijo(Persona, Persona);
    void agregarHijo();
    void decendientesDe(Persona);
    void decendientesDe();
    void getHermanoPrimos();
    void getAncestros();
    void getAncestros(NodoB<Persona>*);
    void fallecidos();
    void fallecidos(NodoB<Persona>*, int);
    void vivos();
    void vivos(NodoB<Persona>*);
    void matar();
    
    friend std::ostream & operator <<(std::ostream & os, ArbolGenealogico & a);
};

#endif /* defined(__Tarea5Ejercicio4__ArbolGenealogico__) */
