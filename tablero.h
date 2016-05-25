//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#ifndef AJEDREZ_TABLERO_H
#define AJEDREZ_TABLERO_H

#include <vector>
#include <iostream>

using namespace std;

class casilla;
class jugador;
class rey;
class tablero;
class pieza;

class tablero {
public:

    casilla& casillaPorCoord(int x, int y);

    int getDimensiones() const;

    bool comprobarVertical(casilla& origen, casilla& destino);

    bool comprobarHorizontal(casilla& origen, casilla& destino);

    bool comprobarDiagonal(casilla& origen,casilla& destino);

    void imprimir(ostream& salida) const;

    static tablero& getTablero();

    friend ostream& operator<< (ostream& salida, const tablero& tablero);

private:

    tablero(int dimensiones = _DIMENSIONES);

    ~tablero();

    vector< vector<casilla> > _casillas;

    static tablero _tablero;
    static const int _DIMENSIONES;

};


#endif //AJEDREZ_TABLERO_H
