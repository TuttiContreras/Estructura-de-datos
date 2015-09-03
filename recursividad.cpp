//
//  recursividad.cpp
//  
//
//  Created by Daniel on 21/08/14.
//
//

#include "recursividad.h"
using namespace std;
#include<iostream>

int MCD;

int main(int argc, const char *argv[]){
    int m,n;
    cout<<"Entre un numero"<<endl;
    cin>>m;
    cout<<"SEgundo numero"<<endl;
    cin>>n;
    cout<<"El MCD de:"<<m<<" y "<<n<<" es:"<<euclides(m, n)<<endl;
}

int euclides(int m,int n){
    int r;
    if(m>n){
        r = m%n;
    }
    else{
        r = n%m;
    }
    
    if(r==0){
        return n;
    }
    else{
        return euclides(n,r);
    }
}