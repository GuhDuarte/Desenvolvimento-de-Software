#include "jogo.h"
#include <iostream>
#include <vector>

Mapa::Mapa(int largura, int altura) : largura(largura), altura(altura) {
    // Inicializar o mapa vazio
    for (int y = 0; y < altura; ++y) {
        std::vector<char> row;
        for (int x = 0; x < largura; ++x) {
            if (y == 0 || y == altura - 1 || x == 0 || x == largura - 1) {
                // Adicionar paredes ao redor do mapa
                row.push_back('#');
            } else {
                // Adicionar células vazias dentro do mapa
                row.push_back(' ');
            }
        }
        cells.push_back(row);
    }
}

void Mapa::desenhar() {
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

void Mapa::atualizarPosicaoCobra(int x, int y) {
    if (x >= 0 && x < largura && y >= 0 && y < altura) {
        cells[y][x] = '*';
    }
}