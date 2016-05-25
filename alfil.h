//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#ifndef AJEDREZ_ALFIL_H
#define AJEDREZ_ALFIL_H

#include "pieza.h"

class casilla;
class tablero;


class alfil : public pieza {
public:
    alfil();

    alfil(bool& color);

    ~alfil();

    const bool movLegal(casilla& destino) const;

    const void imprimir(ostream& salida) const;

};


#endif //AJEDREZ_ALFIL_H
