//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#ifndef AJEDREZ_CABALLO_H
#define AJEDREZ_CABALLO_H

#include "pieza.h"

class casilla;
class tablero;


class caballo : public pieza {
public:
    caballo();

    caballo(bool& color);

    ~caballo();

    const bool movLegal(casilla& destino) const;

    const void imprimir(ostream& salida) const;

};


#endif //AJEDREZ_CABALLO_H
