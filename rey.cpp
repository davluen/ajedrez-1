//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "rey.h"
#include "pieza.h"
#include "casilla.h"
#include "tablero.h"

rey::rey() { }

rey::rey(bool &color) : pieza(color) {

}

rey::~rey() {

}

bool rey::movLegal(casilla& destino) {

    bool esLegal = false;

    //Comprobamos que la casilla de destino no esté ocupada o que si está ocupada que sea por una pieza del otro color
    if(!destino.ocupada() || (destino.ocupante().color() != this->color())){
        //Comprobamos que la casilla de destino sea adyacente a la actual
        if(abs(this->posicion().coordX() - destino.coordX()) <= 1 && abs(this->posicion().coordY() - destino.coordY()) <= 1){
            esLegal = true;

        }
    }

    return esLegal;

}

void rey::imprimir(ostream& salida)
{
    salida << color() << string("R");
}//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "rey.h"
