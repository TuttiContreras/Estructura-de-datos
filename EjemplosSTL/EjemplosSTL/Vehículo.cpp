//
//  Vehículo.cpp
//  EjemplosSTL
//
//  Created by Daniel on 06/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Vehículo.h"

Vehiculo::Vehiculo(){
    fabricante = "vacio";
    modelo = " ";
    color = " ";
    ano = 0;
}

void Vehiculo::Modificar(){
    std::cout<<"Fabricante: ";
    std::cin>>fabricante;
    std::cout<<"Modelo: ";
    std::cin>>modelo;
    std::cout<<"Color: ";
    std::cin>>color;
    std::cout<<"ano: ";
    std::cin>>ano;
}

std::ostream & operator <<(std::ostream & os, Vehiculo & v){
    
    os << "Modelo: "<<v.modelo << "\nFabricante: " << v.fabricante << "\nColor: " << v.color << "\nAño de fabricacion: "<<v.ano << std::endl;
    
    return os;
}

bool Vehiculo::operator<(Vehiculo & v){
    return this->ano < v.ano;
}