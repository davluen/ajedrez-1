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

    bool movLegal(casilla& destino);

    void imprimir(ostream& salida);

};


#endif //AJEDREZ_REINA_H
