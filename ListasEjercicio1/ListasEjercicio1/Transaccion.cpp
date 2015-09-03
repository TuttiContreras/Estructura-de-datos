//
//  Transaccion.cpp
//  ListasEjercicio1
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Transaccion.h"

Transaccion::Transaccion(){
    tipo = "vacio";
}

Transaccion::Transaccion(int i){
    int opcion;
    std::cout<<"Tipo de transaccion?\n1) Retiro\n2) Depósito\n3) Consulta\n4) Actualizacion\n5) Pagos"<<std::endl;
    std::cin>>opcion;
    switch (opcion) {
        case 1:
            tipo = "Retiro";
            tiempo = 4;
            break;
        case 2:
            tipo = "Deposito";
            tiempo = 2;
            break;
        case 3:
            tipo = "Consulta";
            tiempo = 3.5;
            break;
        case 4:
            tipo = "Actualizacion";
            tiempo = 5;
            break;
        case 5:
            tipo = "Pagos";
            tiempo = 2;
        default:
            tipo = "Undefined";
            tiempo = 0;
            break;
    }
}
