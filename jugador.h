//
// Created by Daniel Sánchez Vicente on 15/5/16.
//

#ifndef AJEDREZ_JUGADOR_H
#define AJEDREZ_JUGADOR_H


class jugador {
public:
    jugador();

    jugador(string nombre, rey* miRey, set<pieza*>* misPiezas);

    string& nombre();

    set<pieza*>& misPiezas();

    rey& miRey();

//    int puntuacion();

    bool movimiento();

    void capturar(pieza& piezaCapturada);

private:
    string _nombre;

    rey* _miRey;
    set<pieza*>* _misPiezas;
    set<pieza*>* _piezasCapturadas;



};


#endif //AJEDREZ_JUGADOR_H
