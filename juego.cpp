//
// Created by Daniel Sánchez Vicente on 24/5/16.
//

#include "juego.h"
#include "casilla.h"
#include "tablero.h"
#include "jugador.h"
#include "pieza.h"
#include "peon.h"
#include "caballo.h"
#include "alfil.h"
#include "reina.h"
#include "rey.h"
#include "peon.h"

jugador* _siguienteJugador;

juego::juego() { }

juego::~juego(){}

jugador& juego::siguienteJugador() {
    return *_siguienteJugador;
}

void juego::inicializar() {

    bool negro = 0;
    bool blanco = 1;

    //Sets de piezas blancas y negras
    _piezasN = new set<pieza*>();
    _piezasB = new set<pieza*>();
    rey* reyB = new rey(blanco);
    rey* reyN = new rey(negro);
    _siguienteJugador = NULL;

    //Colocamos las piezas negras
    tablero::getTablero().casillaPorCoord(0, 0).ponerPieza((new torre(negro)));
    tablero::getTablero().casillaPorCoord(0, 0).ocupante().poner(&tablero::getTablero().casillaPorCoord(0, 0));
    
    tablero::getTablero().casillaPorCoord(0, 1).ponerPieza((new caballo(negro)));
    tablero::getTablero().casillaPorCoord(0, 1).ocupante().poner(&tablero::getTablero().casillaPorCoord(0, 1));
    
    tablero::getTablero().casillaPorCoord(0, 2).ponerPieza((new alfil(negro)));
    tablero::getTablero().casillaPorCoord(0, 2).ocupante().poner(&tablero::getTablero().casillaPorCoord(0, 2));
    
    tablero::getTablero().casillaPorCoord(0, 3).ponerPieza((new reina(negro)));
    tablero::getTablero().casillaPorCoord(0, 3).ocupante().poner(&tablero::getTablero().casillaPorCoord(0, 3));
    
    tablero::getTablero().casillaPorCoord(0, 4).ponerPieza(reyN);
    tablero::getTablero().casillaPorCoord(0, 4).ocupante().poner(&tablero::getTablero().casillaPorCoord(0, 4));
    
    tablero::getTablero().casillaPorCoord(0, 5).ponerPieza((new alfil(negro)));
    tablero::getTablero().casillaPorCoord(0, 5).ocupante().poner(&tablero::getTablero().casillaPorCoord(0, 5));
    
    tablero::getTablero().casillaPorCoord(0, 6).ponerPieza((new caballo(negro)));
    tablero::getTablero().casillaPorCoord(0, 6).ocupante().poner(&tablero::getTablero().casillaPorCoord(0, 6));
    
    tablero::getTablero().casillaPorCoord(0, 7).ponerPieza((new torre(negro)));
    tablero::getTablero().casillaPorCoord(0, 7).ocupante().poner(&tablero::getTablero().casillaPorCoord(0, 7));

    //Peones con un bucle
    for (int i = 0; i < 8; i++) {
        tablero::getTablero().casillaPorCoord(1, i).ponerPieza((new peon(negro)));
        tablero::getTablero().casillaPorCoord(1, i).ocupante().poner(&tablero::getTablero().casillaPorCoord(1, i));

    }

    //Introducimos las piezas negras en el set de piezas negras
    //Filas 0 y 1 (índice 0)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {

            _piezasN->insert(&(tablero::getTablero().casillaPorCoord(i, j).ocupante()));
        }
    }

    //Colocamos las piezas blancas
    tablero::getTablero().casillaPorCoord(7, 0).ponerPieza((new torre(blanco)));
    tablero::getTablero().casillaPorCoord(7, 0).ocupante().poner(&tablero::getTablero().casillaPorCoord(7, 0));

    tablero::getTablero().casillaPorCoord(7, 1).ponerPieza((new caballo(blanco)));
    tablero::getTablero().casillaPorCoord(7, 1).ocupante().poner(&tablero::getTablero().casillaPorCoord(7, 1));

    tablero::getTablero().casillaPorCoord(7, 2).ponerPieza((new alfil(blanco)));
    tablero::getTablero().casillaPorCoord(7, 2).ocupante().poner(&tablero::getTablero().casillaPorCoord(7, 2));

    tablero::getTablero().casillaPorCoord(7, 3).ponerPieza((new reina(blanco)));
    tablero::getTablero().casillaPorCoord(7, 3).ocupante().poner(&tablero::getTablero().casillaPorCoord(7, 3));

    tablero::getTablero().casillaPorCoord(7, 4).ponerPieza(reyB);
    tablero::getTablero().casillaPorCoord(7, 4).ocupante().poner(&tablero::getTablero().casillaPorCoord(7, 4));

    tablero::getTablero().casillaPorCoord(7, 5).ponerPieza((new alfil(blanco)));
    tablero::getTablero().casillaPorCoord(7, 5).ocupante().poner(&tablero::getTablero().casillaPorCoord(7, 5));

    tablero::getTablero().casillaPorCoord(7, 6).ponerPieza((new caballo(blanco)));
    tablero::getTablero().casillaPorCoord(7, 6).ocupante().poner(&tablero::getTablero().casillaPorCoord(7, 6));

    tablero::getTablero().casillaPorCoord(7, 7).ponerPieza((new torre(blanco)));
    tablero::getTablero().casillaPorCoord(7, 7).ocupante().poner(&tablero::getTablero().casillaPorCoord(7, 7));

    //Peones con un bucle
    for (int i = 0; i < 8; i++) {
        tablero::getTablero().casillaPorCoord(6, i).ponerPieza((new peon(blanco)));
        tablero::getTablero().casillaPorCoord(6, i).ocupante().poner(&tablero::getTablero().casillaPorCoord(6, i));

    }

    //Introducimos las piezas blancas en el set de piezas blancas
    //Filas 6 y 7 (índice 0)
    for (int i = 6; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            _piezasB->insert(&(tablero::getTablero().casillaPorCoord(i, j).ocupante()));
        }
    }

    // Create players
    _jugador1 = new jugador(string("Jugador 1"), reyB, _piezasB);
    _jugador2 = new jugador(string("Jugador 2"), reyN, _piezasN);

    _siguienteJugador = _jugador1;

    //Impresión inicial del tablero
    tablero::getTablero().imprimir(cout);

    //Bucle de juego
    while (true)
    {
        //Pedir movimiento al jugador
        siguienteJugador().movimiento();

        //Buscamos el siguiente jugador
        _siguienteJugador = &adversario(siguienteJugador());

        //Volvemos a imprimir el tablero
        tablero::getTablero().imprimir(cout);
    }
}

jugador& juego::adversario(jugador &jugador) {

    jugador* adversario;

    //Consultamos el color del rey
    if (jugador.miRey().color() == 0){
        adversario =  _jugador1;
    }

    else {
        adversario = _jugador2;
    }

    return *adversario;

}

//inicializamos variables
set<pieza*>* juego::_piezasB;
set<pieza*>* juego::_piezasN;
jugador* juego::_jugador1;
jugador* juego::_jugador2;
