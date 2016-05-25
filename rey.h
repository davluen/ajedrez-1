//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#ifndef AJEDREZ_REY_H
#define AJEDREZ_REY_H

#include "pieza.h"

class casilla;
class tablero;


class rey : public pieza {
public:
    rey();

    rey(bool& color);

    ~rey();

    const bool movLegal(casilla& destino) const;

    const void imprimir(ostream& salida) const;

};


#endif //AJEDREZ_REY_H
