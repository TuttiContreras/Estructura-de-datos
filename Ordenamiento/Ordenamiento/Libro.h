//
//  Libro.h
//  Ordenamiento
//
//  Created by Daniel on 01/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Ordenamiento__Libro__
#define __Ordenamiento__Libro__

#include <iostream>

class Libro{
    std::string titulo;
    std::string autor;
    int paginas;
    int ano_publicacion;
public:
    Libro(){
        titulo = "sin definir";
        autor = "no hay";
        paginas = 0;
        ano_publicacion = 0;
    }
    Libro(std::string _titulo, std::string _autor, int _paginas, int _ano_publicacion):titulo(_titulo), autor(_autor), paginas(_paginas), ano_publicacion(_ano_publicacion){
    }
    friend std::ostream & operator <<(std::ostream &, Libro &);
    bool operator > (Libro &);
};

#endif /* defined(__Ordenamiento__Libro__) */
