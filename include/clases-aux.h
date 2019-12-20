/* ******************************************************************** *
 * Fichero: clases-aux.h                                                *
 * Autor: Juan Antonio Villegas Recio                                   *
 * Informática Gráfica Curso 2019-2020                                  *
 * Descripción: En este fichero declaro las clases, sus atributos y     *
 * métodos que me hayan ido haciendo falta durante el desarrollo de las *
 * prácticas de la asignatura y estas no se hayan pedido explícitamente *
 * o no se hayan proporcionado.                                         *
 * ******************************************************************** */

#ifndef CLASES_AUX
#define CLASES_AUX

#include "malla-revol.h"

//----------------------------------------------------------------------
// Clase CoronaCilindrica (derivada de MallaRevol). Utilizada para
// representar el enganche del cuerpo de la atracción al tubo de la 
// práctica 3.
class CoronaCilindrica : public MallaRevol
{
public:
      // Constructor: crea el perfil original y llama a inicializar
      // Se necesita saber el radio del primer cilindro y del segundo
      CoronaCilindrica(
         const int num_verts_per,         // número de vértices del perfil original (M )
         const unsigned nperfiles ,        // número de perfiles (N )
         const float r1,                  //Radio del cilindro mas interno
         const float r2                   //Radio del cilindro mas externo
      ) ;
} ;

#endif
