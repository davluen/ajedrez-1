//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#ifndef AJEDREZ_TABLERO_H
#define AJEDREZ_TABLERO_H

#include <vector>
#include <iostream>

class casilla;

class tablero {
public:

    casilla& casillaPorCoord(int x, int y);

    int getDimensiones();

    bool comprobarVertical(casilla& origen, casilla& destino);

    bool comprobarHorizontal(casilla& origen, casilla& destino);

    bool comprobarDiagonal(casilla& origen,casilla& destino);

    void imprimir(ostream& salida);

    tablero& getTablero();

    friend ostream& operator<< (ostream& salida, const tablero& tablero);

private:

    tablero(int dimensiones = _DIMENSIONES);

    ~tablero();

    vector<vector<casilla>> _casillas;

    tablero _mitablero;
    const int _DIMENSIONES;

};


#endif //AJEDREZ_TABLERO_H
