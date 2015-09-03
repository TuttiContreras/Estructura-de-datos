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
    Libro n("Viaje al centro de la tierra", "Julio Verne", "Hachette", 500, 3, 12, 2, 1600);
    agregar(n);
    Libro m("Tengo hambre", "Daniel", "LaMia", 100, 5, 31, 3, 2014);
    agregar(m);
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

void Biblioteca::agregar(Libro l){
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
        ++i;
    }
    if(encontrado){
        return i-1;
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

void Biblioteca::buscarIntervaloFechas(bool menor(int, int, int, Libro), bool mayor(int, int, int, Libro)){
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
        if(mayor(d1, m1, a1, libros[i]) && menor(d2, m2, a2, libros[i])){
            std::cout<<"- "<<libros[i]<<std::endl;
        }
    }
}

void Biblioteca::busquedaAutor(){
    std::string nom;
    std::cout<<"Nombre del autor: "<<std::endl;
    std::getline(std::cin, nom);
    std::getline(std::cin, nom);
    std::cout<<"Resultados: "<<std::endl;
    for(int i = 0; i< cont; i++){
        if(libros[i].autor == nom){
            std::cout<<"- "<<libros[i];
        }
    }
}

void Biblioteca::busquedaEditorial(){
    std::string nom;
    std::cout<<"Nombre de la editorial: "<<std::endl;
    std::cin>>nom;
    std::cout<<"Resultados: "<<std::endl;
    for(int i = 0; i< cont; i++){
        if(libros[i].editorial == nom){
            std::cout<<"- "<<libros[i];
        }
    }
}

void Biblioteca::imprimir(){
    for(int i = 0; i< cont;i++){
        std::cout<<libros[i]<<std::endl;
    }
}

bool Biblioteca:: may(int d, int m, int a, Libro b){
    if (b.ano > a){
        return true;
    }
    else if(b.ano == a){
        if(b.mes > m){
            return true;
        }
        else if(b.mes == m){
            if(b.dia > d){
                return true;
            }
        }
        
    }
    return false;
}

bool Biblioteca::men(int d, int m, int a, Libro b){
    if (b.ano < a){
        return true;
    }
    else if(b.ano == a){
        if(b.mes < m){
            return true;
        }
        else if(b.mes == m){
            if(b.dia < d){
                return true;
            }
        }
        
    }
    return false;}
