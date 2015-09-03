//
//  Cliente.cpp
//  ExamenFinal_Pregunta2
//
//  Created by Daniel on 01/12/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Cliente.h"

Cliente::Cliente(){
    nombre = apellidoM = apellidoP = sexo = direccion = "Vacio";
    edad = telefono = 0;
}

Cliente::Cliente(int){
    cout<<"Nombre: ";
    cin >>nombre;
    cout<<"Apellido paterno: ";
    cin >>apellidoP;
    cout<<"Apellido Materno: ";
    cin>>apellidoM;
    cout<<"sexo: ";
    cin >>sexo;
    cout<< "Direccion";
    cin>>direccion;
    cout<< "edad :";
    cin>>edad;
    cout << "Telefono";
    cin>>telefono;
}

void Cliente::realizarLlamada(Operador * o){
    registro.push_back(Llamada(o));
}
