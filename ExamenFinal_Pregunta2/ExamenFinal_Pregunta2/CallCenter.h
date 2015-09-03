//
//  CallCenter.h
//  ExamenFinal_Pregunta2
//
//  Created by Daniel on 01/12/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __ExamenFinal_Pregunta2__CallCenter__
#define __ExamenFinal_Pregunta2__CallCenter__

#include <iostream>
#include "Operador.h"
#include "Cliente.h"
#include "Busqueda.h"
#include "Ordenamiento.h"
#include <list>
#include <queue>
#include <map>

class CallCenter{
public:
    CallCenter();
    CallCenter(int);
    ~CallCenter();
    
    int numOperadores, total;
    Operador** operadores;
    queue<Cliente*> *espera;
    map<int, Cliente*> clientes;
    
    bool agregarOperador(Operador*);
    bool atenderLlamada(Cliente*);
    bool terminarLlamada(Operador*);
    void agregarCliente(Cliente*);
    Cliente * preguntar();
    
    void reporte();
    
};

#endif /* defined(__ExamenFinal_Pregunta2__CallCenter__) */
