//
//  main.cpp
//  Grafo
//
//  Created by Daniel on 03/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Grafo.h"
#include "Ciudad.h"

int main(int argc, const char * argv[]) {
    Grafo<Ciudad, int> * mapa = new Grafo<Ciudad, int>();
    
    NodoV<Ciudad, int> * df = new NodoV<Ciudad, int>(Ciudad("DF", 22000000));
    NodoV<Ciudad, int> * cuernavaca = new NodoV<Ciudad, int>(Ciudad("Cuernavaca", 500000));
    NodoV<Ciudad, int> * toluca = new NodoV<Ciudad, int>(Ciudad("Toluca", 100000));
    NodoV<Ciudad, int> * pachuca = new NodoV<Ciudad, int>(Ciudad("Pachuca", 250000));
    
    mapa->insertarVertice(df);
    mapa->insertarVertice(cuernavaca);
    mapa->insertarVertice(toluca);
    mapa->insertarVertice(pachuca);
    
    //    mapa->insertarVertice('A');
    //    mapa->insertarVertice('B');
    //    mapa->insertarVertice('C');
    //    mapa->insertarVertice('D');
    
    /* Obtener el tamaño del grafo */
    
    if (mapa->empty()) {
        std::cout << "El grafo está vacío" << std::endl;
    }
    else {
        std::cout << "El grafo tiene " << mapa->size() << " vértices" << std::endl;
    }
    
    /* Adicionar aristas */
    
    mapa->insertarArista(90, df, cuernavaca);
    mapa->insertarArista(55, df, toluca);
    mapa->insertarArista(80, df, pachuca);
    mapa->insertarArista(35, cuernavaca, toluca);
    
    /* Mostrar la información del grafo */
    
    std::cout << *mapa << std::endl;
    
    delete mapa;

    return 0;
}
