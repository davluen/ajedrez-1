//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#ifndef AJEDREZ_PIEZA_H
#define AJEDREZ_PIEZA_H

#include <string>

using namespace std;

class casilla;
class jugador;
class tablero;
class rey;
class juego;


class pieza{
public:
    pieza();

    pieza(bool& color);

    virtual ~pieza();

    virtual const bool& color() const;

    virtual casilla& posicion() const;

    virtual const bool moverPieza(const jugador& jugadorActual, casilla& destino);

    virtual void poner(casilla* destino);

    virtual const void imprimir(ostream& salida) const  = 0;

    virtual const bool movLegal(casilla& destino) const = 0;

    const bool movida() const;

    virtual bool enJuego();
private:
    bool _color;
    bool _primerMovimiento;
    casilla* _posicion;
};


#endif //AJEDREZ_PIEZA_H
