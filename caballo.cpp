//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "caballo.h"
#include "casilla.h"
#include "tablero.h"

caballo::caballo() { }

caballo::caballo(bool &color) : pieza(color) {

}

caballo::~caballo() {

}

const bool caballo::movLegal(casilla& destino) const {

    bool esLegal = false;

    //Comprobamos que la casilla de destino no esté ocupada o que si está ocupada que sea por una pieza del otro color
    if(!destino.ocupada() || (destino.ocupante().color() != this->color())){

        //Comprobamos que el movimiento se haga en L: una casilla en una dirección y dos en la otra
        //No es necesario comprobar si el camino está libre, el caballo puede saltar.

        if(abs(this->posicion().coordX() - destino.coordX()) == 1){

            if(abs(this->posicion().coordY() - destino.coordY()) == 2){

                esLegal = true;

            }

        }

        if(abs(this->posicion().coordY() - destino.coordY()) == 1){

            if(abs(this->posicion().coordX() - destino.coordX()) == 2){

                esLegal = true;

            }

        }
    }

    return esLegal;

}

const void caballo::imprimir(ostream& salida) const {
    salida << color() << string("C");
}