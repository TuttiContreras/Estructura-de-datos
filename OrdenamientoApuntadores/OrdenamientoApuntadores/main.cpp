//
//  main.cpp
//  OrdenamientoApuntadores
//
//  Created by Daniel on 25/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>


int main(int argc, const char * argv[]) {
    
    int n;
    std::cout<<"De cuantos numeros quiere su arreglo?\n";
    std::cin>>n;
    
    int * numeros = new int [n];
    int * final = numeros + n;
    int i = 0;
    
    for (int * aux = nuemros; aux < final; ++aux){
        std::cout<<"numeros["<<i++<<"] = "<< *aux << " ";
        std::cin>>*aux;
    }
    
    return 0;
}
