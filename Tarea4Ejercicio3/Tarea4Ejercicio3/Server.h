//
//  Server.h
//  Tarea4Ejercicio3
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea4Ejercicio3__Server__
#define __Tarea4Ejercicio3__Server__

#include <iostream>
#include "ListaEnlazada.h"
#include "Mensaje.h"

class Server{
public:
    Server();
    ~Server();
    Server(int);
    int address;
    void recibir(Mensaje*);
    bool envio;
    void enviar();
    Mensaje* m;
    
    ListaEnlazada<Mensaje*> * mensajes;
    
    friend std::ostream & operator <<(std::ostream &, Server &);
};

#endif /* defined(__Tarea4Ejercicio3__Server__) */
