//
// Created by Daniel Sánchez Vicente on 15/5/16.
//

#ifndef AJEDREZ_JUGADOR_H
#define AJEDREZ_JUGADOR_H

#include <set>
#include <string>

using namespace std;

class rey;
class pieza;
class tablero;

class jugador {
public:
    jugador();

    jugador(string nombre, rey* miRey, set<pieza*>* misPiezas);

    const string& nombre() const;

    const set<pieza*>& misPiezas() const;

    const rey& miRey() const;

//    int puntuacion();

    const bool movimiento() const;

    const void capturar(pieza& piezaCapturada) const;

private:
    string _nombre;

    rey* _miRey;
    set<pieza*>* _misPiezas;
    set<pieza*>* _piezasCapturadas;



};


#endif //AJEDREZ_JUGADOR_H
