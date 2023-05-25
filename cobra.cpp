#include "Cobra.h"
#include <conio.h>
#include <cstdlib>
#include <algorithm>


Cobra::Cobra(int x, int y, Mapa& mapa) : x(x), y(y), mapa(mapa){
    // Construtor da cobra
}

bool verificarColisao(const std::vector<std::pair<int, int>>& corpo, int x, int y) {
    return std::find_if(corpo.begin(), corpo.end(), [&](const auto& pos) {
        return pos.first == x && pos.second == y;
    }) != corpo.end();
}

void Cobra::mover(int largura, int altura) {
    bool gameover = false;

    while (!gameover) {
        // Limpar a tela
        system("cls");

        // Exibir o mapa e a posição atual da cobra
        mapa.desenhar();
        mapa.atualizarPosicaoCobra(x, y);

        // Ler a tecla pressionada
        char tecla = getch();

        // Atualizar a posição da cobra com base na tecla pressionada
        switch (tecla) {
            case 'w': // Tecla W - mover para cima
                y--;
                break;
            case 's': // Tecla S - mover para baixo
                y++;
                break;
            case 'a': // Tecla A - mover para a esquerda
                x--;
                break;
            case 'd': // Tecla D - mover para a direita
                x++;
                break;
            case 27: // Tecla Esc - terminar o jogo
                gameover = true;
                break;
            default:
                break;
        }

        if (x < 0 || x >= largura || y < 0 || y >= altura || verificarColisao(corpo, x, y)) {
            gameover = true;
            break;
        }

        // Pequena pausa para controlar a velocidade do jogo
        // Você pode ajustar o valor aqui para alterar a velocidade
        // Sleep(100);
    }
}


// void Cobra::mover() {
//     while (true) {
//         // Limpar a tela
//         system("clear");

//         // Exibir o mapa e a posição atual da cobra
//         mapa.desenhar();
//         mapa.atualizarPosicaoCobra(x, y);

//         // Ler a tecla pressionada
//         char tecla = _getch();

//         // Atualizar a posição da cobra com base na tecla pressionada
//         switch (tecla) {
//             case 'w': // Tecla W - mover para cima
//                 y--;
//                 break;
//             case 's': // Tecla S - mover para baixo
//                 y++;
//                 break;
//             case 'a': // Tecla A - mover para a esquerda
//                 x--;
//                 break;
//             case 'd': // Tecla D - mover para a direita
//                 x++;
//                 break;
//             default:
//                 break;
//         }
//     }
// }
