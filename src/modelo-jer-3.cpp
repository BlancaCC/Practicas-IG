#include "modelo-jer-3.h"
#include "malla-ind.h"
#include "grafo-escena.h"
#include "matrices-tr.h"
#include <vector>
#include <cmath>

CuboColocado :: CuboColocado(std::vector<Matriz4f *>& traslacion){
	traslacion.push_back(leerPtrMatriz(agregar(MAT_Traslacion(0,0,0))));
	agregar(MAT_Traslacion(-1.0,0.0,1.0));
	agregar(new Cubo());
}

TiraCubos :: TiraCubos(int n){
		nCubos = n;
		for(int i = 0; i < n; i++){
			agregar( new CuboColocado(traslaciones) );
			agregar( MAT_Traslacion(2.0,0.0,0.0) );
		}
	
}


unsigned TiraCubos::leerNumParametros() const{
	return 1;
}

void TiraCubos :: fijarTraslacion(const float k){
		for(int i = 0; i<nCubos; i++){
			*(traslaciones[i]) = MAT_Traslacion(0, 0,k);
		}
}

void TiraCubos::actualizarEstadoParametro(const unsigned iParam, const float t_sec ){
		assert(iParam<leerNumParametros());
		switch(iParam){
			case 0:
				float a = 0;
				float b = 1;
				fijarTraslacion(a + b*sin(0.5*M_PI*t_sec));
		}
}
