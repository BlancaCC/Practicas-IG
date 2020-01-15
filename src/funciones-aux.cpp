/* ************************************************************************* *
 * Fichero: funciones-aux.cpp                                           	 *
 * Autor: Juan Antonio Villegas Recio                                   	 *
 * Informática Gráfica Curso 2019-2020                                       *
 * Descripción: En este fichero implemento las funciones y métodos genericos *
 * que me hayan ido haciendo falta durante el desarrollo de las              *
 * prácticas de la asignatura y estas no se hayan pedido explícitamente      *
 * o no se hayan proporcionado.                                              *
 * ************************************************************************* */

#include "matrices-tr.h"
#include "matrizg.h"

using namespace std;

//----------------------------------------------------------------------
// Función que devuelve la matriz asociada a una transformacion lineal
// de tipo cizalla que desplaza X en proporción a Y en un factor a

Matriz4f MAT_Cizalla_xy(float a){
    Matriz4f res = MAT_Ident();
    res(0,1) = a;
    return res ;
}


//----------------------------------------------------------------------
// Función que a partir de una tupla RGB flotante calcula el
// identificador de objeto correspondiente.

int calculaIdent(Tupla3f color){
    int 
        r = (int) (color(R)*255),
        g = (int) (color(G)*255),
        b = (int) (color(B)*255);

    return r + ( 0x100U*g ) + (0x10000U*b) ;
}
