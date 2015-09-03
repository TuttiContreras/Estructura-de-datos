//
//  Persona.h
//  ListasEjercicio1
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __ListasEjercicio1__Persona__
#define __ListasEjercicio1__Persona__

#include <iostream>
#include "Transaccion.h"
#include "ListaEnlazada.h"

class Persona{
    Persona();
    ListaEnlazada<Transaccion*> * listaT = new ListaEnlazada<Transaccion*>();
};

Persona::Persona(){
    
}

#endif /* defined(__ListasEjercicio1__Persona__) */
