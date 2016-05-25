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

bool ocupada(){
    bool ocupada = true;
    if (!_piezaOcupante){
        ocupada = false;
    }
}

pieza& ocupante(){
    return *_piezaOcupante;
}

void ponerPieza(pieza* pieza){
    _piezaOcupante = pieza;
}

void imprimir(ostream& salida){

    salida << "|";
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
    salida << "|";
}

//Sobrecarga de operador para imprimir la pieza
friend ostream& operator<< (ostream& salida, const casilla& casilla){
    return salida;
}