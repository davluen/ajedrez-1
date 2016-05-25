//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "torre.h"
#include "casilla.h"
#include "tablero.h"

torre::torre() { }

torre::torre(bool &color) : pieza(color) {

}

torre::~torre() {

}

const bool torre::movLegal(casilla &destino) const {

    bool esLegal=false;

    //Miramos si está ocupada o si está ocupada por una pieza de otro color
    if(!destino.ocupada()||(destino.ocupante().color()!=this->color())){

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
    //TODO: falta comprobar el ENROQUE

    return esLegal;
}

const void torre::imprimir(ostream& salida) const{
    salida << color() << string("T");
}