//
//  Token.cpp
//  Tarea4Ejercicio3
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Token.h"

Token::Token(){
    remitente = 0;
    destino = 0;
    mnsj = nullptr;
}

int Token::verificar(int i){
    if(i == remitente){
        if(mnsj == nullptr){
            std::cout<<"Su mensaje fue recibido"<<std::endl;
            remitente = 0;
            ocupado = false;
        }
        return 2;
    }
    else if (i == destino){
        destino = 0;
        return 1;
    }
    else{
        return 0;
    }
}

void Token::setMensaje(Mensaje* m){
    mnsj = m;
    destino = m->dirDestino;
    remitente = m->dirOrigen;
    ocupado = true;
}

Mensaje* Token::entregarMensaje(){
    Mensaje * nuevo = new Mensaje(mnsj->dirOrigen, mnsj->dirDestino, mnsj->mnsj);
    mnsj = nullptr;
    return nuevo;
}