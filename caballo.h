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

    bool movLegal(casilla& destino);

    void imprimir(ostream& salida);

};


#endif //AJEDREZ_CABALLO_H
