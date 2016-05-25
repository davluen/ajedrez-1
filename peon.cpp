//
// Created by Daniel Sánchez Vicente on 20/5/16.
//

#include "peon.h"
#include "pieza.h"
#include "casilla.h"
#include "tablero.h"

//NOTA: las blancas comienzan en las casillas bajas (0,1)
//		las negras comienzan en las casillas altas (6,7)

#define DIREC_B -1
#define DIREC_N 1
#define FIN_N 7
#define FIN_B 0

peon::peon() { }

peon::peon(bool &color) : pieza(color) {

}

peon::~peon() {

}

bool peon::movLegal(casilla &destino) {

    int direccion=DIREC_B; //Blancas por defecto para ahorrarnos un else
    bool esLegal=false;

    if(this->color()==0){
        direccion=DIREC_N;
    }  // Por si la pieza es negra

    if(_ascension){
        esLegal=_ascension.moveLegal(destino);
    }

    else {
        if(!destino.ocupada()){
            // Está libre el destino?
            if(destino.coordY()==this->posicion().coordX())
                //está en dirección vertical?
            if(!pieza::movida()){
                //Ha sido movido el peon anteriormente?
                if(destino.coordX()==(this->posicion.coordX()+2*direccion)){
                    // Si va a mover dos casillas a la vez
                    if(!(tablero::getTablero().casillaPorCoord(this->posicion.coordX()+1*direccion,this->posicion.coordY()).ocupada())){
                        //Este if toma el tablero y, con las coordenadas de la posicion, comprueba si la casilla delantera o trasera está libre
                        esLegal=true;
                    }
                }
            }
            if(destino.coordX()==(this->posicion.coordX()+1*direccion)){
                esLegal=true;
            }
        }
    }

    else if((destino.coordX()==(this->posicion.coordX()+1*direccion))&&((destino.coordY()==(this->posicion.coordY()+1))||(destino.coordY()==(this->posicion.coordY()-1))){
        //Movimiento oblicuo: si avanza 1 y se mueve a derecha o izquierda 1
        if(destino.ocupada().color()!=this->color()){
            esLegal=true;
        }
    }
}

return esLegal;

}

void peon::imprimir(ostream& salida)
{
    salida << color() << string("A");
}

