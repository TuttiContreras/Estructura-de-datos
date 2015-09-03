//
//  main.cpp
//  Tarea3Ejercicio4
//
//  Created by Daniel on 07/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ListaOrdenada.h"
#include "Persona.h"

typedef void (*t_opciones)(ListaOrdenada<Persona>*);

// Declaracion de funciones
void agregar(ListaOrdenada<Persona>* l);
void borrar(ListaOrdenada<Persona> *l);
void datos(ListaOrdenada<Persona> *l);
void imprimir(ListaOrdenada<Persona> *l);
void vaciar(ListaOrdenada<Persona> *l);
void tamano(ListaOrdenada<Persona> *l);

int main(int argc, const char * argv[]) {
    
    ListaOrdenada<int> * numeros = new ListaOrdenada<int>();
    
    numeros->insert(2);
    numeros->insert(3);
    numeros->insert(1);
    std::cout<<*numeros;
    
    
    ListaOrdenada<Persona> * agenda = new ListaOrdenada<Persona>();
    
    // Menu de opciones
    bool activo = true;
    int opcion;
    t_opciones opciones[6];
    opciones[0] = agregar;
    opciones[1] = borrar;
    opciones[2] = datos;
    opciones[3] = imprimir;
    opciones[4] = vaciar;
    opciones[5] = tamano;
    
    
    while(activo){
        std::cout<<"--------Menu---------"<<std::endl;
        std::cout<<"1) Agregar Persona\n2) Borrar Persona\n3) Obtener Datos\n4) Imprimir Agenda\n5) Borrar Agenda\n6) Determinar la cantidad de personas\n0) Salir"<<std::endl;
        
        std::cin>>opcion;
        if(opcion == 0){
            activo = false;
        }
        else{
            opciones[opcion-1](agenda);
        }
    }
    
    
    std::cout<<*agenda;
    
    
    delete numeros;
    delete agenda;
    return 0;
}

void agregar(ListaOrdenada<Persona> * l){
    Persona* temp = new Persona(1);
    l->insert(*temp);
    delete temp;
    
}

void borrar(ListaOrdenada<Persona> *l){
    std::cout<<"Posición: ";
    int pos;
    std::cin>>pos;
    if(pos-1 < l->getTamano() && pos-1 >= 0){
        l->deleteAt(pos-1);
    }
    else{
        std::cout<<"Esa posición no existe"<<std::endl;
    }
    
}

void datos(ListaOrdenada<Persona> * l){
    std::cout<<"Posición: ";
    int pos;
    std::cin>>pos;
    
    if(pos-1 < l->getTamano() && pos-1 >= 0){
        std::cout<<l->At(pos-1)->getInfo();
        std::cout<<std::endl;
    }
    else{
        std::cout<<"Esa posición es incorrecta"<<std::endl;
    }
}

void imprimir(ListaOrdenada<Persona> *l){
    std::cout<<*l;
    std::cout<<std::endl;
}

void vaciar(ListaOrdenada<Persona> *l){
    l->vaciar();
}

void tamano(ListaOrdenada<Persona> *l){
    std::cout<<"Número de Personas: "<<l->getTamano()<<std::endl;
}

Persona * crear(){
    Persona* temp = new Persona(1);
    return temp;
}
