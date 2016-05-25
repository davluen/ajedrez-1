//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#ifndef AJEDREZ_PEON_H
#define AJEDREZ_PEON_H

#include "pieza.h"

class casilla;
class tablero;
class reina;
class pieza;
class juego;
class jugador;
class rey;


class peon : public pieza {
public:
    peon();

    peon(bool& color);

    ~peon();

    const bool movLegal(casilla& destino) const;

    const void imprimir(ostream& salida) const;

    const bool moverPieza(const jugador& jugadorActual, casilla& destino);



private:
    reina* _ascension;
};


#endif //AJEDREZ_PEON_H
