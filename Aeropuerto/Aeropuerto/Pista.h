//
//  Pista.h
//  Aeropuerto
//
//  Created by Daniel on 01/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Aeropuerto__Pista__
#define __Aeropuerto__Pista__

#include <iostream>
#include "Avion.h"
#include "Cola.h"

class Pista{
public:
    Pista();
//    ~Pista();
    
    Avion* plane;
    bool ocupied;
    
    void inputPlane(Cola<Avion*> * c);
    void outputPlane();
};

#endif /* defined(__Aeropuerto__Pista__) */
