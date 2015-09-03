//
//  Vehículo.h
//  EjemplosSTL
//
//  Created by Daniel on 06/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __EjemplosSTL__Vehi_culo__
#define __EjemplosSTL__Vehi_culo__

#include <iostream>

class Vehiculo{
public:
    std::string fabricante, modelo, color;
    int ano;
    
    Vehiculo();
    Vehiculo(std::string _fabricante, std::string _modelo, std::string _color, int _ano): fabricante(_fabricante), modelo(_modelo), color(_color), ano(_ano){};
    void Modificar();
    bool operator <(Vehiculo &);
    friend std::ostream & operator <<(std::ostream & os, Vehiculo & v);
};

#endif /* defined(__EjemplosSTL__Vehi_culo__) */
