/* ******************************************************************** *
 * Fichero: clases-aux.cpp                                              *
 * Autor: Juan Antonio Villegas Recio                                   *
 * Informática Gráfica Curso 2019-2020                                  *
 * Descripción: En este fichero implemento los métodos de las clases    *
 * que me hayan ido haciendo falta durante el desarrollo de las         *
 * prácticas de la asignatura y estas no se hayan pedido explícitamente *
 * o no se hayan proporcionado.                                         *
 * ******************************************************************** */


#include "clases-aux.h"
#include "objeto3d.h"

//-------------------------------------------------------------------------
// Constructor de la clase CoronaCilindrica. 

CoronaCilindrica::CoronaCilindrica
(
   const int num_verts_per,
   const unsigned nperfiles ,
   const float r1,
   const float r2
)
{
   assert(r1<r2);
   std::vector<Tupla3f> perfil;
   perfil.push_back( { r1, 0.0, 0.0 } );
   for(int i = 0; i < num_verts_per/2-2; i++)
      perfil.push_back( { r1, (float)i/(float)(num_verts_per/2-3), 0.0} );
   perfil.push_back( { r1, 1.0, 0.0} );

   perfil.push_back( { r2, 0.0, 0.0 } );
   for(int i = 0; i < num_verts_per/2-2; i++)
      perfil.push_back( { r2, (float)i/(float)(num_verts_per/2-3), 0.0} );
   perfil.push_back( { r2, 1.0, 0.0} );

   inicializar(perfil, nperfiles);
}
