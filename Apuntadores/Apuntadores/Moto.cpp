//
//  Moto.cpp
//  Apuntadores
//
//  Created by Daniel on 22/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Moto.h"

std::ostream & operator << (std::ostream & os, Moto & moto){
    return os << "Soy una Moto"<<std::endl;
}

void Moto::Corre(){
    std::cout<<"La moto corre\n";
}