//
//  Libro.h
//  Tarea2Ejercicio1
//
//  Created by Daniel on 02/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea2Ejercicio1__Libro__
#define __Tarea2Ejercicio1__Libro__

#include <iostream>
class Libro{
public:
    std::string titulo, autor, editorial;
    int numPag, edicion, dia, mes, ano;
    
    Libro(std::string _titulo, std::string _autor, std::string _editorial, int _numPag, int _edicion, int _dia, int _mes, int _ano):titulo(_titulo), autor(_autor), editorial(_editorial), numPag(_numPag), edicion(_edicion), dia(_dia), mes(_mes), ano(_ano){
    }
    
    Libro();
    Libro(int);
    
    bool operator > (Libro &);
    bool operator < (Libro &);
    friend std::ostream & operator <<(std::ostream &, Libro &);
    
};

#endif /* defined(__Tarea2Ejercicio1__Libro__) */
