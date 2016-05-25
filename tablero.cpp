//
// Created by Daniel Sánchez Vicente on 19/5/16.
//

#include"tablero.h"
#include"casilla.h"

tablero::tablero(int dimension){
    //Vector de casillas de la clase vector
    DIM=dimension;
    std::vector<casillas> fila(DIM);

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

//Funciones que comprueban si está libre el camino

bool tablero::comprobarVertical(casilla& origen, casilla& destino){
    bool libre=true;

    //Suponemos que avanza por defecto
    int direccion=1;
    if(origen.coordX()>destino.coodX()) direccion=-1;

    if(this->getTablero().casillaPorCoord(origen.coordX()+i*direccion,origen.coordY()).ocupada()) libre=false;

    return libre;
}

bool tablero::comprobarHorizontal(casilla& origen, casilla& destino){
    bool libre=true;
    int direccion=1;
    if(origen.coordY()>destino.coodY()) direccion = -1;

    for(int i=0; i<abs(origen.coordY()>destino.coodY()); i++){
        if(this->getTablero().casillaPorCoord(origen.coordX(),origen.coordY()+i*direccion).ocupada()) libre=false;
    }

    return libre;
}

bool tablero::comprobarHorizontal(casilla& origen, casilla& destino){
    bool libre=true;
    int direccion=1;
    if(origen.coordY()>destino.coodY()) direccion = -1;

    for(int i=0; i<abs(origen.coordY()>destino.coodY()); i++){
        if(this->getTablero().casillaPorCoord(origen.coordX(),origen.coordY()+i*direccion).ocupada()) libre=false;
    }

    return libre;
}

bool tablero::comprobarDiagonal(casilla& origen, casilla& destino){
    bool libre=true;
    int dirX=1,dirY=1;
    if(origen.coordY()>destino.coodY()) dirY = -1;
    if(origen.coordX()>destino.coodX()) dirX = -1;

    for(int i=0; i<abs(origen.coordX()>destino.coodX()); i++){
        for(int j=0; j<abs(origen.coordY()>destino.coodY()); j++){
            if(this->getTablero().casillaPorCoord(origen.coordX()+i*dirX,origen.coordY()+j*dirY).ocupada()) libre=false;
        }
    }

    return libre;
}


//Salida por pantalla

tablero::imprimir(ostream%){

output<<"    a    b    c    d    e    f    g    h"<<endl;
for(int i=0;i<this->getDimension();i++){

//Parte superior de las casilla
output<<(8-i)<<" .";
for(int j=0;j<this->getDimension();j++){
if(!(abs(i+j)%2)) output<<"####";
else output<<"    ";
}
output<<endl;

output<<"    ";
for(int j=0;j<this->getDimension();j++){
if(!(abs(i+j)%2)) output<<"#"<<_casillas[i][j].imprimir(output)<<"#";
else output<<" "<<_casillas[i][j].imprimir(output)<<" ";
}
output<<". "<<(8-i)<<endl;
}
output<<"    a    b    c    d    e    f    g    h"<<endl;
}


//Obtencion de variables privadas

tablero& tablero::getTablero(){
    return _tablero;
}

int getDimension(){
    return DIM;
}


//Operador amigo

ostream& operator<< (ostream& output, tablero& tablero)
{
    // Para llamar a la impresion del tablero en el juego
    tablero.impreimir(output);
    return output;
}


//variables

int tablero::DIM;
tablero tablero::_tablero;