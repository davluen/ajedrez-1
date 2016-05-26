//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "peon.h"
#include "casilla.h"
#include "tablero.h"
#include "juego.h"
#include "reina.h"
#include "rey.h"
#include "jugador.h"

//NOTA: las blancas comienzan en las casillas bajas (0,1)
//		las negras comienzan en las casillas altas (6,7)

#define DIREC_B -1
#define DIREC_N 1
#define FIN_N 7
#define FIN_B 0

peon::peon() { }

peon::peon(bool &color) : pieza(color) {

}

peon::~peon() {
	//delete _ascension->~reina();
}

const bool peon::movLegal(casilla &destino) const {

	int direccion = DIREC_B; //Blancas por defecto para ahorrarnos un else
	bool esLegal = false;

	if (this->color() == 0) {
		direccion = DIREC_N;
	}  // Por si la pieza es negra

	if (_ascension) {
		//esLegal = _ascension->movLegal(destino);
	}

	else if (!_ascension) {
		if (!destino.ocupada()) {
			// Está libre el destino?
			if (destino.coordY() == this->posicion().coordY()) {
				//está en dirección vertical?
				if (!pieza::movida()) {
					//Ha sido movido el peon anteriormente?
					if (destino.coordX() == (this->posicion().coordX() + 2 * direccion)) {
						// Si va a mover dos casillas a la vez
						if (!(tablero::getTablero().casillaPorCoord(this->posicion().coordX() + 1 * direccion, this->posicion().coordY()).ocupada())) {
							//Este if toma el tablero y, con las coordenadas de la posicion, comprueba si la casilla delantera o trasera está libre
							esLegal = true;
						}
					}
				}
				if (destino.coordX() == (this->posicion().coordX() + 1 * direccion)) {
					esLegal = true;
				}
			}
		}

		else if ((destino.coordX() == (this->posicion().coordX() + 1 * direccion)) && ((destino.coordY() == (this->posicion().coordY() + 1)) || (destino.coordY() == (this->posicion().coordY() - 1)))) {
			//Movimiento oblicuo: si avanza 1 y se mueve a derecha o izquierda 1
			if (destino.ocupante().color() != this->color()) {
				esLegal = true;
			}
		}
	}



	return esLegal;

}

const bool peon::moverPieza(const jugador &jugadorActual, casilla &destino) {
	int final = FIN_N;
	bool col = this->color();
	if (this->color()) final = FIN_B;
	bool esLegal = pieza::moverPieza(jugadorActual, destino);
	if (esLegal) {
		if (!_ascension&&(posicion().coordX() == final)) {
			_ascension = new reina(col);
		}
		if (_ascension) {
			//Poner la reina donde el peon
			_ascension->poner(&destino);
			//Comprobar si la reina hace jaque
			if (this->movLegal(juego::adversario(jugadorActual).miRey().posicion())) cout << "Jaque" << endl;

		}
		juego::resetContadorTablas();
	}
	return esLegal;
};



const void peon::imprimir(ostream& salida) const {
	salida << color() << string("P");
}
