//
//  Vuelo.h
//  TorreDeControl
//
//  Created by Catalina Peralta on 11/1/14.
//  Copyright (c) 2014 Catalina Peralta. All rights reserved.
//

#ifndef __TorreDeControl__Vuelo__
#define __TorreDeControl__Vuelo__

#include <iostream>
#include <string>
#include "Hora.h"

class Vuelo
{
private:
    int passengers, flightNum;
    
    std::string airport;
    
public:
    Hora time;
    Vuelo();
    Vuelo(int _flightNum,int _passengers, Hora _time, std::string _airport):flightNum(_flightNum),passengers(_passengers), time(_time), airport(_airport){};
    
    void setPassengers(int value);
    int getPassengers();
    
    void setTime(Hora value);
    Hora getTime();
    
    void setAirport(std::string);
    std::string getAirport();
    
    void setFlightNum(int);
    int getFlightNum();
    
    bool operator <(Vuelo * v);
    
    friend std::ostream & operator <<(std::ostream & os, Vuelo & v);
};

#endif /* defined(__TorreDeControl__Vuelo__) */
