//
//  ArbolGenealogico.cpp
//  Tarea5Ejercicio4
//
//  Created by Daniel on 13/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "ArbolGenealogico.h"

ArbolGenealogico::ArbolGenealogico(){
    arbol = new ArbolBinario<Persona>;
    std::cout<<"Cabeza:"<<std::endl;
    Persona cabeza(1);
    arbol->insert(cabeza, nullptr);
}

ArbolGenealogico::~ArbolGenealogico(){
    delete arbol;
}

Persona ArbolGenealogico::getPatriarca(){
    return arbol->getRaiz()->getInfo();
}

void ArbolGenealogico::agregarHijo(Persona p, Persona h){
//    std::cout<<"agregar"<<std::endl;
    arbol->insert(h, p);
}

void ArbolGenealogico::agregarHijo(){
    std::cout<<"Padre: "<<std::endl;
    std::string r;
    Persona p;
    std::cout<<"Nombre: ";
    std::cin>>p.getNombre();
    std::cout<<"Apellido Paterno: ";
    std::cin>>p.getApellidoP();
    std::cout<<"Apellido Materno: ";
    std::cin>>p.getApellidoM();
    std::cout<<std::endl<< "Hijo: ";
    Persona q(1);
    arbol->insert(q, p);
}

void ArbolGenealogico::decendientesDe(Persona p){
    std::cout<<&arbol->imprime(std::cout, arbol->buscar(p));
}

void ArbolGenealogico::decendientesDe(){
    Persona p;
    std::cout<<"Decendientes de: "<<std::endl;
    std::cout<<"Nombre: ";
    std::cin>>p.getNombre();
    std::cout<<"Apellido Paterno: ";
    std::cin>>p.getApellidoP();
    std::cout<<"Apellido Materno: ";
    std::cin>>p.getApellidoM();
    decendientesDe(p);
}

void ArbolGenealogico::getHermanoPrimos(){
    Persona p;
    std::cout<<"Hermano y primos de: "<<std::endl;
    std::cout<<"Nombre: ";
    std::cin>>p.getNombre();
    std::cout<<"Apellido Paterno: ";
    std::cin>>p.getApellidoP();
    std::cout<<"Apellido Materno: ";
    std::cin>>p.getApellidoM();
    NodoB<Persona>* papa = arbol->buscar(p)->getPadre();
    NodoB<Persona>* temp;
    if (papa->getDerecho()->getInfo() == p) {
        temp = papa->getIzquierdo();
    }
    else{
        temp = papa->getDerecho();
    }
    
    std::cout<<"Hermano: "<<std::endl;
    temp->getInfo().imprimir();
    std::cout<<std::endl;
    std::cout<<"Primos: " <<std::endl;
    
    if (papa == papa->getPadre()->getIzquierdo()){
        temp = papa->getPadre()->getDerecho();
    }
    else{
        temp = papa->getPadre()->getIzquierdo();
    }
    temp->getIzquierdo()->getInfo().imprimir();
    temp->getDerecho()->getInfo().imprimir();
}

void ArbolGenealogico::getAncestros(){
    Persona p;
    std::cout<<"Ancestros de: "<<std::endl;
    std::cout<<"Nombre: ";
    std::cin>>p.getNombre();
    std::cout<<"Apellido Paterno: ";
    std::cin>>p.getApellidoP();
    std::cout<<"Apellido Materno: ";
    std::cin>>p.getApellidoM();
    getAncestros(arbol->buscar(p));
}

void ArbolGenealogico::getAncestros(NodoB<Persona> * p){
    if (p->getPadre()) {
        p->getPadre()->getInfo().imprimir();
        getAncestros(p->getPadre()->getPadre());
    }
}

void ArbolGenealogico::fallecidos(){
    int ano;
    std::cout<<"Personas fallecida antes de: ";
    std::cin>>ano;
    fallecidos(arbol->getRaiz(), ano);
    
}

void ArbolGenealogico::fallecidos(NodoB<Persona> *p, int year){
    if (p->getIzquierdo()) {
        if(p->getIzquierdo()->getInfo()  < year){
            p->getIzquierdo()->getInfo().imprimir();
        }
        fallecidos(p->getIzquierdo(), year);
    }
    if (p->getDerecho()) {
        if (p->getDerecho()->getInfo() < year){
            p->getDerecho()->getInfo().imprimir();
        }
        fallecidos(p->getDerecho(), year);
    }
}

void ArbolGenealogico::matar(){
    Persona p;
    std::cout<<"Persona fallecida: "<<std::endl;
    std::cout<<"Nombre: ";
    std::cin>>p.getNombre();
    std::cout<<"Apellido Paterno: ";
    std::cin>>p.getApellidoP();
    std::cout<<"Apellido Materno: ";
    std::cin>>p.getApellidoM();
    if(arbol->buscar(p)){
        arbol->buscar(p)->getInfo().Matar();
    }
}

void ArbolGenealogico::vivos(){
    std::cout<<"Familiares vivos: "<<std::endl;
    vivos(arbol->getRaiz());
}

void ArbolGenealogico::vivos(NodoB<Persona> *p){
    if(p){
        if(!p->getInfo().getMuerto()){
            p->getInfo().imprimir();
        }
        vivos(p->getIzquierdo());
        vivos(p->getDerecho());
    }
}

std::ostream & operator <<(std::ostream & os, ArbolGenealogico & a){
    os <<*(a.arbol);
    return os;
}