/* ******************************************************************** *
 * Fichero: modelo-jer.cpp                                             	*
 * Autor: Juan Antonio Villegas Recio                                   *
 * Informática Gráfica Curso 2019-2020                                  *
 * Descripción: Implementación de constructores de las clases que 		*
 * componen el modelo jerárquico junto con el código necesario para las *
 * animaciones de la atracción.											*
 * ******************************************************************** */

#include "modelo-jer.h"
#include "malla-ind.h"
#include "funciones-aux.h"
#include "clases-aux.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include "materiales-luces.h"
#include <cmath>

//-----------------------------------------------------------------------
// Implementación del constructor de la clase C
C :: C(){
	ponerNombre("La Revuelta");
    agregar(new Atraccion(traslacion, rotacionCuerpo, rotacionRotor, traslacionRotor));
}

//-----------------------------------------------------------------------
// Funcion de consulta que devuelve el número de parámetros activos
unsigned C :: leerNumParametros() const{
    return 4;
}

void C :: fijarTraslacion(const float nueva_tras){
    *traslacion = MAT_Traslacion(nueva_tras, 0.0, 0.0);
}

void C :: fijarRotacionCuerpo(const float nueva_rotC){
    *rotacionCuerpo = MAT_Traslacion(0.0, 6.0, 0.0)*
                      MAT_Rotacion(nueva_rotC, 1.0, 0.0, 0.0)*
                      MAT_Traslacion(0.0, -6.0, 0.0);
}

void C :: fijarRotacionRotor(const float nueva_rotR){
    *rotacionRotor = MAT_Rotacion(nueva_rotR, 0.0, 1.0, 0.0);
}

void C :: fijarTraslacionRotor(const float nueva_trasR){
    *traslacionRotor = MAT_Traslacion(0.0, nueva_trasR, 0.0);
}

//-----------------------------------------------------------------------
// Implementación de la función que modifica el estado de los distintos
// parámetros que tiene la atracción.
void C :: actualizarEstadoParametro( const unsigned iParam, const float t_sec ){
    assert(iParam < leerNumParametros());
    switch (iParam){
    case 0:
        fijarTraslacion(1.5 * sin(0.5*M_PI*t_sec));
        break;
    case 1:
        fijarRotacionCuerpo( 90 * sin(0.5*M_PI*t_sec) );
        break;
    case 2:
        fijarRotacionRotor( 180.0 * t_sec );
        break;
    case 3:
        fijarTraslacionRotor( 1.0 + sin(0.3*M_PI*t_sec ));
    }
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase CilindroParam
CilindroParam :: CilindroParam( const int num_verts_per,
                                const unsigned nperfiles,
                                const float radio,
                                const float altura  )
{
    agregar( MAT_Escalado( radio, altura/2, radio ) );
    agregar( new Cilindro(num_verts_per, nperfiles) );

    ponerIdentificador(-1);
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase MediaPata
MediaPata :: MediaPata(){
    agregar( MAT_Rotacion(30.0,0.0,1.0,0.0) );
    agregar( MAT_Traslacion(-6.0,0.0,0.0));
    agregar( MAT_Cizalla_xy(1.0) );
    agregar( MAT_Traslacion(0.25,3.0,0.0) );
    agregar( MAT_Escalado(0.25, 3.0, 0.25) );
    agregar( new Cubo24() );

    ponerIdentificador(-1);
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Pata
Pata :: Pata(){
    agregar( new Material( new Textura("./imgs/pata.jpg"), 0.1, 0.8, 0.1, 25));
    ponerColor({0.0, 0.0, 1.0});
    agregar( new MediaPata() );
    agregar( MAT_Escalado(1.0, 1.0, -1.0) );
    agregar( new MediaPata() );
    agregar(new Bola());

    ponerNombre("Pata");
    ponerIdentificador(0xFF);
    
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase DosPatas
DosPatas :: DosPatas(){
    agregar( MAT_Traslacion(-4.0, 0.0, 0.0) );
    agregar( new Pata() );
    agregar( MAT_Traslacion(8.0, 0.0, 0.0) );
    agregar( MAT_Escalado(-1.0, 1.0, 1.0) );
    agregar( new Pata() );

    ponerIdentificador(0);
}

Bola :: Bola(){
    agregar( MAT_Traslacion( 0.0, 6.0, 0.0 ) );
    agregar( MAT_Escalado(0.7,0.5,0.5) );
    agregar( new Material(0.1, 0.1,0.8,20));
    agregar(new Material(new Textura("./imgs/bolaDisco.jpg"), 0.1, 0.8, 0.1,20));
    agregar( new Esfera(20,20) );

    ponerIdentificador(0xFF+1);
    ponerNombre("Bola");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Tubo
Tubo :: Tubo(){
    agregar(new Material(0.2,0.8,0.1,20));
    agregar( MAT_Rotacion(90.0, 0.0, 0.0, 1.0) );
    agregar( new CilindroParam(10,50, 0.25, 8.0) );
    ponerColor({1.0,1.0,1.0});  

    ponerIdentificador(0xFF+2);
    ponerNombre("Tubo");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Estructura
Estructura :: Estructura(){
    agregar( new DosPatas() );
    agregar( MAT_Traslacion(0.0, 6.0, 0.0) );
    agregar( new Tubo() );

    ponerIdentificador(0);
    ponerNombre("Estructura");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase MedioReposabrazos
MedioReposabrazos :: MedioReposabrazos(){
    agregar( MAT_Cizalla_xy(1.0) );
    agregar( MAT_Escalado(0.05,0.125,0.1) );
    agregar( MAT_Traslacion(1.0,1.0,1.0) );
    agregar( new Cubo24() );

    ponerIdentificador(-1);
    ponerNombre("Medio Reposabrazos");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Reposabrazos
Reposabrazos :: Reposabrazos(){
    agregar( MAT_Traslacion(0.0, 0.25, 0.75) );
    agregar( MAT_Escalado(1.0, 1.0, -1.0) );
    agregar( MAT_Traslacion(0.0, 0.0, 0.5) );
    agregar( MAT_Rotacion(90.0, 0.0, 1.0, 0.0) );
    agregar( new MedioReposabrazos() );
    agregar( MAT_Traslacion(0.25,0.15,0.0) );
    agregar( MAT_Escalado(0.12,0.05,0.1) );
    agregar( MAT_Traslacion(1.0,1.0,1.0) );
    agregar( new Cubo24() );
    ponerColor({0.0, 0.0, 0.0});

    ponerNombre("Reposabrazos");
    ponerIdentificador(-1);
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase AsientoSeguro
AsientoSeguro :: AsientoSeguro(){
    agregar( new Material(0.1,0.8,0.1,25));
    agregar( new MallaPLY("./plys/asiento.ply") );
    agregar( new Reposabrazos() );
    agregar( MAT_Traslacion(0.75, 0.0, 0.0) );
    agregar( new Reposabrazos() );
    ponerColor({1.0, 0.0, 0.0});

    ponerIdentificador(0xFF+3);
    ponerNombre("Asiento Seguro");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase FilaAsientos
FilaAsientos :: FilaAsientos(){
    agregar( MAT_Traslacion(0.0, 0.0, 1.0) );
    agregar( MAT_Escalado(1.0, 1.0, -1.0 ) );
    agregar(new AsientoSeguro() );
    agregar( MAT_Traslacion(1.0, 0.0, 0.0) );
    agregar(new AsientoSeguro() );
    agregar( MAT_Traslacion(1.0, 0.0, 0.0) );
    agregar(new AsientoSeguro() );
    agregar( MAT_Traslacion(1.0, 0.0, 0.0) );
    agregar(new AsientoSeguro() );
    agregar( MAT_Traslacion(-1.0, 0.45, 0.5) );
    agregar( MAT_Rotacion(90, 0.0,0.0,1.0) );
    agregar(new CilindroParam(4, 20, 0.025, 4) );

    ponerNombre("Fila de Asientos");
    ponerIdentificador(0xFF+4);
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Conector
Conector :: Conector(){
    agregar(new Material(0.1,0.1,0.8,25));
    agregar( MAT_Cizalla_xy(1.53) );
    agregar( MAT_Escalado(0.25, 1.0, 0.25) );
    agregar( MAT_Traslacion( 1.0,1.0,1.0 ) );
    agregar( new Cubo24() );
    ponerColor({0.29, 0.30, 0.81});

    ponerIdentificador(-1);
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase FilaConector
FilaConector :: FilaConector(){
    agregar( MAT_Traslacion(-2.0, 0.0, 2.0) );
    agregar( new FilaAsientos() );
    agregar( MAT_Rotacion(45.0, 0.0, 1.0, 0.0));
    agregar( MAT_Traslacion(-0.25, 0.0, -0.25));
    agregar( new Conector() );

    ponerIdentificador(-1);
    ponerNombre("Fila de Asientos + Conector");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Rotor
Rotor :: Rotor ( Matriz4f * &rotacionRotor, Matriz4f * &traslacionRotor ){
    unsigned ind1, ind2;
    ind1 = agregar( MAT_Rotacion( 0.0, 0.0, 1.0, 0.0 ) );
    ind2 = agregar( MAT_Traslacion(0.0, 0.0, 0.0) );
    agregar( new FilaConector() );
    agregar( MAT_Rotacion(90.0, 0.0, 1.0, 0.0));
    agregar( new FilaConector() );
    agregar( MAT_Rotacion(90.0, 0.0, 1.0, 0.0));
    agregar( new FilaConector() );
    agregar( MAT_Rotacion(90.0, 0.0, 1.0, 0.0));
    agregar( new FilaConector() );
    agregar( MAT_Traslacion(0.0, 2.0, 0.0) );
    //agregar( new Material (0.2, 0.8, 0.0, 25));
    agregar( new CilindroParam(4,8,0.6,0.5) );

    rotacionRotor = leerPtrMatriz(ind1);
    traslacionRotor = leerPtrMatriz(ind2);

    ponerNombre("Rotor");
    ponerIdentificador(0xFF00);
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase RemateTuboRotor
RemateTuboRotor :: RemateTuboRotor(){
    agregar( MAT_Traslacion(0.0,6.75,0.0) );
    agregar( MAT_Escalado(0.15,0.15,0.15) );
    agregar( new MallaPLY("../recursos/plys/beethoven.ply") );

    ponerIdentificador(0xFF01);
    ponerNombre("Remate del tubo del rotor");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase TuboRotor
TuboRotor :: TuboRotor(){
    agregar(new Material(0.1,0.1,0.8,20));
    agregar( new RemateTuboRotor() );
    agregar( MAT_Traslacion(0.0, 3, 0.0) );
    agregar( new CilindroParam(10,50,0.3,6) );
    ponerColor({0.34, 0.13, 0.39});

    ponerNombre("Tubo del Rotor");
    ponerIdentificador(-1);
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Enganche
Enganche :: Enganche(){
    agregar(new Material(new Textura("./imgs/bolaDisco.jpg"), 0.1, 0.8, 0.1,20));
    agregar( MAT_Rotacion(90.0, 0.0, 0.0, 1.0) );
    agregar( MAT_Escalado( 1.0, 0.8, 1.0 ) );
    agregar( MAT_Traslacion( 0.0, -0.5, 0.0 ));
    agregar( new CoronaCilindrica(10, 50, 0.25, 0.4));
    ponerColor( {1.0, 1.0, 1.0} );

    ponerIdentificador(-1);
    ponerNombre("Enganche");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Cuerpo
Cuerpo :: Cuerpo(Matriz4f * &rotacionCuerpo, Matriz4f * &rotacionRotor, 
				 Matriz4f * &traslacionRotor) 
{
    unsigned ind = agregar(     MAT_Traslacion(0.0, -6.0, 0.0)*
                                MAT_Rotacion(0.0, 1.0, 0.0, 0.0)*
                                MAT_Traslacion(0.0, 6.0, 0.0) );
    agregar( MAT_Traslacion(0.0, 0.75, 0.0) );
    agregar( new Rotor(rotacionRotor, traslacionRotor) );
    agregar( MAT_Traslacion(0.0, 2.0, 0.0) );
    agregar( new TuboRotor() );
    agregar( MAT_Traslacion(0.0, 3.25, 0.0) );
    agregar(new Material(new Textura("./imgs/bolaDisco.jpg"), 0.1, 0.8, 0.1,20));
    agregar( new Enganche() );

    rotacionCuerpo = leerPtrMatriz(ind);

    ponerIdentificador(0xFF02);
    ponerNombre("Cuerpo de la Atraccion");
}

//-----------------------------------------------------------------------
// Implementación del constructor de la clase Atraccion
Atraccion :: Atraccion( Matriz4f * &traslacion,    Matriz4f * &rotacionCuerpo, 
						Matriz4f * &rotacionRotor, Matriz4f * &traslacionRotor )
{
    agregar( new Estructura() );
    unsigned ind = agregar( MAT_Traslacion(0.0, 0.0, 0.0) );
    agregar( new Cuerpo(rotacionCuerpo, rotacionRotor, traslacionRotor) );
    
    traslacion = leerPtrMatriz(ind);

    ponerIdentificador(0);
    ponerNombre("Atraccion");
}



















