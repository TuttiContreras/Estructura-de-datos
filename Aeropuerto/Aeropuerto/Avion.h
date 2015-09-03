//
//  Avion.h
//  TorreDeControl
//
//  Created by Catalina Peralta on 11/1/14.
//  Copyright (c) 2014 Catalina Peralta. All rights reserved.
//

#ifndef __TorreDeControl__Avion__
#define __TorreDeControl__Avion__

#include <stdio.h>
#include <iostream>
#include "Vuelo.h"

class Avion
{
private:
    Vuelo* flight = nullptr;
    std::string airline;
    int numSeats, iD;
    
public:
    Avion();
    Avion(int _iD, std::string _airline, int _numSeats):iD(_iD), airline(_airline), numSeats(_numSeats){};
    void setFlight(Vuelo *v);
    void setFlight();
    Vuelo* getFlight();
    void setID(int iD);
    int getID();
    
    bool operator <(Avion* a);
    friend std::ostream & operator <<(std::ostream & os, Avion & a);
};

#endif /* defined(__TorreDeControl__Avion__) */
