#ifndef COBRA_H
#define COBRA_H

#include "jogo.h"

class Cobra {
public:
    Cobra(int x, int y, Mapa& mapa);
    void mover(int largura, int altura);

private:
    int x;
    int y;
    Mapa& mapa;
};

#endif
