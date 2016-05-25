//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#include "casilla.h"
#include "pieza.h"

casilla::casilla(){}

casilla::casilla(int x, int y) : _x(x), _y(y){ }

casilla::~casilla() { }

int casilla::coordX() {
    return _x;
}

int casilla::coordY() {
    return _y;
}

const bool casilla::ocupada() const{
    bool ocupada = true;
    if (!_piezaOcupante){
        ocupada = false;
    }
    return ocupada;
}

pieza& casilla::ocupante() const{
    return *_piezaOcupante;
}

void casilla::ponerPieza(pieza* pieza){
    _piezaOcupante = pieza;
}

void casilla::imprimir(ostream& salida) const {

    //salida << "|";
    //Imprime la pieza si la casilla está ocupada
    if (ocupada())
    {
        ocupante().imprimir(salida);
    }
        //Si no está ocupada imprime dos espacios en blanco
    else
    {
        salida << "  ";
    }
    //salida << "|";
}

//Sobrecarga de operador para imprimir la pieza
ostream& operator<< (ostream& salida, const casilla& casilla){
    return salida;
}