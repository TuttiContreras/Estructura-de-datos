//
//  Ciudad.h
//  Grafo
//
//  Created by Vicente Cubells Nonell on 03/11/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __Grafo__Ciudad__
#define __Grafo__Ciudad__

#include <iostream>
#include <string>

class Ciudad {
    std::string nombre;
    int habitantes;
    
    public:
    
    Ciudad();
    Ciudad(std::string nombre, int hab);
    
    friend std::ostream & operator <<(std::ostream & os, Ciudad  ciudad);
};

#endif /* defined(__Grafo__Ciudad__) */
