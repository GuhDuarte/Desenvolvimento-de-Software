#include <iostream>
#include <cstdlib>
#include "jogo.h"
#include "cobra.h"

int main() {
    printf("Bem-vindo ao jogo da Snake!\n");
    int mapa_largura, mapa_altura;

    printf("Digite a largura do mapa: ");
    std::cin >> mapa_largura;

    printf("Digite a altura do mapa: ");
    std::cin >> mapa_altura;


    int snake_x = mapa_largura / 2;
    int snake_y = mapa_altura / 2;

    Mapa mapa(mapa_largura, mapa_altura);
    Cobra cobra(snake_x, snake_y, mapa);
    mapa.desenhar();
    cobra.mover(mapa_largura, mapa_altura);

    return 0;
}
