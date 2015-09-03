//
//  Operador.cpp
//  ExamenFinal_Pregunta2
//
//  Created by Daniel on 01/12/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Operador.h"

Operador::Operador(){
    
}

void Operador::nuevaLlamada(Llamada l){
    int mult;
    if(turno == "Matutino" || turno == "Vespertino"){
        mult = 1;
    }
    else{
        mult = 3;
    }
    
    productividad += mult * (l.duracion);
    registro.push_back(l);
}

bool Operador::operator<(Operador *o){
    return productividad < o->productividad;
}

ostream& operator <<(ostream & os, Operador & o){
    os << o.nombre << endl;
    os << o.apellidoP <<endl;
    os << o.apellidoM << endl;
    os << o.productividad << endl;
    return os;
}