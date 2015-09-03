//
//  Server.cpp
//  Tarea4Ejercicio3
//
//  Created by Daniel on 16/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Server.h"


Server::Server(){
    envio = false;
    std::cout<<"Address: ";
    std::cin>>address;
    mensajes = new ListaEnlazada<Mensaje*>;
    m = nullptr;
}

Server::Server(int t){
    address = t;
    envio = false;
    mensajes = new ListaEnlazada<Mensaje*>;
    m = nullptr;
}

Server::~Server(){
    delete mensajes;
}

void Server::recibir(Mensaje* m){
    std::cout<<"Recibido"<<std::endl;
    mensajes->insertBack(m);
}

void Server::enviar(){
    envio = true;
    int destino;
    std::string mnsj;
    std::cout<<"Dirección de computadora destino: ";
    std::cin>>destino;
    std::cout<<"Mensaje: ";
    std::cin>>mnsj;
    m = new Mensaje(address, destino, mnsj);
    std::cout<<"Mensaje enviado"<<std::endl;
}

std::ostream & operator <<(std::ostream & os, Server & s){
    os << "Direccion de la cmputadora: " << s.address << std::endl;
    os << "Mensajes: ";
//    Nodo<Mensaje*> * aux = s.mensajes->start();
//    while (aux){
//        os << (*aux) << std::endl;
//        aux = aux->getSiguiente();
//    }
    for (int i = 0; i < s.mensajes->size(); ++i){
        os << *s.mensajes->At(i)->getInfo();
    }
    
    return os;
}
