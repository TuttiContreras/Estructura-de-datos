//
//  main.cpp
//  Tarea4Ejercicio3
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ListaCircular.h"
#include "Server.h"
#include "Token.h"

int main(int argc, const char * argv[]) {
    
    ListaCircular<Server*> *ring = new ListaCircular<Server*>;
    Token * t = new Token();
    
    
    // Anillo de 5 computadoras
    Server * s1 = new Server(1001);
    Server * s2 = new Server(1002);
    Server * s3 = new Server(1003);
    Server * s4 = new Server(1004);
    Server * s5 = new Server(1005);
    ring->insertBack(s1);
    ring->insertBack(s2);
    ring->insertBack(s3);
    ring->insertBack(s4);
    ring->insertBack(s5);
    
    // Ciclo de circulación del Token durante 20 vueltas
    
    int cont = 0;
    
    
    
    Nodo<Server*> * temp = new Nodo<Server*>;
    temp = ring->At(0);
    while (cont <20*5){
        if (t->ocupado) {
            int d =t->verificar(temp->getInfo()->address);
            if(d == 1){
                temp->getInfo()->recibir(t->mnsj);
            }
        }
        else if (temp->getInfo()->envio){
//            std::cout<<"enviar"<<std::endl;
            t->setMensaje(temp->getInfo()->m);
        }
        
        if(cont == 3){
            s3->enviar();
        }
        if (cont == 4){
            s1->enviar();
        }
        
        temp = temp->getSiguiente();
        ++cont;
    }
    
    
    std::cout<<"Computadoras: "<<std::endl;
    for (int i = 0; i < ring->size(); ++i){
        
        std::cout<<*ring->At(i)->getInfo()<<std::endl;
    }
    
    delete t;
    delete ring;
    return 0;
}
