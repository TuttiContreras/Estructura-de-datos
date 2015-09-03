//
//  Vuelo.cpp
//  TorreDeControl
//
//  Created by Catalina Peralta on 11/1/14.
//  Copyright (c) 2014 Catalina Peralta. All rights reserved.
//

#include "Vuelo.h"

Vuelo::Vuelo()
{
    std::cout<<"Destino: ";
    std::cin>>airport;
    std::cout<<"Numero de pasajeros: ";
    std::cin>>passengers;
    std::cout<<"Numero de vuelo: ";
    std::cin>>flightNum;
    std::cout<<"Hora: ";
    Hora hora(1);
    time = hora;
}

void Vuelo::setPassengers(int value)
{
    passengers += value;
}

int Vuelo::getPassengers()
{
    return passengers;
}

void Vuelo::setTime(Hora value)
{
    time = value;
}

Hora Vuelo::getTime()
{
    return time;
}

void Vuelo::setAirport(std::string a){
    airport = a;
}

std::string Vuelo::getAirport(){
    return airport;
}

void Vuelo::setFlightNum(int n){
    flightNum = n;
}

int Vuelo::getFlightNum(){
    return flightNum;
}

bool Vuelo::operator<(Vuelo *v){
    if(this->time < v->time){
        return true;
    }
    return false;
}

std::ostream & operator <<(std::ostream & os, Vuelo & v){
    os << "Número de vuelo: " << v.getFlightNum() << std::endl;
    os << "Destino: " << v.getAirport() << std::endl;
    os << "Hora: " << v.time ;
    os << "Nùmero de pasajeros: " << v.getPassengers()<<std::endl;
    return os;
}