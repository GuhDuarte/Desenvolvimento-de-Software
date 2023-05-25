#ifndef JOGO_H
#define JOGO_H

#include <vector>

class Mapa {
public:
    Mapa(int largura, int altura);
    void desenhar();
    void atualizarPosicaoCobra(int x, int y);

private:
    int largura;
    int altura;
    std::vector<std::vector<char>> cells;
};


#endif
