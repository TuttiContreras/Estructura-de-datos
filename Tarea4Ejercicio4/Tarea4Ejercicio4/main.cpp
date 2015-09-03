//
//  main.cpp
//  Tarea4Ejercicio4
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include "Pantalla.h"
#include <fstream>
#include <curses.h>

ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> * abrir();
ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> * nuevo();
void guardar(ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>* > *);



int main(int argc, const char * argv[]) {
    
    int opcion;
    bool abierto = true;
    ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> * text = new ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*>;
    
//    Pantalla::printMenu();
//    std::cin>> opcion;
//    if (opcion == 2){
//        text = abrir();
//    }
//    else if (opcion == 1){
//        guardar(text);
//        
//    }
    
    while (abierto) {
        Pantalla::printMenu();
        std::cin>> opcion;
        switch (opcion) {
            case 2:
                text = abrir();
                break;
            case 1:
                text = nuevo();
                break;
            case 0:
                abierto = false;
                break;
            default:
                std::cout<<"Opcion no valida"<<std::endl;
                break;
        }
    }
    
    // Liberar memoria
    for(int i = 0; i < text->size(); ++i){
        delete text->At(i)->getInfo();
    }
    delete text;
    
    return 0;
}

// Funcion para guardar el archivo
void guardar(ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>* > * text){
    std::string dir;
    std::cout<<"Direccion en la que lo quiere guardar?"<<std::endl;
//    std::cin>>dir;
    dir = "/users/daniel/desktop/l.txt";
    std::ofstream l(dir);
    for(int i = 0; i< text->size(); ++i){
        l << *text->At(i)->getInfo();
        l<< "\n";
    }
}

// Funcion para la apertura de un archivo .txt, que se guarda en una doble lista doblemente enlazada
ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> * abrir(){
    ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> * texto = new ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*>;
    
    ListaDoblementeEnlazada<char> * linea = new ListaDoblementeEnlazada<char>;
    
    std::string direccion;
    char l;
    std::ifstream leer;
    std::cout<< "Dirección del archivo .txt" <<std::endl;
//    std::cin>>direccion;
    direccion = "/users/daniel/desktop/dir.txt";
    leer.open(direccion);
    
    if (leer.is_open()) {
//        std::cout<<"is open"<<std::endl;
        while (leer.get(l)) {
            if(l != '\n'){
//                std::cout<<l<<std::endl;
                linea->insertBack(l);
            }
            else{
//                std::cout<<"se agrega"<<std::endl;
                ListaDoblementeEnlazada<char> * nueva = new ListaDoblementeEnlazada<char>;
                for (int i = 0; i < linea->size(); ++i) {
                    nueva->insertBack(linea->At(i)->getInfo());
                }
                texto->insertBack(nueva);
                linea->clear();
            }
        }
        
        ListaDoblementeEnlazada<char> * nueva = new ListaDoblementeEnlazada<char>;
        for (int i = 0; i < linea->size(); ++i) {
            nueva->insertBack(linea->At(i)->getInfo());
        }
        texto->insertBack(nueva);
        linea->clear();
        
        bool editando = true;
        while (editando) {
            Pantalla::editor(texto);
            Pantalla::printOpciones();
            int opcion;
            std::cin>>opcion;
            switch (opcion) {
                case 1:
                    guardar(texto);
                    break;
                case 2:
                    editando = false;
                    break;
                default:
                    break;
            }
        }
        
        
    }
    else{
        std::cout<<"No se abrio"<<std::endl;
    }
//    std::cout<<"size: "<<texto->size()<<std::endl;
    leer.close();
    return texto;
}

ListaDoblementeEnlazada<ListaDoblementeEnlazada<char>*> * nuevo(){
    ListaDoblementeEnlazada<ListaDoblementeEnlazada<char> *> * text = new ListaDoblementeEnlazada<ListaDoblementeEnlazada<char> *>;
    ListaDoblementeEnlazada<char> * linea = new ListaDoblementeEnlazada<char>;
    text->insertBack(linea);
    bool editando = true;
    while (editando) {
        Pantalla::editor(text);
        Pantalla::printOpciones();
        int opcion;
        std::cin>>opcion;
        switch (opcion) {
            case 1:
                guardar(text);
                break;
            case 2:
                editando = false;
                break;
            default:
                break;
        }
    }
    
    return text;
}



