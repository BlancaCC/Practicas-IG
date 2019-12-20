#ifndef LATAPEONES_H
#define LATAPEONES_H

#include "objeto3d.h"
#include "grafo-escena.h"

class Lata : public NodoGrafoEscena{
    public:
        Lata(const std::string & textura);

};

class TapaInferiorLata : public NodoGrafoEscena{
    public:
        TapaInferiorLata();
};

class TapaSuperiorLata : public NodoGrafoEscena{
    public:
        TapaSuperiorLata();
};

class CuerpoLata : public NodoGrafoEscena{
    public:
        CuerpoLata(const std::string & fichero);
};

class PeonMadera : public NodoGrafoEscena{
    public:
        PeonMadera();
};

class PeonBlanco : public NodoGrafoEscena{
    public:
        PeonBlanco();
};

class PeonNegro : public NodoGrafoEscena{
    public:
        PeonNegro();
};

class LataPeones: public NodoGrafoEscena{
    public:
        LataPeones();
};

class LataPepsi : public NodoGrafoEscena{
    public:
        LataPepsi();
};

class LataCocaCola : public NodoGrafoEscena{
    public:
        LataCocaCola();
};

class LataUGR : public NodoGrafoEscena{
    public:
        LataUGR();
};

class Latas : public NodoGrafoEscena{
    public:
        Latas();
};

class Peones : public NodoGrafoEscena{
    public:
        Peones();
};

class VariasLatasPeones : public NodoGrafoEscena{
    public:
        VariasLatasPeones();
};

#endif