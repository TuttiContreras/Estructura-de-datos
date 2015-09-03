//
//  Auto.cpp
//  Apuntadores
//
//  Created by Daniel on 22/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Auto.h"

std::ostream & operator << (std::ostream & os, Auto & uto){
    return os << "Soy un Auto"<<std::endl;
}
void Auto::Corre(){
    std::cout<<"El auto corre\n";
}