//
//  main.cpp
//  Tarea2Ejercicio1
//
//  Created by Daniel on 02/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Biblioteca.h"


int main(int argc, const char * argv[]){
    
    bool estado = true;
    Biblioteca b;
    
    while (estado) {
        std::cout<<"Escoja una de las opciones siguientes"<<std::endl;
        std::cout<<"1) Ver biblioteca"<<std::endl<<"2) Añadir Libro"<<std::endl<<"3) Eliminar libro"<<std::endl<<"4) Mostrar libros anteriores a una fecha"<<std::endl<<"5) Mostrar libros posteriores a una fecha: "<<std::endl<<"6) Mostrar libros escritos en un intervalo de tiempo:"<<std::endl<<"7) Mostrar libros de un autor"<<std::endl<<"8) Mostrar libros de una editorial"<<std::endl<<"0) Salir"<<std::endl;
        int opcion;
        std::cin>>opcion;
        switch (opcion) {
            case 1:
                b.imprimir();
                break;
            case 2:
                b.agregar();
                b.imprimir();
                break;
            case 3:
                b.quitar();
                b.imprimir();
                break;
            case 4:
                b.buscarFecha(Biblioteca::men);
                break;
            case 5:
                b.buscarFecha(Biblioteca::may);
                break;
            case 6:
                b.buscarIntervaloFechas(Biblioteca::men, Biblioteca::may);
                break;
            case 7:
                b.busquedaAutor();
                break;
            case 8:
                b.busquedaEditorial();
                break;
            case 0:
                estado = false;
                break;
            default:
                estado = false;
                break;
        }
    }
    
    return 0;
}