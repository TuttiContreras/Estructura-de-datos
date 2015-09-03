//
//  main.cpp
//  Tarea2Ejercicio3
//
//  Created by Daniel on 03/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

int buscarOcurrencias(std::string texto, std::string buscar);

int main(int argc, const char * argv[])
{
    std::string linea;
    std::string texto;
    std::string buscar;
    int encontradas;
    int lin=0;
    
    std::ifstream leer;
    leer.open("/Users/Daniel/Documents/Tec/3º/Estructura de datos/C++/Tarea2Ejercicio2/Tarea2Ejercicio2/texto.txt");
    if(leer.is_open()){
        std::cout<<"Que frase quiere buscar?"<<std::endl;
        buscar= "";
        std::getline(std::cin, buscar);
        
        while (getline(leer, linea)) {
            lin++;
            if (buscarOcurrencias(linea, buscar) != 0){
                encontradas += buscarOcurrencias(linea, buscar);
                std::cout<<"Se encontro en la linea "<<lin<<": "<<linea<<std::endl;
            }
            texto = texto + " " + linea;
        }
    }
    else{
        std::cout<<"no se pudo abrir";
    }
    
    std::cout<<"Se encontro la frase \""<<buscar<<"\" "<<encontradas<<" veces."<<std::endl;
    
    leer.close();
    
    
    return 0;
}

int buscarOcurrencias(std::string texto, std::string buscar){
    
    std::transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    std::transform(buscar.begin(), buscar.end(), buscar.begin(), ::tolower);
    
    bool encontrado = false;
    int ocurrecias = 0;
    for(int i =0; i<(texto.length());++i){
        if(texto[i] == buscar[0]){
            for (int j = 0; j<buscar.length();j++){
                if (texto[i+j] == buscar[j]){
                    encontrado = true;
                }
                else{
                    encontrado = false;
                    break;
                }
            }
            if (encontrado){
                ocurrecias++;
            }
        }
    }
    return ocurrecias;
}