#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void desenharMapa(int x, int y, const std::vector<std::pair<int, int>>& corpo, const std::pair<int, int>& comida, int pontuacao) {
    // Exibir a pontuação acima do mapa
    std::cout << "Pontuação: " << pontuacao << std::endl;

    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if (i == y && j == x) {
                std::cout << '*'; // Cabeça da cobra
            } else if (std::find_if(corpo.begin(), corpo.end(), [&](const auto& pos) {
                return pos.first == j && pos.second == i;
            }) != corpo.end()) {
                std::cout << '*'; // Corpo da cobra
            } else if (j == comida.first && i == comida.second) {
                std::cout << '@'; // Comida
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

bool verificarColisao(const std::vector<std::pair<int, int>>& corpo, int x, int y) {
    return std::find_if(corpo.begin(), corpo.end(), [&](const auto& pos) {
        return pos.first == x && pos.second == y;
    }) != corpo.end();
}

int main() {
    bool gameover = false;
    std::string nome;
    int x = MAP_WIDTH / 2;
    int y = MAP_HEIGHT / 2;
    std::vector<std::pair<int, int>> corpo;
    std::pair<int, int> comida;
    int pontuacao = 0;

    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> randomX(0, MAP_WIDTH - 1);
    std::uniform_int_distribution<int> randomY(0, MAP_HEIGHT - 1);

    std::cout << "Digite seu nome: ";
    std::getline(std::cin, nome);

    std::ofstream arquivo("pontuacao.txt");

    while (!gameover) {
        limparTela();
        desenharMapa(x, y, corpo, comida, pontuacao);

        char tecla = getch();

        switch (tecla) {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 27:
                gameover = true;
                break;
            default:
                break;
        }

        if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT || verificarColisao(corpo, x, y)) {
            gameover = true;
            break;
        }

        corpo.push_back(std::make_pair(x, y));

        if (x == comida.first && y == comida.second) {
            pontuacao++;
            comida.first = randomX(rng);
            comida.second = randomY(rng);
        } else {
            corpo.erase(corpo.begin());
        }
    }
    arquivo << nome << ": " << pontuacao << std::endl;
    arquivo.close(); // Fecha o arquivo
    return 0;
}
