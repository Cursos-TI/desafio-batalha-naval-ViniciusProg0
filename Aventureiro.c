#include <stdio.h>

int main() {
    // ------------------------------------------
    // 1️⃣ Criar o tabuleiro 10x10
    // ------------------------------------------
    int tabuleiro[10][10];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ------------------------------------------
    // 2️⃣ Definir os navios (tamanho fixo = 3)
    // ------------------------------------------
    int navio[3] = {3, 3, 3};

    // ------------------------------------------
    // 3️⃣ Definir coordenadas iniciais dos 4 navios
    // ------------------------------------------
    // (esses valores foram escolhidos manualmente dentro dos limites 10x10)
    int linha_h1 = 2, coluna_h1 = 1; // navio horizontal 1
    int linha_v1 = 6, coluna_v1 = 8; // navio vertical 1

    int linha_d1 = 1, coluna_d1 = 1; // diagonal descendo ↘️
    int linha_d2 = 5, coluna_d2 = 7; // diagonal subindo ↗️

    // ------------------------------------------
    // 4️⃣ Posicionar navio horizontal
    // ------------------------------------------
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_h1][coluna_h1 + i] = navio[i];
    }

    // ------------------------------------------
    // 5️⃣ Posicionar navio vertical
    // ------------------------------------------
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_v1 + i][coluna_v1] = navio[i];
    }

    // ------------------------------------------
    // 6️⃣ Posicionar navio diagonal descendente ↘️
    // Linha e coluna aumentam juntas (ex: (1,1), (2,2), (3,3))
    // ------------------------------------------
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = navio[i];
    }

    // ------------------------------------------
    // 7️⃣ Posicionar navio diagonal ascendente ↗️
    // Linha aumenta, coluna diminui (ex: (5,7), (6,6), (7,5))
    // ------------------------------------------
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_d2 + i][coluna_d2 - i] = navio[i];
    }

    // ------------------------------------------
    // 8️⃣ Exibir o tabuleiro
    // ------------------------------------------
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    for (int i = 0; i < 10; i++) {       // percorre as linhas
        for (int j = 0; j < 10; j++) {   // percorre as colunas
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // quebra de linha
    }

    return 0;
}
