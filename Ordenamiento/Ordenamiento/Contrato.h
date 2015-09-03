//
//  Contrato.h
//  Ordenamiento
//
//  Created by Daniel on 04/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Ordenamiento__Contrato__
#define __Ordenamiento__Contrato__

#include <iostream>
class Contrato{
public:
    int numero, dia, mes, ano;
    Contrato(){}
    Contrato(int _num, int _dia, int _mes, int _ano):numero(_num), dia(_dia), mes(_mes), ano(_ano){}
    
    bool operator > (Contrato &);
    bool operator < (Contrato &);
    friend std::ostream & operator <<(std::ostream &, Contrato &);

};

#endif /* defined(__Ordenamiento__Contrato__) */
