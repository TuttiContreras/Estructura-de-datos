//
//  Pista.cpp
//  Aeropuerto
//
//  Created by Daniel on 01/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Pista.h"

Pista::Pista(){
    ocupied = false;
    plane = nullptr;
}

//Pista::~Pista(){
//    if(plane != NULL){
//        delete plane;
//    }
//}

void Pista::inputPlane(Cola<Avion*> *c){
    if(!ocupied){
        if(c->size() != 0){
            plane = c->deQue()->getInfo();
            ocupied = true;
            std::cout<<"El avion: "<<plane->getID()<<" entró a la pista"<<std::endl;
        }
        else{
            std::cout<<"No hay aviones esperando"<<std::endl;
        }
        
    }
    else{
        std::cout<< "Pista ocupada!"<<std::endl;
    }
}

void Pista::outputPlane(){
    if(ocupied){
        std::cout<<"El avion: "<<plane->getID()<<" salió de la pista"<<std::endl;
        delete plane;
        ocupied = false;
        
    }
    else{
        std::cout<< "Pista vacía!"<<std::endl;
    }
}