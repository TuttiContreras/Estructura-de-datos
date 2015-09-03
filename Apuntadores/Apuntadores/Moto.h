//
//  Moto.h
//  Apuntadores
//
//  Created by Daniel on 22/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Apuntadores__Moto__
#define __Apuntadores__Moto__

#include <iostream>
#include "Auto.h"

class Moto : public Auto{
public:
    Moto() {}
    virtual void Corre();
    friend std::ostream & operator << (std::ostream &, Moto &);
};


#endif /* defined(__Apuntadores__Moto__) */
