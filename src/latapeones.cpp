#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include "latapeones.h"



Lata :: Lata(const std::string & textura){
    agregar(MAT_Escalado(4.0,4.0,4.0));
    agregar(new TapaInferiorLata() );
    agregar(new TapaSuperiorLata());
    agregar(new CuerpoLata(textura));

    ponerIdentificador(-1);
    ponerNombre("Lata");
}

TapaInferiorLata :: TapaInferiorLata(){
    agregar( new Material(0.1,0.6,0.3,20) );
    agregar( new MallaRevolPLY("../recursos/plys/lata-pinf.ply",50) );

    ponerIdentificador(-1);
    ponerNombre("Tapa Inferior Lata");
}

TapaSuperiorLata :: TapaSuperiorLata(){
    agregar( new Material(0.1,0.6,0.3,20) );
    agregar(new MallaRevolPLY("../recursos/plys/lata-psup.ply",50));

    ponerIdentificador(-1);
    ponerNombre("Tapa Superior Lata");
}

CuerpoLata :: CuerpoLata(const std::string & fichero){
    Textura * tex = new Textura(fichero);
    agregar( new Material(tex, 0.5,0.1,0.3,20) );
    agregar(new MallaRevolPLY("../recursos/plys/lata-pcue.ply",50));
    ponerIdentificador(-1);
    ponerNombre("Cuerpo de la lata");
}

PeonMadera :: PeonMadera(){
    Textura * tex = new Textura("../recursos/imgs/text-madera.jpg");
    agregar( MAT_Escalado(0.8, 0.8, 0.8) );
    agregar( MAT_Traslacion(0.0,1.35,0.0));
    agregar( new Material(tex, 0.2, 0.4, 0.4, 20) );
    agregar(new MallaRevolPLY("../recursos/plys/peon.ply",50));

    ponerNombre("Peon de Madera");
    ponerIdentificador(0xFF+1);
}

PeonBlanco :: PeonBlanco(){
    ponerColor({1.0,1.0,1.0});
    agregar( MAT_Escalado(0.8, 0.8, 0.8) );
    agregar( MAT_Traslacion(0.0,1.35,0.0));
    agregar( new Material(0.1, 0.8, 0.1, 15 ) );
    agregar(new MallaRevolPLY("../recursos/plys/peon.ply",50));

    ponerNombre("Peon Blanco");
    ponerIdentificador(0xFF00+1);
}

PeonNegro :: PeonNegro(){
    ponerColor({0.0,0.0,0.0});
    agregar( MAT_Escalado(0.8, 0.8, 0.8) );
    agregar( MAT_Traslacion(0.0,1.35,0.0));
    agregar( new Material(0.1, 0.1, 0.8, 20) );
    agregar(new MallaRevolPLY("../recursos/plys/peon.ply",50));

    ponerNombre("Peon Negro");
    ponerIdentificador(0xFF0000+1);
}

LataPeones :: LataPeones(){

    agregar(new Lata("../recursos/imgs/lata-pepsi.jpg"));
    agregar(MAT_Traslacion(0.0, 0.0, 3.0));
    agregar(new PeonNegro());
    agregar(MAT_Traslacion(2.0, 0.0, 0.0));
    agregar(new PeonBlanco());
    agregar(MAT_Traslacion(2.0, 0.0, 0.0));
    agregar(new PeonMadera());

    ponerNombre("Lata y Peones");
}

LataPepsi :: LataPepsi(){
    agregar(new Lata("../recursos/imgs/lata-pepsi.jpg"));

    ponerNombre("Lata de Pepsi");
    ponerIdentificador(0xFF);
}

LataCocaCola :: LataCocaCola(){
    agregar(new Lata("../recursos/imgs/lata-coke.jpg"));

    ponerNombre("Lata de Coca-Cola");
    ponerIdentificador(0xFF00);
}

LataUGR :: LataUGR(){
    agregar(new Lata("../recursos/imgs/window-icon.jpg"));

    ponerNombre("Lata de la UGR");
    ponerIdentificador(0xFF0000);
}

Latas :: Latas(){
    agregar(new LataPepsi());
    agregar(MAT_Traslacion(3.0,0.0,0.0));
    agregar(new LataCocaCola());
    agregar(MAT_Traslacion(3.0,0.0,0.0));
    agregar(new LataUGR());

    ponerIdentificador(0);
    ponerNombre("Latas");
}

Peones :: Peones(){
    agregar(new PeonMadera());
    agregar(MAT_Traslacion(2.0, 0.0, 0.0));
    agregar(new PeonBlanco());
    agregar(MAT_Traslacion(2.0, 0.0, 0.0));
    agregar(new PeonNegro());
    ponerIdentificador(0);

    ponerNombre("Peones");
}

VariasLatasPeones :: VariasLatasPeones(){
    agregar(new Latas());
    agregar(MAT_Traslacion(0.0,0.0,3.0));
    agregar(new Peones());

    ponerIdentificador(0);
    ponerNombre("Latas y Peones");
}