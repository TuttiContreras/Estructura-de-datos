//
//  main.cpp
//  Tarea4Ejercicio2
//
//  Created by Daniel on 15/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include "Pila.h"

std::string resolver(std::string);

std::string result;

int main(int argc, const char * argv[]) {
    
    std::string e;
    double res = 0;
    
    std::cout<<"Expresión: (separe cada elemento por un espacio)"<<std::endl;
    getline(std::cin, e);
    
    e = resolver(e);
    
//    std::cout<<e<<std::endl;
    Pila<std::string> * exp = new Pila<std::string>;
    
    for (int i = 0; i < e.length(); ++i){
        std::string temp;
        temp = e[i];
        if (temp != " "){
            while(e[i+1] != ' ' && i < e.length()-1){
                ++i;
                temp += e[i];
            }
            if(temp == "*"){
                res = ::atof(exp->pop()->getInfo().c_str()) * ::atof(exp->pop()->getInfo().c_str());
                temp = std::to_string(res);
            }
            else if (temp == "-"){
                res = (- ::atof(exp->pop()->getInfo().c_str())) + ::atof(exp->pop()->getInfo().c_str());
                temp = std::to_string(res);
            }
            else if (temp == "+"){
                res = ::atof(exp->pop()->getInfo().c_str()) + ::atof(exp->pop()->getInfo().c_str());
                temp = std::to_string(res);
            }
            else if (temp == "/"){
                res = (1/(::atof(exp->pop()->getInfo().c_str()))) * ::atof(exp->pop()->getInfo().c_str());
                temp = std::to_string(res);
            }
             exp->push(temp);
        }
    }
    
    
    std::cout<<*exp;
    
    delete exp;
    return 0;
}

std::string resolver(std::string s){
    std::string masMenos = " ";
    std::string multDiv = "";
    
    

    for (int i = 0; i < s.length(); ++i){
        std::string temp;
        temp = s[i];
        s[i] = ' ';
        if (temp != " "){
            while(s[i+1] != ' ' && i < s.length()-1){
                ++i;
                temp += s[i];
                s[i] = ' ';
            }
            temp += " ";
            if (temp == "( ") {
                s = resolver(s);
            }
            else if (temp == ") "){
                for (int v = 1; v< multDiv.length(); ++v) {
                    std::string t = std::to_string(multDiv[v]);
                    result += multDiv;
                }
                if (masMenos != " ") {
                    result += masMenos;
                }
                return s;
            }
            else if(temp == "* " || temp == "/ "){
                
                multDiv += temp;
            }
            else if (temp == "+ " || temp == "- "){
                if(masMenos == " "){
                    masMenos = temp;
                    
                }
                else{
                    result += multDiv;
                    result += masMenos;
                    masMenos = temp;
                    multDiv = "";
                }
            }
            else{
                result += temp;
            }
        }
    }
    
    result += multDiv;
    if(masMenos != " "){
        result += masMenos;
    }
    
//    for (int l = 0; l < operadores->size(); ++l){
//        
//    }
    
    
    
    return result;
}


//void calcular(){
//    std::string o = operadores->pop()
//    
//    if(o == +)
//}