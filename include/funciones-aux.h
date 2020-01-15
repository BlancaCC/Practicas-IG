/* ******************************************************************** *
 * Fichero: funciones-aux.h                                             *
 * Autor: Juan Antonio Villegas Recio                                   *
 * Informática Gráfica Curso 2019-2020                                  *
 * Descripción: En este fichero declaro las funciones auxiliares y      *
 * métodos que me hayan ido haciendo falta durante el desarrollo de las *
 * prácticas de la asignatura y estas no se hayan pedido explícitamente *
 * o no se hayan proporcionado.                                         *
 * ******************************************************************** */

#ifndef FUN_AUX
#define FUN_AUX


//----------------------------------------------------------------------
// Función que devuelve la matriz asociada a una transformacion lineal
// de tipo cizalla que desplaza X en proporción a Y en un factor a

Matriz4f MAT_Cizalla_xy(float a);

//----------------------------------------------------------------------
// Función que a partir de una tupla RGB flotante calcula el
// identificador de objeto correspondiente. Implemento esta funcion por
// comodidad a la hora de asignar identificadores a los objetos

int calculaIdent(Tupla3f color);

#endif
