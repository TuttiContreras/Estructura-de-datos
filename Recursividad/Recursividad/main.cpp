//
//  main.cpp
//  Recursividad
//
//  Created by Daniel on 21/08/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
using namespace std;
#include<iostream>

int MCD;

int euclides(int m, int n);

int main(int argc, const char *argv[]){
    int m,n;
    cout<<"Entre un numero"<<endl;
    cin>>m;
    cout<<"SEgundo numero"<<endl;
    cin>>n;
    cout<<"El MCD de:"<<m<<" y "<<n<<" es:"<<euclides(m, n)<<endl;
    return 0;
}

int euclides(int m,int n){
    int r;
    if(n>m){
        r = m;
        m = n;
        n = r;
    }
    r = m%n;
    
    if(r==0){
        return n;
    }
    else{
        return euclides(n,r);
    }
}