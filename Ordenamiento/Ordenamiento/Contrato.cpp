//
//  Contrato.cpp
//  Ordenamiento
//
//  Created by Daniel on 04/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Contrato.h"

bool Contrato::operator > (Contrato &c){
    if(ano==c.ano){
        if(mes == c.mes){
            return dia>c.dia;
        }
        else{
            return mes>c.mes;
        }
    }
    else{
        return ano>c.ano;
    }
}

bool Contrato::operator < (Contrato &c){
    if(ano==c.ano){
        if(mes == c.mes){
            return dia<c.dia;
        }
        else{
            return mes<c.mes;
        }
    }
    else{
        return ano<c.ano;
    }
}

std::ostream & operator <<(std::ostream & os, Contrato & cont){
    os << cont.numero;
    return os;
}