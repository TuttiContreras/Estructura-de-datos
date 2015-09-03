/* 
 * File:   main.cpp
 * Author: Daniel
 *
 * Created on 21 de agosto de 2014, 07:41 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

int sumarVectores(int* arreglo, int pos);
int main(int argc, char** argv) {
    int arr[3] = {3,6,9};
    
    cout<<sumarVectores(arr, 2);

    return 0;
}

int sumarVectores(int *arreglo, int pos){
    if(pos == 0){
        return arreglo[0];
    }
    else{
        if(pos == 0){
            return arreglo[0];
        }
        else{
            return (arreglo[pos]+sumarVectores(arreglo, pos-1));
        }
    }
}