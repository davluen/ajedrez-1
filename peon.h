//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#ifndef AJEDREZ_PEON_H
#define AJEDREZ_PEON_H

#include "pieza.h"

class casilla;
class tablero;


class peon : public pieza {
public:
    peon();

    peon(bool& color);

    ~peon();

    bool movLegal(casilla& destino);

    void imprimir(ostream& salida);


private:
    //TODO: variable promocion
};


#endif //AJEDREZ_PEON_H
