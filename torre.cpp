//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "torre.h"
#include "pieza.h"
#include "casilla.h"
#include "tablero.h"

torre::torre() { }

torre::torre(bool &color) : pieza(color) {

}

torre::~torre() {

}

bool torre::movLegal(casilla &destino) {

    bool esLegal=false;

    //Miramos si está ocupada o si está ocupada por una pieza de otro color
    if(!destino.ocupada()||(destino.ocupada().color()!=this->color())){
        if(this->posicion().coordX()==destino.coordX()){
            if(tablero::getTablero().comprobarHorizontal(this->posicion(),destino)){
                esLegal=true;
            }
        }
        else if(this->posicion().coordY()==destino.coordY()){
            if(tablero::getTablero().comprobarVertical(this->posicion(),destino)){
                esLegal=true;
            }
        }
    }
    //falta comprobar el ENROQUE

    return esLegal;
}

void torre::imprimir(ostream& salida)
{
    salida << color() << string("T");
}