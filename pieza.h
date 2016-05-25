//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#ifndef AJEDREZ_PIEZA_H
#define AJEDREZ_PIEZA_H


class pieza{
public:
    pieza();

    pieza(bool& color){}

    virtual ~pieza();

    string& color();

    casilla& posicion();

    bool moverPieza(jugador &jugadorActual, casilla &destino);

    bool poner(casilla* destino);

    void imprimir(ostream& salida);

    bool movLegal(casilla& destino);
private:
    bool _color;
    bool _primerMovimiento;
    casilla* _posicion;
};


#endif //AJEDREZ_PIEZA_H
