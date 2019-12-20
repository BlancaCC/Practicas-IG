/* ******************************************************************** *
 * Fichero: modelo-jer.h                                             	*
 * Autor: Juan Antonio Villegas Recio                                   *
 * Informática Gráfica Curso 2019-2020                                  *
 * Descripción: Declaración de clases derivadas de NodoGrafoEscena que	*
 * forman el modelo jerárquico desarrollado en la práctica 3.			*
 * ******************************************************************** */
 
#ifndef MODELO_JER_H
#define MODELO_JER_H

#include "grafo-escena.h"


//-----------------------------------------------------------------------
// Nodo Raíz del grafo
class C : public NodoGrafoEscena
{
     protected:
        Matriz4f * traslacion      = nullptr;		// Matriz asociada a la traslación de un lado a otro del cuerpo de la atracción
        Matriz4f * rotacionCuerpo  = nullptr;		// Matriz asociada al movimiento de rotación en torno al tubo del cuerpo
        Matriz4f * rotacionRotor   = nullptr;		// Matriz asociada a la rotación del rotor sobre sí mismo
        Matriz4f * traslacionRotor = nullptr;		// Matriz asociada al movimiento del rotor de arriba a abajo sobre el tubo del rotor
        
        void actualizarEstadoParametro( const unsigned iParam, const float t_sec );

    public:
        C();
        unsigned leerNumParametros() const;
        void fijarTraslacion(const float nueva_tras);         	// Fija el vector de traslacion del cuerpo
        void fijarRotacionCuerpo(const float nueva_rotC);		// Fija el angulo que forma el cuerpo con respecto al plano XY
        void fijarRotacionRotor(const float nueva_rotR);        // Fija el angulo de rotacion del rotor
        void fijarTraslacionRotor(const float nueva_trasR);		// Fija el vector de traslacion del rotor
};

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como CilindroParam (Cilindro Paramétrico)
class CilindroParam : public NodoGrafoEscena{
    public:
        CilindroParam(  const int num_verts_per,
                        const unsigned nperfiles,
                        const float radio,
                        const float altura );			// constructor
};

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como MediaPata
class MediaPata : public NodoGrafoEscena
{ 
    public:
        MediaPata() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Pata
class Pata : public NodoGrafoEscena
{ 
    public:
        Pata() ; // constructor
} ;

class Bola : public NodoGrafoEscena{
    public:
        Bola();
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como DosPatas
class DosPatas : public NodoGrafoEscena
{ 
    public:
        DosPatas() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Tubo
class Tubo : public NodoGrafoEscena
{ 
    public:
        Tubo() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Estructura
class Estructura : public NodoGrafoEscena
{ 
    public:
        Estructura() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como MedioReposabrazos
class MedioReposabrazos : public NodoGrafoEscena
{ 
    public:
        MedioReposabrazos() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Reposabrazos
class Reposabrazos : public NodoGrafoEscena
{
    public:
        Reposabrazos() ;  // constructor
};

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como AsientoSeguro
class AsientoSeguro : public NodoGrafoEscena
{
    public:
        AsientoSeguro();  // constructor
};

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como FilaAsientos
class FilaAsientos : public NodoGrafoEscena
{ 
    public:
        FilaAsientos() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Conector
class Conector : public NodoGrafoEscena
{ 
    public:
        Conector() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como FilaConector
class FilaConector : public NodoGrafoEscena
{ 
    public:
        FilaConector() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Rotor
class Rotor : public NodoGrafoEscena
{ 
    public:
        Rotor ( Matriz4f * &rotacionRotor, Matriz4f * &traslacionRotor ) ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como RemateTuboRotor
class RemateTuboRotor : public NodoGrafoEscena
{
    public:
        RemateTuboRotor(); // constructor
};

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como TuboRotor
class TuboRotor : public NodoGrafoEscena
{ 
    public:
        TuboRotor() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Enganche
class Enganche : public NodoGrafoEscena
{ 
    public:
        Enganche() ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Cuerpo
class Cuerpo : public NodoGrafoEscena
{
    public:
        Cuerpo(Matriz4f * &rotacionCuerpo, Matriz4f * &rotacionRotor, Matriz4f * &traslacionRotor) ; // constructor
} ;

//----------------------------------------------------------------------------------
// clase para el nodo del grafo etiquetado como Atraccion
class Atraccion : public NodoGrafoEscena
{
    public:
        Atraccion( Matriz4f * &traslacion,    Matriz4f * &rotacionCuerpo, 	
                   Matriz4f * &rotacionRotor, Matriz4f * &traslacionRotor );		// constructor
};

#endif
