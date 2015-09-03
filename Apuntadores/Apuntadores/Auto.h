//
//  Auto.h
//  Apuntadores
//
//  Created by Daniel on 22/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Apuntadores__Auto__
#define __Apuntadores__Auto__

#include <iostream>

class Auto {
public:
    Auto() {}
    virtual void Corre();
    friend std::ostream & operator << (std::ostream &, Auto &);
    
    
};

#endif /* defined(__Apuntadores__Auto__) */
