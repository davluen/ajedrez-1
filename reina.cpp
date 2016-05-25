//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "reina.h"
#include "pieza.h"
#include "casilla.h"
#include "tablero.h"

reina::reina() { }

reina::reina(bool &color) : pieza(color) {

}

reina::~reina() {

}

bool reina::movLegal(casilla &destino) {

    bool esLegal=false;

    if(!destino.ocupada()||(destino.ocupada().color()!=this->color())){
        //Movimiento vertical
        if(destino.coordX()==this->posicion().coordX()){
            if(tablero::getTablero().comprobarHorizontal(this->posicion,destino)){
                esLegal=true;
            }
        }

        //Movimiento horizontal
        if(destino.coordY()==this->posicion().coordY()){
            if(tablero::getTablero().comprobarVertical(this->posicion(),destino)){
                esLegal=true;
            }
        }

        //Movimiento diagonal
        if(abs(this->posicion().coordX() - destino.coordX())==abs(this->posicion().coordY() - destino.coordY())){
            if(tablero::getTablero().comprobarDiagonal(this->posicion(),destino)){
                esLegal=true;
            }
        }
    }

    return esLegal;

}

void reina::imprimir(ostream& salida)
{
    salida << color() << string("A");
}