//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#ifndef AJEDREZ_TORRE_H
#define AJEDREZ_TORRE_H

#include "pieza.h"

class casilla;
class tablero;


class torre : public pieza {
public:
    torre();

    torre(bool& color);

    ~torre();

    const bool movLegal(casilla& destino) const;

    const void imprimir(ostream& salida) const;

};


#endif //AJEDREZ_TORRE_H
