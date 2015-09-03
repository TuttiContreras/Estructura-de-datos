//
//  Relacion.h
//  SegundoParcialEjercicio1
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __SegundoParcialEjercicio1__Relacion__
#define __SegundoParcialEjercicio1__Relacion__

#include <iostream>



class Relacion{
public:
    Relacion();
    Relacion(std::string, int);
    std::string estudianteU;
    int tiempo;
    
    friend std::ostream & operator <<(std::ostream & os, Relacion & r);
};

#endif /* defined(__SegundoParcialEjercicio1__Relacion__) */
