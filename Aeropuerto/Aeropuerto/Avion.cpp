//
//  Avion.cpp
//  TorreDeControl
//
//  Created by Catalina Peralta on 11/1/14.
//  Copyright (c) 2014 Catalina Peralta. All rights reserved.
//

#include "Avion.h"

Avion::Avion(){
    airline = "None";
    numSeats = 0;
    iD = 0;
}

void Avion::setFlight(Vuelo *v){
    flight = v;
}

void Avion::setFlight(){
    flight = new Vuelo();
}

void Avion::setID(int iD)
{
    this->iD = iD;
}

int Avion::getID(){
    return iD;
}

bool Avion::operator<(Avion *a){
    if (this->flight < a->flight) {
        return true;
    }
    return false;
}

std::ostream & operator <<(std::ostream & os, Avion & a){
    os << std::endl << "-------";
    os << "Numero de avión: " << a.iD << "------" <<std::endl;
    os << "Aerolinea: " << a.airline << std::endl;
    if(a.flight != nullptr){
        os << "Vuelo: "<<std::endl;
        os << *(a.flight);
    }
    else{
        os << "Estacionado" << std::endl;
    }
    return os;
}
