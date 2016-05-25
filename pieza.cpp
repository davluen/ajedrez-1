//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#include "pieza.h"
#include "casilla.h"
#include "jugador.h"
#include "tablero.h"
#include "rey.h"
#include "juego.h"

    pieza::pieza(){

    }

    pieza::pieza(bool& color) : _color(color), _primerMovimiento(false){

    }

    pieza::~pieza(){

    }

    string& pieza::color(){
        return color;
    }

    casilla& pieza::posicion(){
        return *_posicion;
    }

    //Comprueba que la pieza no haya sido capturada
    //Al capturar una pieza se establece su posicion como NULL, si está capturada la función devuelve falso.
    bool pieza::enJuego(){

        return _posicion;
    }

    bool pieza::moverPieza(jugador& jugadorActual, casilla& destino){

        bool esLegal = movLegal(destino);
        set<pieza*>::iterator miIterator;
        casilla* casillaOrigen;
        pieza* ocupanteDestino;

        //Ya se ha comprobado que la casilla de origen contiene una pieza del jugador actual
        if(esLegal){
            casillaOrigen = &(pieza::posicion());
            ocupanteDestino = &destino.ocupante();

            //Hacemos un "movimiento virtual"
            //Primero movemos la pieza a la casilla
            poner(&destino);
            destino.ponerPieza(this);
            casillaOrigen->ponerPieza(NULL);

            //Ahora comprobamos que el rey del jugador que hace el movimiento no quede en jaque
            //Recorremos el set de las piezas del jugador contrario comprobando que ninguna pueda comer al rey
            miIterator = juego::adversario(jugadorActual).misPiezas().begin();
            while (esLegal && miIterator != juego::adversario(jugadorActual).misPiezas().end()) {

                //Las condiciones para detectar que una pieza hace jaque al rey son:
                //La pieza está en el tablero, no capturada
                //La pieza no va a ser capturada en este movimiento
                //La pieza puede moverse a la casilla que ocupa el rey

                if ((*miIterator)->enJuego() && &(*miIterator)->posicion() != &destino && (*miIterator)->movLegal(jugadorActual.miRey().posicion())) {
                    esLegal = false;

                }
                miIterator++;
            }

            //Deshacemos el movimiento
            poner(casillaOrigen);
            destino.ponerPieza(ocupanteDestino);
            casillaOrigen->ponerPieza(this);

            if (esLegal) {
                // Si hay una pieza en el destino la capturamos
                if (destino.ocupada()) {
                    jugadorActual.capturar(destino.ocupante());
                }

                // Movemos la pieza
                this->poner(&destino);
                destino.ponerPieza(this);
                casillaOrigen->ponerPieza(NULL);

                //Actualizamos la variable primer movimiento
                _primerMovimiento = true;

                //Comprobamos si hay jaque al otro jugador después del movimiento
                if (this->movLegal(juego::adversario(jugadorActual).miRey().posicion())) {
                    cout << "Jaque" << endl;
                }
            }
        }
        return esLegal;

    }

    bool pieza::poner(casilla* destino){
        _posicion = destino;
    }

    bool pieza::movida(){
            return _primerMovimiento;
    }
