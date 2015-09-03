//
//  main.cpp
//  cursesPrueba
//
//  Created by Daniel on 19/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include <curses.h>

bool curses_ON = false;

void endCurses() {
    if (curses_ON && !isendwin())
        endwin();
}


void startCurses() {
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


int main(int argc, const char * argv[]) {
    int key, col, row;
    
    startCurses();
    key = getch();
    addch(key);
    getyx(stdscr, row, col);
    endCurses();
    std::cout<<"key:"<<key<<std::endl;
    std::cout<<"col: "<<col;
    std::cout<<std::endl<<"row: "<<row;
    
    return 0;
}
