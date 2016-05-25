//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#ifndef AJEDREZ_CASILLA_H
#define AJEDREZ_CASILLA_H

#include <iostream>
using namespace std;

class jugador;
class rey;
class tablero;
class casilla;
class pieza;


class casilla {

public:

    casilla();

    casilla(int x, int y);

    ~casilla();

    int coordX();

    int coordY();

    const bool ocupada() const;

    pieza& ocupante() const;

    void ponerPieza(pieza* pieza);

    void imprimir(ostream& salida) const;

    friend ostream& operator<< (ostream& salida, const casilla& casilla);


private:
    int _x;
    int _y;
    pieza* _piezaOcupante;

};


#endif //AJEDREZ_CASILLA_H
