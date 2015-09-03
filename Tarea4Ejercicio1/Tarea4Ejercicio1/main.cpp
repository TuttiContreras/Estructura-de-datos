//
//  main.cpp
//  Tarea4Ejercicio1
//
//  Created by Daniel on 15/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Pila.h"

int main(int argc, const char * argv[]) {
    std::string expresion;
    std::cout<<"Inserte la expresión: ";
    std::cin>>expresion;
    
    Pila<char> * exp = new Pila<char>;
    for (int i = 0; i < expresion.length(); ++i) {
        exp->push(expresion[i]);
    }
    
    int cont = 0;
    for (int j = 0; j <expresion.length();++j){
        char c = exp->pop()->getInfo();
        if (cont < 0){
            break;
        }
        else if (c == ')') {
            ++cont;
        }
        else if(c == '('){
            --cont;
        }
    }
    
    if (cont == 0){
        std::cout<<"La expresion está balanceada"<<std::endl;
    }
    else{
        std::cout<<"La expresión no está balanceada"<<std::endl;
    }
    delete exp;
    return 0;
}
