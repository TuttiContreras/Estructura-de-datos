//
//  Pantalla.h
//  Tarea4Ejercicio4
//
//  Created by Daniel on 18/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Tarea4Ejercicio4__Pantalla__
#define __Tarea4Ejercicio4__Pantalla__

#include <iostream>
#include <curses.h>
#include "ListaDoblementeEnlazada.h"

class Pantalla{
public:
    static void printMenu();
    static void print(ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> *);
    static void printOpciones();
    static ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> * editor(ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> *);
    static ListaDoblementeEnlazada<char> * nuevaLinea(ListaDoblementeEnlazada<char> *, int);
    
    static bool curses_ON;
    static void endCurses();
    static void startCurses();
    static const int ESC = 27;
    static const int UP = 259;
    static const int DOWN = 258;
    static const int LEFT = 260;
    static const int RIGHT = 261;
    static const int BACKSPACE = 127;
    
};



#endif /* defined(__Tarea4Ejercicio4__Pantalla__) */
