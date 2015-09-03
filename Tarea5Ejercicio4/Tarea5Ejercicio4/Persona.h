//
//  Persona.h
//  Tarea5Ejercicio4
//
//  Created by Daniel on 13/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea5Ejercicio4__Persona__
#define __Tarea5Ejercicio4__Persona__

#include <iostream>

class Persona{
private:
    std::string nombre, apellidoP, apellidoM, sexo;
    int edad, fechaFallecido;
    bool muerto;
public:
    Persona();
    Persona(int);
    Persona(std::string _nombre, std::string _apellidoP, std::string _apellidoM, std::string _sexo, int _edad):nombre(_nombre), apellidoP(_apellidoP), apellidoM(_apellidoM), sexo(_sexo), edad(_edad), fechaFallecido(NULL), muerto(false){};
    void Matar();
    void imprimir();
    
    std::string& getNombre();
    std::string& getApellidoP();
    std::string& getApellidoM();
    int getFechaF();
    bool getMuerto();
    
    bool operator <(int ano);
    bool operator ==(Persona &);
    
    friend std::ostream & operator <<(std::ostream & os, Persona & p);
};

#endif /* defined(__Tarea5Ejercicio4__Persona__) */
