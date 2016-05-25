//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#include"tablero.h"
#include"casilla.h"

tablero::tablero(int dimension){
    //Vector de casillas de la clase vector
    std::vector<casilla> fila(dimension);

    for(int i=0;i<dimension;i++){
        //Recordamos que _casillas es un vector de vectore de casilla
        //Así pues, crearemos 8 vectores de 8 componentes casilla, esto es, una matriz.
        _casillas.push_back(fila);
    }

    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            //creamos un nuevo puntero a una casilla
            casilla* nueva= new casilla(i,j);

            //asignamos dicho puntero al miembro correspondiente de la matriz
            _casillas[i][j]=*nueva;
        }
    }
}

tablero::~tablero(){

}

casilla& tablero::casillaPorCoord(int x, int y) {
    return _casillas.at(x).at(y);
}

//Funciones que comprueban si está libre el camino

bool tablero::comprobarVertical(casilla& origen, casilla& destino){
    bool libre=true;

    //Suponemos que avanza por defecto
    int direccion=1;
    if(origen.coordX()>destino.coordX()) direccion=-1;

    for (int i = 1; i < abs(origen.coordX() - destino.coordX()); i++) {
        if (this->getTablero().casillaPorCoord(origen.coordX() + i * direccion, origen.coordY()).ocupada()) libre = false;
    }
    return libre;
}

bool tablero::comprobarHorizontal(casilla& origen, casilla& destino){
    bool libre=true;
    int direccion=1;

    if(origen.coordY() > destino.coordY()) direccion = -1;

    for(int i = 1; i < abs(origen.coordY() - destino.coordY()); i++){
        if(this->getTablero().casillaPorCoord(origen.coordX(),origen.coordY()+i*direccion).ocupada()) libre=false;
    }

    return libre;
}


bool tablero::comprobarDiagonal(casilla& origen, casilla& destino){
    bool libre=true;
    int dirX=1,dirY=1;
    if(origen.coordY()>destino.coordY()) dirY = -1;
    if(origen.coordX()>destino.coordX()) dirX = -1;

    for(int i=1; i < abs(origen.coordX() - destino.coordX()); i++){
        for(int j=1; j < abs(origen.coordY() - destino.coordY()); j++){
            if(this->getTablero().casillaPorCoord(origen.coordX()+i*dirX,origen.coordY()+j*dirY).ocupada()) libre=false;
        }
    }

    return libre;
}


//Salida por pantalla

void tablero::imprimir(ostream& salida) const{

salida << "    a   b   c   d   e   f   g   h" << endl;
for(int i=0; i < this->getDimensiones(); i++){

    //Parte superior de las casilla
    salida<<(8-i)<<" .";

    for(int j=0; j < this->getDimensiones(); j++){

        if(!(abs(i+j)%2)) salida<<"####";
        else salida<<"    ";
    }

    salida<<endl;

    salida<<"   ";

    for(int j=0; j < this->getDimensiones(); j++){

        if(!(abs(i+j)%2)){
            salida<<"#";
            //Si la casilla está vacía la pinta de negro entera
            if(_casillas[i][j].ocupada()) _casillas[i][j].imprimir(salida);
            else salida << "##";

            salida<<"#";
        }

        else {
            salida<<" ";
            _casillas[i][j].imprimir(salida);
            salida <<" ";
        }

        }

    salida << endl;
    //Parte inferior de las casilla
    salida<<"   ";

    for(int j=0; j < this->getDimensiones(); j++){

        if(!(abs(i+j)%2)) salida<<"####";
        else salida<<"    ";
    }

    salida<<". "<<(8-i)<<endl;

    }

    salida<<"    a   b   c   d   e   f   g   h"<<endl;
}



//Obtencion de variables privadas

tablero& tablero::getTablero(){
    return _tablero;
}

int tablero::getDimensiones() const{
    return _casillas.size();
}


//Operador amigo

ostream& operator<< (ostream& salida, const tablero& tablero)
{
    // Para llamar a la impresion del tablero en el juego
    tablero.imprimir(salida);
    return salida;
}


//variables

const int tablero::_DIMENSIONES = 8;
tablero tablero::_tablero;