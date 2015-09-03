//
//  main.cpp
//  EjemplosSTL
//
//  Created by Daniel on 06/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include <List>
#include <vector>
#include <map>
#include <algorithm>
#include <ostream>
#include <ctime>
#include <cstdlib>

#include "Vehículo.h"

Vehiculo crear();
void imprime(std::map<std::string, Vehiculo>);
bool compara(std::pair<std::string, Vehiculo>, std::pair<std::string, Vehiculo>);

inline bool operator <(std::pair<std::string, Vehiculo> p1, std::pair<std::string, Vehiculo> p2){return p1.second < p2.second;}

int main(int argc, const char * argv[]) {
    
    
    srand((int)time(NULL));
    
    std::list<int> numeros;
    for(int i = 0; i <10; ++i){
        numeros.push_back(i);
    }
    
    /* vector de 10 elementos */
    std::vector<int> aleatorios(10);
    std::generate(aleatorios.begin(), aleatorios.end(), rand);
    
    for(auto item : numeros){
        std::cout<<item<< " ; ";
    }
    
    std::cout<<std::endl;
    
    std::copy(aleatorios.begin(), aleatorios.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout<<std::endl<<std::endl;
    std::cout<<"------------ Ejercicio 2 ----------"<<std::endl;
    std::map<std::string, Vehiculo> autos;
    
    Vehiculo v1("GM", "tracker", "negro", 2010);
    autos["119RTS"] = v1;

    int opcion;
    std::string placas;
    bool corriendo = true;
    while (corriendo) {
        std::cout<<"Que desea hacer?\n1) Imprimir\n2) Añadir vehículo\n3) Eliminar vehículo\n4) Modificar\n5) Vehículos de algún fabricante\n6)Encontrar vehiculos por color\n7) Encontrar vehículos por año\n0) Salir"<<std::endl;
        std::cin>>opcion;
        switch (opcion){
            case 1:
//                std::sort(autos.begin(), autos.end(), std::less<Vehiculo>());
                imprime(autos);
                break;
            case 2:
                std::cout<<"Placas: ";
                std::cin>>placas;
                autos[placas] = crear();
                break;
            case 3:
                std::cout<<"Placas: ";
                std::cin>>placas;
                autos.erase(placas);
                break;
            case 4:
                std::cout<<"Placas: ";
                std::cin>>placas;
                autos[placas].Modificar();
                break;
            case 5:
                std::cout<<"Fabricante: ";
                std::cin>>placas;
                for (auto item:autos){
                    if(item.second.fabricante == placas){
                        std::cout<<"Placa: "<<item.first<<std::endl;
                        std::cout<<item.second;
                    }
                }
                break;
            case 6:
                std::cout<<"Color: ";
                std::cin>>placas;
                for (auto item:autos){
                    if(item.second.color == placas){
                        std::cout<<"Placa: "<<item.first<<std::endl;
                        std::cout<<item.second;
                    }
                }
                break;
            case 7:
                std::cout<<"Año de fabricacion: ";
                std::cin>>placas;
                for (auto item:autos){
                    if(item.second.ano == atoi(placas.c_str())){
                        std::cout<<"Placa: "<<item.first<<std::endl;
                        std::cout<<item.second;
                    }
                }
                break;
            case 0:
                corriendo = false;
                break;
            default:
                std::cout<<"No existe la opcion"<<std::endl;
                break;
        }
    }
    std::cout<<std::endl;
    std::cout<<"----------- Ejercicio 1 ------------"<<std::endl;
    // Mismo ejercicio que en el segundo pracial. Ya resuelto ver 
    std::cout<<"ver exame del segundo parcial"<<std::endl;
    
    
    return 0;
}

void imprime(std::map<std::string, Vehiculo> m){
    for (auto item:m){
        std::cout<<"Vehiculo "<<item.first << ": " <<std::endl;
        std::cout<<item.second<<std::endl;
    }
}

Vehiculo crear(){
    std::string fab, mod, col;
    int ano;
    std::cout<<"Fabricante: ";
    std::cin>>fab;
    std::cout<<"Modelo: ";
    std::cin>>mod;
    std::cout<<"Color: ";
    std::cin>>col;
    std::cout<<"Año fabricacion: ";
    std::cin>>ano;
    
    Vehiculo v(fab, mod, col, ano);
    return v;
}

bool compara(std::pair<std::string, Vehiculo> a1, std::pair<std::string, Vehiculo> a2){
    return a1.second < a2.second;
}

//void ordenamientoSeleccion(std::map<std::string, Vehiculo> x){
//    int minimo = 0;
//    int temp;
//    
//    for(int i = 0; i<n-1;i++){
//        minimo = i;
//        for(int j = i+1; j<n; j++){
//            if (x[minimo] > x[j]){
//                minimo = j;
//            }
//            temp = x[minimo];
//            x[minimo] = x[i];
//            x[i] = temp;
//        }
//    }
//}
