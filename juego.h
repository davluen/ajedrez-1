//
// Created by Daniel Sánchez Vicente on 24/5/16.
//

#ifndef AJEDREZ_JUEGO_H
#define AJEDREZ_JUEGO_H

#include <set>

using namespace std;

class jugador;
class casilla;
class tablero;
class pieza;
class peon;
class caballo;
class alfil;
class reina
class rey;

class juego {
public:

    jugador& siguienteJugador();

    void inicializar();

    jugador& adversario(jugador& jugador);

private:

    juego();

    ~juego();

    static tablero _tablero;
    static set<pieza*>* _piezasB;
    static set<pieza*>* _piezasN;
    static jugador* _jugador1;
    static jugadot* _jugador2;

};


#endif //AJEDREZ_JUEGO_H
