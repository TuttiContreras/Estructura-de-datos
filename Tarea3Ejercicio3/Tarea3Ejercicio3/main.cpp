//
//  main.cpp
//  Tarea3Ejercicio3
//
//  Created by Daniel on 07/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Persona.h"
#include "ListaEnlazada.h"

typedef void (*t_opciones)(ListaEnlazada<Persona>*);

// Declaracion de funciones
void agregar(ListaEnlazada<Persona>* l);
void borrar(ListaEnlazada<Persona> *l);
void datos(ListaEnlazada<Persona> *l);
void imprimir(ListaEnlazada<Persona> *l);
void vaciar(ListaEnlazada<Persona> *l);
void tamano(ListaEnlazada<Persona> *l);
Persona * crear();

int main(int argc, const char * argv[]) {
    
    ListaEnlazada<Persona> * agenda = new ListaEnlazada<Persona>();
    
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
    
    
    delete agenda;
    return 0;
}

void agregar(ListaEnlazada<Persona> * l){
    
    std::cout<<"Ingresar:\n1) Al principio\2) Al final\n3) Posición dada"<<std::endl;
    int opcion;
    std::cin>>opcion;
    
    if(opcion == 1){
        l->insertFront(*crear());
    }
    else if(opcion == 2){
        l->insertBack(*crear());
    }
    else if(opcion == 3){
        std::cout<<"Posición: (Empezando en 1)";
        int pos;
        std::cin>>pos;
        
        if((pos-1 <= l->tamano) && (pos-1 >= 0)){
            Persona* temp = new Persona(1);
            l->insertAt(*temp, pos-1);
            delete temp;
        }
        else{
            std::cout<<"Esa posición es incorrecta"<<std::endl;
        }
    }
    else{
        std::cout<<"Valor no asignado"<<std::endl;
    }
    
    

}

void borrar(ListaEnlazada<Persona> *l){
   
    std::cout<<"Borrar:\n1) Al principio\2) Al final\n3) Posición dada"<<std::endl;
    int opcion;
    std::cin>>opcion;
    if(opcion == 1){
        l->deleteFront();
    }
    else if (opcion == 2){
        l->deleteBack();
    }
    else if(opcion == 3){
        std::cout<<"Posición: ";
        int pos;
        std::cin>>pos;
        if(pos-1 < l->tamano && pos-1 >= 0){
            l->deleteAt(pos-1);
        }
        else{
            std::cout<<"Esa posición no existe"<<std::endl;
        }
    }
    else{
        std::cout<<"Esa pocion no es valida"<<std::endl;
    }
    
    
}

void datos(ListaEnlazada<Persona> * l){
    std::cout<<"Posición: ";
    int pos;
    std::cin>>pos;
    
    if(pos-1 < l->tamano && pos-1 >= 0){
        std::cout<<l->At(pos-1)->getInfo();
        std::cout<<std::endl;
    }
    else{
        std::cout<<"Esa posición es incorrecta"<<std::endl;
    }
}

void imprimir(ListaEnlazada<Persona> *l){
    std::cout<<*l;
    std::cout<<std::endl;
}

void vaciar(ListaEnlazada<Persona> *l){
    l->clear();
}

void tamano(ListaEnlazada<Persona> *l){
    std::cout<<"Número de Personas: "<<l->tamano<<std::endl;
}

Persona * crear(){
    Persona* temp = new Persona(1);
    return temp;
}