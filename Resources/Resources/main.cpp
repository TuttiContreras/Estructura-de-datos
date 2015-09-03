//
//  main.cpp
//  Resources
//
//  Created by Daniel on 29/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Ordenamiento.h"
#include "Busqueda.h"
#include "Grafo.h"
#include "ArbolBinario.h"
#include <list>

using namespace std;

void operator << (ostream & os, list<int> & l);

int main(int argc, const char * argv[]) {
    
    
    list<int> * lista = new list<int>;
    
    lista->push_back(1);
    lista->push_back(3);
    lista->push_back(2);
    
    cout<<*lista;
    
    lista->sort();
    
    cout<<*lista;
    
    delete lista;
    return 0;
}

void operator << (ostream & os, list<int> & l){
    for (auto item:l){
        os << item << " ";
    }
    cout << endl;
}