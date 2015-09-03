//
//  main.cpp
//  TorreDeControl
//
//  Created by Catalina Peralta on 11/1/14.
//  Copyright (c) 2014 Catalina Peralta. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "ListaEnlazada.h"
#include "Cola.h"
#include "Avion.h"
#include "Pista.h"
#include "Ordenamiento.h"

//#define N 4



int main(int argc, const char * argv[]) {
    
    
    int numFlights;
    std::string airportName = "JFK";
    int numberRunways = 4;
    ListaEnlazada<Avion*>* aviones = new ListaEnlazada<Avion*>;
    
    
    
    
    
//    Avion * a1 = new Avion(1,"jk",100);
//    a1->setFlight();
    
//    Avion * a2;// = new Avion();
//    Avion * a3 = new Avion();
//    Avion * a4 = new Avion();
//    a2->setFlight();
//    a3->setFlight();
//    a4->setFlight();
    
//    for(int i=0; i<N; i++)
//    {
//        a2 = new Avion();
//        a2->setID(i+1);
//        a2->setFlight();
//        aviones[i] = a2;
//    }
//    
//    for(int i=0; i<N; i++)
//    {
//        std::cout<<*aviones[i];
//    }
//    
//    Ordenamiento<Avion*> ::ordenamientoQuickSort(aviones, Ordenamiento<Avion*>::desc, 0, N-1);
//    
//    for(int i=0; i<N; i++)
//    {
//        std::cout<<*aviones[i];
//    }
    
    // Pistas en el aeropuerto
    ListaEnlazada<Pista*> * pistas = new ListaEnlazada<Pista*>;
    
    // Lista de aviones esperando alguna pista
    Cola<Avion*> * cola = new Cola<Avion*>;
    
    
    
//    Vuelo * v = new Vuelo();
//    a1->setFlight(v);
//    cola->enQue(a1);
//    Pista pista1;
//    pista1.inputPlane(cola);
//    pista1.outputPlane();
//    pista1.inputPlane(cola);
//    pista1.outputPlane();
    
    delete cola;
    return 0;
}

ListaEnlazada<Avion*>* abrir(){
    
    Avion * a;
    Vuelo *v;
    ListaEnlazada<Avion*> * lot = new ListaEnlazada<Avion*>;
    
    int N = 0;
    std::string s[7];
    std::string l, valor ,_aerol, _aerop;
    int _id, _nums, _numv, _pasa;
    
    std::ifstream leer;
    leer.open("/Users/Daniel/Documents/Tec/3º/Estructura de datos/C++/Aeropuerto/Aeropuerto/Itinerario.txt");
    if (leer.is_open()) {
        //                std::cout<<"is open"<<std::endl;
        getline(leer, l);
        N = atoi(l.c_str());
        while (getline(leer, l)) {
            int cont = 0;
            
            for(int i = 0; i <7; i++){
                for (int j = cont; j < l.length(); ++j) {
                    if(l[j] != ' '){
                        valor += l[j];
                    }
                    else{
                        cont = j +1;
                        break;
                    }
                }
                s[i] = valor;
                valor = "";
            }
            
            _id = atoi(s[0].c_str());
            _aerol = s[1];
            _nums = atoi(s[2].c_str());
            _numv = atoi(s[3].c_str());
            _pasa = atoi(s[4].c_str());
            Hora temp(s[5].c_str());
            _aerop = s[6];
            
            a = new Avion(_id, _aerol, _nums);
            v = new Vuelo(_numv, _pasa, temp, _aerop);
            a->setFlight(v);
            lot->insertBack(a);
        }
    }
    return lot;
}

