//
//  CallCenter.cpp
//  ExamenFinal_Pregunta2
//
//  Created by Daniel on 01/12/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "CallCenter.h"

CallCenter::CallCenter(){
    srand((int) time(NULL));
    numOperadores = rand() % 10;
    operadores = new Operador*[numOperadores];
    total = 0;
    espera = new queue<Cliente*>;
}

CallCenter::CallCenter(int n){
    numOperadores = n;
    operadores = new Operador*[numOperadores];
    total = 0;
    espera = new queue<Cliente*>;
}

CallCenter::~CallCenter(){
    delete operadores;
    delete espera;
}


bool CallCenter::agregarOperador(Operador * o){
    if(total < numOperadores){
        operadores[total] = o;
        ++total;
        return true;
    }
    else{
        return false;
    }
}

bool CallCenter::atenderLlamada(Cliente * c){
    for(int i = 0; i < numOperadores; ++i){
        if(operadores[i]->disponible){
            operadores[i]->disponible = false;
            c->realizarLlamada(operadores[i]);
            return true;
        }
    }
    espera->push(c);
    return false;
}

bool CallCenter::terminarLlamada(Operador * o){
    
    Busqueda<Operador*> b;
    if(b.busquedaBinaria(operadores, o, 0, numOperadores) != -1){
        if(o->disponible){
            cout<<"Este operador no esta atediendo llamada"<<endl;
        }
        else{
            o->disponible = true;
            if(espera->size() != 0){
                atenderLlamada(espera->back());
                espera->pop();
            }
        }
    }
    else{
        cout<<"Este operador no está activo"<<endl;
    }
    
    return false;
}

Cliente* CallCenter::preguntar(){
    Cliente* c;
    int opcion;
    cout << "Buenos Dias"<<endl;
    cout << "Es su primera vez llamando? 1) si 2) no"<<endl;
    cin>>opcion;
    if(opcion == 1){
        c = new Cliente(3);
        int num = rand() % 2000;
        clientes[num] = c;
        return c;
    }
    else if (opcion == 2){
        cout << "cual es su numero de cuenta?";
        cin >> opcion;
        for(auto item:clientes){
            if(item.first == opcion){
                return item.second;
            }
        }
        cout << "cual es su telefono"<<endl;
        cin >> opcion;
        for (auto item:clientes){
            if(item.second->telefono == opcion){
                return item.second;
            }
        }
    }
    return c;
}

void CallCenter::reporte(){
    Ordenamiento<Operador*>::ordenamientoMergeSort(operadores, Ordenamiento<Operador*>::desc, 0, numOperadores-1, numOperadores);
    
    for(int i = 0; i < numOperadores; ++i){
        cout << *(operadores[i]);
    }
}