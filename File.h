//
//  File.h
//  
//
//  Created by Daniel on 14/08/14.
//
//

#ifndef ____File__
#define ____File__

#include <iostream>

enum Valores {cero, uno, dos, tres};
//hasta el 255

class Entero{
private:
    enum Valores valor;
    
public:
    Entero suma(Entero e) = 0;
    Entero resta(Entero e) = 0;
};

class Binario :Entero{
private:
    Entero bin[8];
public:
    void EnteroABinario(Entero e) =0;
};

class Flotante:Entero{
private:
    Entero fraccion;
public:
    //funciones para crear la funcion
}

#endif /* defined(____File__) */
