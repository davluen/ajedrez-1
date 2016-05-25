//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "alfil.h"
#include "pieza.h"
#include "casilla.h"
#include "tablero.h"

alfil::alfil() { }

alfil::alfil(bool &color) : pieza(color) {

}

alfil::~alfil() {

}

bool alfil::movLegal(casilla& destino) {

    bool esLegal = false;

    //Comprobamos que la casilla de destino no esté ocupada o que si está ocupada que sea por una pieza del otro color
    if(!destino.ocupada() || (destino.ocupante().color() != this->color())){
        //Comprobamos que el camino sea diagonal
        if(abs(this->posicion().coordX() - destino.coordX()) == abs(this->posicion().coordY() - destino.coordY())){
            //Por último comprobamos si hay vía libre
            if(tablero::getTablero().comprobarDiagonal(this->posicion(), destino)){
                esLegal = true;
            }
        }
    }

    return esLegal;

}

void alfil::imprimir(ostream& salida)
{
    salida << color() << string("A");
}