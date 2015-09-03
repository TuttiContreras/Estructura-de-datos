//
//  Biblioteca.cpp
//  Tarea2Ejercicio1
//
//  Created by Daniel on 04/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Biblioteca.h"

Biblioteca::Biblioteca(){
    libros = new Libro[num];
    cont = 0;
}


void Biblioteca::agregar(){
    Libro l(7);
    if(cont< num){
        libros[cont] = l;
        cont++;
    }
    else{
        std::cout<<"No hay suficiente espacio"<<std::endl;
    }
}

void Biblioteca::quitar(){
    std::string t;
    std::cout<<"Ingrese el titulo del libro:"<<std::endl;
    std::cin>>t;
    int indice = buscarAutor(t);
    if(indice != -1){
        Libro temp;
        libros[indice] = temp;
        for(int i = indice+1; i< cont; i++)
        {
            temp = libros[i-1];
            libros[i-1] = libros[i];
            libros[i] = temp;
        }
        cont--;
    }
    else{
        std::cout<<"No se encontro el libro a eliminar."<<std::endl;
    }
}

int Biblioteca::buscarAutor(std::string buscar){
    int i = 0;
    bool encontrado = false;
    while((i < cont) && (!encontrado)){
        if (libros[i].titulo == buscar){
            encontrado = true;
        }
        else if(encontrado){
            return (i-1);
        }
        ++i;
    }
    return -1;
}

void Biblioteca::buscarFecha(bool compara(int, int, int, Libro)){
    int a,m,d;
    std::cout<<"Ano: ";
    std::cin>>a;
    std::cout<<"Mes: ";
    std::cin>>m;
    std::cout<<"Dia: ";
    std::cin>>d;
    
    std::cout<<"Resultados: "<<std::endl;
    for (int i = 0; i<cont; i++) {
        if(compara(d,m,a,libros[i])){
            std::cout<<"- "<<libros[i]<<std::endl;;
        }
    }
    
}

void Biblioteca::buscarIntervaloFechas(bool compara(int, int, int, Libro)){
    int a1, a2, m1, m2, d1, d2;
    std::cout<<"Después de la fecha: "<<std::endl;
    std::cout<<"Dia: ";
    std::cin>>d1;
    std::cout<<"Mes: ";
    std::cin>>m1;
    std::cout<<"Año: ";
    std::cin>>a1;
    std::cout<<"Antes de la fecha: "<<std::endl;
    std::cout<<"Dia: ";
    std::cin>>d2;
    std::cout<<"Mes: ";
    std::cin>>m2;
    std::cout<<"Año: ";
    std::cin>>a2;
    
    std::cout<<"Resultados: "<<std::endl;
    for(int i = 0; i< cont; i++){
        if(compara(d1, m1, a1, libros[i]) && compara(d2, m2, a2, libros[i])){
            std::cout<<"- "<<libros[i]<<std::endl;
        }
    }
}

void Biblioteca::imprimir(){
    for(int i = 0; i< cont;i++){
        std::cout<<libros[i]<<std::endl;
    }
    
}