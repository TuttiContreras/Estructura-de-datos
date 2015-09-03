//
//  TiendaAbarrotes.h
//  
//
//  Created by Daniel on 14/08/14.
//
//

#ifndef ____TiendaAbarrotes__
#define ____TiendaAbarrotes__

#include <iostream>

class Producto{
public:
    string nombre;
    int precio;
};

class Tienda{
private:
    Producto inventario[10];
    
public:
    void comprar(item i) = 0;
    void vender(item i)= 0;
};


#endif /* defined(____TiendaAbarrotes__) */
