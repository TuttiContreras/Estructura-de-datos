//
//  Token.h
//  Tarea4Ejercicio3
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea4Ejercicio3__Token__
#define __Tarea4Ejercicio3__Token__

#include <iostream>
#include "Mensaje.h"

class Token{
public:
    Token();
    int verificar(int);
    void setMensaje(Mensaje*);
    Mensaje* entregarMensaje();
    Mensaje* mnsj;
    bool ocupado;
    
private:
    int remitente;
    int destino;
};

#endif /* defined(__Tarea4Ejercicio3__Token__) */
