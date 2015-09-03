//
//  main.cpp
//  ListasEjercicio1
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include <string>

#define N 4


int main(int argc, const char * argv[]) {
   
    srand((int)time(NULL));
    int temp;
    Cola<int> * cola = new Cola<int>;
    Pila<int> * p = new Pila<int>;
    
    
    std::cout<<"---------- Invertir cola -------"<<std::endl;
    for (int i = 0; i < N; ++i){
        temp = rand()%100;
        cola->enQue(temp);
    }
    std::cout<<*cola<<std::endl;
    
    for (int j = 0; j< N; ++j){
        p->push(cola->deQue()->getInfo());
    }
    
    for (int z = 0; z<N; z++){
        cola->enQue(p->pop()->getInfo());
    }
    
    std::cout<<*cola;
    
    delete p;
    delete cola;
    
    
    std::cout<<"-------- Ejercicio 2 --------"<<std::endl;
    std::string linea;
    std::string palabra;
    Pila<std::string> * palabras = new Pila<std::string>;
    
    std::cout<<"Escriba una frase: "<<std::endl;
    getline(std::cin, linea);
    for (int i = 0; i < linea.length(); ++i){
        palabra = linea[i];
        
        while (linea[i+1] != ' ' && i < linea.length()-1) {
            ++i;
            palabra += linea[i];
        }
        palabras->push(palabra);
    }
    palabra = "";
    int t = palabras->size();
    for (int k = 0; k < t; ++k){
        palabra += palabras->pop()->getInfo();
        palabra += " ";
    }
    
    std::cout<<palabra<<std::endl;
    
    
    
    delete palabras;
    return 0;
}
