//
//  Biblioteca.h
//  Tarea2Ejercicio1
//
//  Created by Daniel on 04/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea2Ejercicio1__Biblioteca__
#define __Tarea2Ejercicio1__Biblioteca__

#include <iostream>
#include "Libro.h"

class Biblioteca{
public:
    
    Biblioteca();
    
    int num = 20;
    int cont;
    Libro* libros;
    void agregar();
    void quitar();
    int buscarAutor(std::string);
    void buscarFecha(bool(*)(int, int, int,Libro));
    void buscarIntervaloFechas(bool(*)(int, int, int, Libro));
    void imprimir();
    
    static bool may(int, int,int, Libro);
    static bool men(int, int,int,Libro);
};

bool Biblioteca::may(int d, int m, int a, Libro b){
    if(a < b.ano){
        return true;
    }
    else if(m < b.mes){
        return true;
    }
    else if(d < b.dia){
        return true;
    }
    else{
        return false;
    }
}

bool Biblioteca::men(int d, int m, int a, Libro b){
    if(a > b.ano){
        return true;
    }
    else if(m > b.mes){
        return true;
    }
    else if(d > b.dia){
        return true;
    }
    else{
        return false;
    }
    
    
#endif /* defined(__Tarea2Ejercicio1__Biblioteca__) */
