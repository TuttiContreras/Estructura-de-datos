//
//  main.cpp
//  ListasEnlazadas
//
//  Created by Daniel on 29/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include <string>
#include "ListaEnlazada.h"

int main(int argc, const char * argv[]) {
    
//    Nodo<int> * entero = new Nodo<int>(35);
//    std::cout<<*entero<<std::endl;
//    
//    Nodo<float>* flotante = new Nodo<float>(1.35);
//    std::cout<<* flotante<<std::endl;
//    
//    Nodo<char>* caracter = new Nodo<char>('A');
//    std::cout<<* caracter<<std::endl;
//    
//    Nodo<std::string> *cadena = new Nodo<std::string>("Cadena");
//    std::cout<<* cadena<<std::endl;
//    
//    
//    delete entero;
//    delete flotante;
//    delete caracter;
//    delete cadena;
    
    ListaEnlazada<int> * numerosEnteros = new ListaEnlazada<int>();
    
    numerosEnteros->insertFront(1);
    numerosEnteros->insertBack(2);
    numerosEnteros->insertBack(3);
    numerosEnteros->insertFront(0);
    numerosEnteros->insertAt(4, 2);
    
    std::cout<< *numerosEnteros<<std::endl;
    
    
    
    Nodo<int> * borrado = numerosEnteros->deleteAt(2);
    
    std::cout<< "Nodo borrado: "<< *borrado<<std::endl;
    std::cout<< *numerosEnteros<<std::endl;
    
    
    
    delete numerosEnteros;
    delete borrado;
    
    return 0;
}
