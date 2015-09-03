//
//  main.cpp
//  SegundoParcialEjercicio1
//
//  Created by Daniel on 23/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Estudiante.h"

void porcentajes(Estudiante * e);
Estudiante * masRelaciones(ListaEnlazada<Estudiante*> *l);
void masEstable(ListaEnlazada<Estudiante *> * l);

int main(int argc, const char * argv[]) {
    
    ListaEnlazada<Estudiante*>* bDEstudiantes = new ListaEnlazada<Estudiante*>;
    Estudiante * e1 = new Estudiante("Pedro", 3);
    Estudiante * e2 = new Estudiante("Alejandro", 4);
    Estudiante * e3 = new Estudiante("Daniel", 5);
    Estudiante * e4 = new Estudiante("Juan", 3);
    
    bDEstudiantes->insertBack(e1);
    bDEstudiantes->insertBack(e2);
    bDEstudiantes->insertBack(e3);
    bDEstudiantes->insertBack(e4);
    
    e1->nuevaRelacion(e2, 1);
    e2->nuevaRelacion(e4, 2);
    
    for (int i = 0; i< bDEstudiantes->size(); ++i){
        std::cout<<*bDEstudiantes->At(i)->getInfo();
        std::cout<<std::endl;
    }
    
    std::cout<<"Los estudiante que no han tenido relaciones son: "<<std::endl;
    for (int j = 0; j < bDEstudiantes->size(); ++j) {
        if (bDEstudiantes->At(j)->getInfo()->relaciones->empty()) {
            std::cout<<*bDEstudiantes->At(j)->getInfo();
        }
    }
    
    porcentajes(e2);
    masEstable(bDEstudiantes);
    
    delete bDEstudiantes;
    return 0;
}

Estudiante * masRelaciones(ListaEnlazada<Estudiante*> *l){
    Estudiante * m = l->At(0)->getInfo();
    for (int i = 0; i < l->size(); ++i) {
        if(l->At(i)->getInfo() > m){
            m = l->At(i)->getInfo();
        }
    }
    return m;
}

void porcentajes(Estudiante * e){
    int por = e->porcentajeT();
    std::cout<<"El  porcentaje de tiempo que el estudiante "<< e->nombre << " ha pasado acompañado es: " << por << std::endl;
    std::cout<<"Solo: " << (100-por)<<std::endl;
}

void masEstable(ListaEnlazada<Estudiante *> * l){
    Estudiante * m = l->At(0)->getInfo();
    for (int i = 0; i < l->size(); ++i) {
        if (l->At(i)->getInfo()->porcentaje() > m->porcentaje()) {
            m = l->At(i)->getInfo();
        }
    }
    
    std::cout<<"El estudiante mas estable es: "<<m->nombre;
}
