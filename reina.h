//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#ifndef AJEDREZ_REINA_H
#define AJEDREZ_REINA_H

#include "pieza.h"

class casilla;
class tablero;


class reina : public pieza {
public:
    reina();

    reina(bool& color);

    ~reina();

    const bool movLegal(casilla& destino) const;

    const void imprimir(ostream& salida) const;
};


#endif //AJEDREZ_REINA_H
