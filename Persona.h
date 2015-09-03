//
//  Persona.h
//  
//
//  Created by Daniel on 14/08/14.
//
//

#ifndef ____Persona__
#define ____Persona__

#include <iostream>

class Persona{
private:
    int hambre;
    int edad;
    int energia;
    int altura;
    int peso;
    
public:
    void comer() = 0;
    void dormir() = 0;
    void crecer() = 0;
    void respirar() = 0;
    void vivir() = 0;
    
};

#endif /* defined(____Persona__) */
