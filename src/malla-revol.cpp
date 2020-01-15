// *********************************************************************
// **
// ** Informática Gráfica, curso 2019-20
// ** Implementación de la clase 'MallaRevol'
// **
// *********************************************************************

#include "ig-aux.h"
#include "tuplasg.h"
#include "lector-ply.h"
#include "matrices-tr.h"
#include "malla-revol.h"

#include <cmath>

using namespace std ;

// *****************************************************************************



void MallaRevol::calcularNormales(){
   
}


// Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
// a partir de un perfil y el número de copias que queremos de dicho perfil.
void MallaRevol::inicializar
(
   const std::vector<Tupla3f> & perfil,     // tabla de vértices del perfil original
   const unsigned               num_copias  // número de copias del perfil
)
{
   //calcularNormales
   
   std::vector<Tupla3f> normalesAristas, vertsAux;
   Tupla3f normal, aux;
   for(unsigned i = 0; i<perfil.size()-1; i++){

      aux = (perfil[i+1]-perfil[i]);
      normal(0)=aux(1);
      normal(1)=-aux(0);
      normal(2)=0;
      if(normal.lengthSq()>0)
         normalesAristas.push_back(normal.normalized());
      else
         normalesAristas.push_back(normal);
      
   }

   nor_ver.insert(nor_ver.begin(), perfil.size(), {0.0, 0.0 , 0.0});
   if(normalesAristas[0].lengthSq()!=0)
      nor_ver[0]=normalesAristas[0].normalized();
   
   for(unsigned i=1; i<perfil.size()-1; i++){
      nor_ver[i]=normalesAristas[i]+normalesAristas[i-1];
      if(nor_ver[i].lengthSq()!=0)
         nor_ver[i]=nor_ver[i].normalized();
   }

   if(normalesAristas[perfil.size()-2].lengthSq()!=0)
      nor_ver[perfil.size()-1]=normalesAristas[perfil.size()-2];


   // Calcular Coordenadas de textura

   std::vector<float> d, t;
   float den=0;
   for(unsigned int i = 0; i<perfil.size()-1; i++){
      d.push_back(sqrt((perfil[i+1]-perfil[i]).lengthSq()));
      den += d[i];
   }
   t.push_back(0);
   for(unsigned int i = 1; i<perfil.size(); i++)
      t.push_back(t[i-1]+d[i-1]/den);
   
   // COMPLETAR: Práctica 2: completar: creación de la malla....
   const int m = perfil.size();
   int k;
   Tupla3f q;
   Matriz4f rot;
   Tupla2f textura;
   float t_x, t_y;
   
   for (unsigned i = 0; i < num_copias; i++){
      rot = MAT_Rotacion((360.0*i)/(num_copias-1), 0.0, 1.0, 0.0);
      for (int j = 0; j < m; j++){
         q = rot * perfil[j];
         nor_ver.push_back(rot*nor_ver[j]);
         t_x = (float)i/(num_copias-1);
         t_y = 1.0-t[j];
         textura = {t_x, t_y};
         vertices.push_back(q);
         cc_tt_ver.push_back(textura);
      }
   }

   for (unsigned i = 0; i < num_copias-1; i++){
      for (int j = 0; j < m-1; j++){
         k = i*m+j;
         triangulos.push_back({k, k+m, k+m+1});
         triangulos.push_back({k, k+m+1, k+1});
      }
   }


}

// -----------------------------------------------------------------------------
// constructor, a partir de un archivo PLY

MallaRevolPLY::MallaRevolPLY
(
   const std::string & nombre_arch,
   const unsigned      nperfiles
)
{
   ponerNombre( std::string("malla por revolución del perfil en '"+ nombre_arch + "'" ));
   // COMPLETAR: práctica 2: crear la malla de revolución
   // Leer los vértice del perfil desde un PLY, después llamar a 'inicializar'
   vector<Tupla3f> perfil;
   LeerVerticesPLY(nombre_arch, perfil);
   inicializar(perfil, nperfiles);
}

// ------------------------------------------------------------------------------
Cilindro::Cilindro
(
   const int num_verts_per,
   const unsigned nperfiles 
)
{
   ponerNombre(std::string("Cilindro generado por revolución"));
   assert(num_verts_per >= 4); // Al menos se necesitan 4 vértices para generar el cilindro

   ponerNombre( std::string("Cilindro generado por revolución" ));
   vector<Tupla3f> perfil;
   float y;
   perfil.push_back( { 0.0, -1.0, 0.0 } );
   for(int i = 0; i < num_verts_per-2; i++){
	  y = -1.0+(2.0*(float)i/(num_verts_per-3));
      perfil.push_back( { 1.0, y, 0.0} );
   }
   perfil.push_back( { 0.0, 1.0, 0.0} );
   
   inicializar(perfil, nperfiles);
}

Cono::Cono
(
   const int num_verts_per,
   const unsigned nperfiles 
)
{
   ponerNombre(std::string("Cono generado por revolución"));	
   assert(num_verts_per >= 3); // Al menos se necesitan 3 vértices para generar el cono

   ponerNombre( std::string("Cono generado por revolución" ));
   vector<Tupla3f> perfil;
   perfil.push_back( { 0.0, 0.0, 0.0 } );
   for(int i = 0; i < num_verts_per-1; i++)
      perfil.push_back( { 1-(float)i/(num_verts_per-2), (float)i/(num_verts_per-2), 0.0} );
   
   inicializar(perfil, nperfiles);
}

Esfera::Esfera
(
   const int num_verts_per,
   const unsigned nperfiles 
)
{
   ponerNombre(std::string("Esfera generada por revolución"));
   
   Tupla3f q;
   Matriz4f rot;
   assert(num_verts_per >= 3); // Al menos se necesitan 3 vértices para generar la esfera

   ponerNombre( std::string("Cono generado por revolución" ));
   vector<Tupla3f> perfil;
   perfil.push_back({ 0.0, -1.0, 0.0 });
   for (int i = 1; i < num_verts_per; i++)
   {
      rot = MAT_Rotacion((180.0*i)/(num_verts_per-1), 0.0, 0.0, 1.0);
      q = rot * perfil[0];
      perfil.push_back(q);
   }
   
   inicializar(perfil, nperfiles);
}
