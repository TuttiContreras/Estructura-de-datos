//
//  main.cpp
//  Tarea5Ejercicio4
//
//  Created by Daniel on 13/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ArbolGenealogico.h"

int main(int argc, const char * argv[]) {
    
    std::cout<<"Arbol Genelógico"<<std::endl;
    ArbolGenealogico* a = new ArbolGenealogico();
    Persona hijo("Paco", "Vazquez", "Lopez", "M", 21);
    a->agregarHijo(a->getPatriarca(), hijo);
    std::cout<<*a<<std::endl;
    
    bool estado = true;
    int opcion;
    while(estado){
        std::cout<<"Menu:\n1) Agregar Familiar\n2) Ver descendientes de una persona\n3) Ver Hermanos y Primos\n4) Ver los Ancestros de una persona\n5) Marcar como fallecido\n6) Ver familiares fallecidos antes de nua fecha\n7) Ver familiares que están vivos\n0) Salir";
        std::cin>>opcion;
        
        switch (opcion) {
            case 0:
                estado = false;
                break;
            case 1:
                a->agregarHijo();
                break;
            case 2:
                a->decendientesDe();
                break;
            case 3:
                a->getHermanoPrimos();
                break;
            case 4:
                a->getAncestros();
                break;
            case 5:
                a->matar();
                break;
            case 6:
                a->fallecidos();
                break;
            case 7:
                a->vivos();
                break;
            default:
                break;
        }
    }
    
    
    
    delete a;
    return 0;
}
