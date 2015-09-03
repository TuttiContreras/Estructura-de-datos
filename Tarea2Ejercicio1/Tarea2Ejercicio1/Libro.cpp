//
//  Libro.cpp
//  Tarea2Ejercicio1
//
//  Created by Daniel on 02/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Libro.h"

Libro::Libro(){
    
}

Libro::Libro(int i){
    std::cout<<"Titulo: ";
    std::cin>>titulo;
    std::cout<<"Autor: ";
    std::cin>>autor;
    std::cout<<"Editorial: ";
    std::cin>>editorial;
    std::cout<<"Edicion: ";
    std::cin>>edicion;
    std::cout<<"Numero de páginas: ";
    std::cin>>numPag;
    std::cout<<"Año de publicacion: ";
    std::cin>>ano;
    std::cout<<"Mes de publicacion: ";
    std::cin>>mes;
    std::cout<<"Dia de publicacion: ";
    std::cin>>dia;
}

bool Libro::operator > (Libro & libro){
    if(ano > libro.ano){
        return true;
    }
    else if(mes > libro.mes){
        return true;
    }
    else if(dia > libro.dia){
        return true;
    }
    else{
        return false;
    }
}

bool Libro::operator < (Libro & libro){
    if(ano < libro.ano){
        return true;
    }
    else if(mes < libro.mes){
        return true;
    }
    else if(dia < libro.dia){
        return true;
    }
    else{
        return false;
    }
}

std::ostream & operator <<(std::ostream & os, Libro & libro){
    if(libro.titulo != ""){
        os << "Titulo: " <<libro.titulo << "  Autor: "<<libro.autor << "  Editorial: "<<libro.editorial << "  Edición: "<<libro.edicion<< "  Fecha de publicacion: "<<libro.dia<<"/"<<libro.mes<<"/"<<libro.ano<<"  Número de páginas: "<<libro.numPag<<std::endl;
    }
    else{
        os<<"";
    }
    return os;
}
