/* 
 * File:   main.cpp
 * Author: Daniel
 *
 * Created on 21 de agosto de 2014, 08:00 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int sumarLinea(int* linea, int pos){
    if(pos ==0){
        return linea[0];
    }
    else{
        return (linea[pos]+ sumarLinea(linea, pos-1));
    }
}
int sumarColumna(int** matriz, int pos){
    if(pos == 0){
        return sumarLinea(matriz[0], 2);
    }
    else{
        return (sumarLinea(matriz[pos], 2) + sumarColumna(matriz, pos-1));
    }
}
int main(int argc, char** argv) {

    
    int arr[4][3] = {{1,1,1},{1,1,1},{1,1,1},{1,1,1}};
    cout<<sumarColumna(arr, 3);
    return 0;
}

