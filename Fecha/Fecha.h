/* 
 * File:   Fecha.h
 * Author: Daniel
 *
 * Created on 14 de agosto de 2014, 07:10 AM
 */

#ifndef FECHA_H
#define	FECHA_H

class Fecha {
public:
    Fecha();
    Fecha(const Fecha& orig);
    virtual ~Fecha();
    
    Fecha sumarDia(int dias) = 0;
    Fecha sumarMes(int mes) = 0;
    Fecha sumarAnos(int anos) = 0;
    Fecha restarDia(int dias) = 0;
    Fecha restarMes(int mes) = 0;
    Fecha restarAnos(int anos) = 0;
    void establecerHuso(int huso) = 0;
    
private:
    int dia;
    int mes;
    int ano;
    int huso;

};

#endif	/* FECHA_H */

