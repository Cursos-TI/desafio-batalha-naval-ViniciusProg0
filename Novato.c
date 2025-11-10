#include <stdio.h>

// Definicao do tamanho fixo do tabuleiro
#define TAMANHO 10 
// Definicao do tamanho fixo dos navios
#define TAMANHO_NAVIO 3 

void main() {
    
    // 1. Representar e Inicializar o Tabuleiro (Matriz 10x10)
    // 0 = Água
    // 3 = Parte do Navio
    int tabuleiro[TAMANHO][TAMANHO];
    int linha, coluna;

    // Inicializa todas as posicoes do tabuleiro com 0 (Água)
    for (linha = 0; linha < TAMANHO; linha++) {
        for (coluna = 0; coluna < TAMANHO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // 2. Posicionar os Navios (Posicionamento Fixo)

    // --- NAVIO 1: HORIZONTAL (tamanho 3) ---
    int linha_h = 5; // Posicao inicial: Linha 5
    int coluna_h = 2; // Posicao inicial: Coluna 2 (Navio vai de 2 ate 4)
    
    // Validação Simples: Garante que o navio cabe na horizontal (coluna + tamanho <= 10)
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO) {
        // Loop para posicionar as 3 partes do navio (colunas 2, 3 e 4)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_h][coluna_h + i] = 3;
        }
    }

    // --- NAVIO 2: VERTICAL (tamanho 3) ---
    int linha_v = 1; // Posicao inicial: Linha 1 (Navio vai de 1 ate 3)
    int coluna_v = 8; // Posicao inicial: Coluna 8
    
    // Validação Simples: Garante que o navio cabe na vertical (linha + tamanho <= 10)
    if (linha_v + TAMANHO_NAVIO <= TAMANHO) {
        // Loop para posicionar as 3 partes do navio (linhas 1, 2 e 3)
        // NOTA: Esta posicao (1,8) nao se sobrepoe ao Navio 1 (5, 2-4)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_v + i][coluna_v] = 3;
        }
    }


    // 3. Exibir o Tabuleiro (Usando loops aninhados)
    printf("\n--- TABULEIRO DE BATALHA NAVAL (10x10) ---\n");
    printf("0 = Agua, 3 = Navio\n\n");
    
    // Imprime o cabecalho das Colunas (0 a 9)
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    printf("  ---------------------\n");
    
    // Loops aninhados para percorrer e imprimir a matriz
    for (linha = 0; linha < TAMANHO; linha++) {
        
        // Imprime o numero da Linha
        printf("%d |", linha); 
        
        for (coluna = 0; coluna < TAMANHO; coluna++) {
            // Imprime o valor da posicao atual (0 ou 3) seguido de um espaco
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n"); // Quebra de linha apos cada linha do tabuleiro
    }
    printf("---------------------------------------\n");
}