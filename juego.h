//
// Created by Daniel Sánchez Vicente on 24/5/16.
//

#ifndef AJEDREZ_JUEGO_H
#define AJEDREZ_JUEGO_H

#include <set>
#include "tablero.h"


using namespace std;

class jugador;
class casilla;
class tablero;
class pieza;
class peon;
class caballo;
class alfil;
class reina;
class rey;

class juego {
public:

    static jugador& siguienteJugador();

    static void inicializar();

    static jugador& adversario(const jugador& jugador);

    static void resetContadorTablas();


private:

    juego();

    ~juego();

    static tablero _tablero;
    static set<pieza*>* _piezasB;
    static set<pieza*>* _piezasN;
    static jugador* _jugador1;
    static jugador* _jugador2;

    static unsigned int _numJugadas;
    static unsigned int _contadorTablas;

};


#endif //AJEDREZ_JUEGO_H
