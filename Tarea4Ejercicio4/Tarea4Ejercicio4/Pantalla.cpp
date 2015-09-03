//
//  Pantalla.cpp
//  Tarea4Ejercicio4
//
//  Created by Daniel on 18/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Pantalla.h"


bool Pantalla::curses_ON = false;

void Pantalla::print(ListaDoblementeEnlazada<ListaDoblementeEnlazada<char> *> *texto){
    std::cout<<"------------- Editor de Texto ------------\n";
    for (int i = 0; i < texto->size(); ++i){
        std::cout<<*(texto->At(i)->getInfo());
        std::cout<<std::endl;
    }
}

void Pantalla::printMenu(){
    std::cout<<"------------- Editor de Texto ------------\n";
    std::cout<<"Menu: "<<std::endl;
    std::cout<<"Para abrir el menu de ocpiones una vez ingresado al editor presione ESC"<<std::endl;
    std::cout<<"1) Nuevo Documento\n2) Abrir Documento\n0) Salir"<<std::endl;
    
}

void Pantalla::printOpciones(){
    std::cout<<"Opciones:\n1) Salvar el documento\n2) Cerrar documento\n";
}

ListaDoblementeEnlazada<ListaDoblementeEnlazada<char> *> * Pantalla::editor(ListaDoblementeEnlazada<ListaDoblementeEnlazada<char> *> * texto){
    int row, col;
    row = 0;
    col = 0;
    bool activo = true;
    
    if(texto->size() == 1 && texto->At(0)->getInfo()->size() == 0){
        row = 0;
        col = 0;
    }
    else{
        row = texto->size() -1;
        col = texto->At(row-1)->getInfo()->size();
    }
    
    
    
    startCurses();
    
    for (int i = 0; i< texto->size(); ++i){
        for (int j = 0; j < texto->At(i)->getInfo()->size(); ++j){
            addch(texto->At(i)->getInfo()->At(j)->getInfo());
        }
        addch('\n');
    }
    
    move(row, col);
    while (activo) {
//        getyx(stdscr, row, col);
        int ch = getch();
        switch (ch) {
            case ESC:
                activo = false;
                break;
            case '\n':
                addch(ch);
                texto->insertAt(nuevaLinea(texto->At(row)->getInfo(), col), row+1);
                clear();
                return editor(texto);
                break;
            case BACKSPACE:
                if (col > 0) {
                    texto->At(row)->getInfo()->deleteAt(col-1);
                    col--;
                    move(row, col);
                    for (int i = col; i < texto->At(row)->getInfo()->size(); ++i){
                        addch(texto->At(row)->getInfo()->At(i)->getInfo());
                    }
                    addch(' ');
                    move(row, col);
                }
                else{
                    for (int j = 0; j < texto->At(row)->getInfo()->size(); ++j) {
                        texto->At(row-1)->getInfo()->insertBack(texto->At(row)->getInfo()->deleteAt(j)->getInfo());
                    }
                    texto->deleteAt(row);
                    return editor(texto);
                    
                }
                break;
            case LEFT:
                if (col >0) {
                    col--;
                    move(row, col);
                }
                break;
            case RIGHT:
                if(col < texto->At(row)->getInfo()->size()){
                    col++;
                    move(row, col);
                }
                break;
            case UP:
                if (row > 0) {
                    row--;
                    move(row, col);
                }
                break;
            case DOWN:
                if(row < texto->size()-1){
                    row++;
                    move(row, col);
                }
                break;
            default:
                addch(ch);
                texto->At(row)->getInfo()->insertAt(ch, col);
                col++;
                break;
        }
    }
    
    
    endCurses();
    
    
    return texto;
}

void Pantalla::endCurses(){
    if (curses_ON && !isendwin())
        clear();
        endwin();
}


void Pantalla::startCurses(){
    if (curses_ON) {
        refresh();
    }
    else {
        initscr();
        cbreak();
        noecho();
        intrflush(stdscr, false);
        keypad(stdscr, true);
        atexit(endCurses);
        curses_ON = true;
    }
}

ListaDoblementeEnlazada<char> * Pantalla::nuevaLinea(ListaDoblementeEnlazada<char> * vieja, int c){
    ListaDoblementeEnlazada<char> * nueva = new ListaDoblementeEnlazada<char>;
    if(c != vieja->size()){
        for (int i = c-1; i < vieja->size(); ++i) {
            nueva->insertBack(vieja->deleteAt(c)->getInfo());
        }
    }
    
    
    return nueva;
}