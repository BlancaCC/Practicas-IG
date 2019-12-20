#ifndef MODELO_JER_3_H
#define MODELO_JER_3_H

#include "objeto3d.h"
#include "grafo-escena.h"

class CuboColocado : public NodoGrafoEscena{
	public:
		CuboColocado(std::vector<Matriz4f *>& traslacion);
};

class TiraCubos : public NodoGrafoEscena{
	protected:
		std::vector<Matriz4f *> traslaciones;
		int nCubos;
		void actualizarEstadoParametro(const unsigned iParam, const float t_sec );
	public:
		TiraCubos(int n);
		unsigned leerNumParametros() const;
        void fijarTraslacion(const float k); 
};

#endif
