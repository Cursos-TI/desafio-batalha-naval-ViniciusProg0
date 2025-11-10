#include <stdio.h>

//constantes /
#define LIN 10
#define COL 10
#define HSIZE 5  //tamanho das matrizes de habilidade (5x5)*//

#define AGUA 0
#define NAVIO 3
#define AFETADO 5

int main() {
    // 1) Criar e inicializar tabuleiro 10x10 (tudo água = 0)
    int tabuleiro[LIN][COL];
    for (int r = 0; r < LIN; r++) {
        for (int c = 0; c < COL; c++) {
            tabuleiro[r][c] = AGUA;
        }
    }

    //2) Colocar alguns navios (valor 3) para visualização
    // Usado posicionamentos fixos, como no exercício anterior.
    // navio horizontal (linha 2, col 1..3) 
    tabuleiro[2][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;

    //navio vertical (coluna 8, linha 6..8)
    tabuleiro[6][8] = NAVIO;
    tabuleiro[7][8] = NAVIO;
    tabuleiro[8][8] = NAVIO;

    //navio diagonal descendente (1,1),(2,2),(3,3) 
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO; //note: sobrescreve mesma célula já navio horizontal se existir
    tabuleiro[3][3] = NAVIO;

    //navio diagonal ascendente (5,7),(6,6),(7,5)
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][5] = NAVIO;

    //3) Criar as matrizes de habilidade 5x5 (valores 0/1)
       //cone, cruz e octaedro (losango)
       //Todas preenchidas dinamicamente com loops aninhados e condicionais
    int cone[HSIZE][HSIZE];
    int cruz[HSIZE][HSIZE];
    int octaedro[HSIZE][HSIZE];

    //inicializa tudo com 0
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    //Construir CONE apontando para baixo 
       //ideia: topo (linha 0) tem um 1 no centro; a cada linha r abaixo
      // o "raio" aumenta: marca coluna j se j está entre (center - r) e (center + r).
      // center = 2 para HSIZE=5
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            int center = HSIZE / 2; /* =2 */
            //ondição simples sem abs(): j >= center - r && j <= center + r/
            if (c >= (center - r) && c <= (center + r)) {
                cone[r][c] = 1;
            } else {
                cone[r][c] = 0;
            }
        }
    }

    //Construir CRUZ (mais simples)
       //regra: célula = 1 se linha == center ou coluna == center
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            int center = HSIZE / 2;
            if (r == center || c == center) {
                cruz[r][c] = 1;
            } else {
                cruz[r][c] = 0;
            }
        }
    }

    //Construir OCTAEDRO/LOSANGO (vista frontal) ---
       //regra (sem abs): marcado se |r-center| + |c-center| <= radius
       //calculamos |x| manualmente com ifs (evita uso de abs)
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            int center = HSIZE / 2; // 2 //
            int radius = center;    //2 //
            int dr = r - center;
            if (dr < 0) dr = -dr;   // dr = |r-center| //
            int dc = c - center;
            if (dc < 0) dc = -dc;   // dc = |c-center| //
            if ((dr + dc) <= radius) {
                octaedro[r][c] = 1;
            } else {
                octaedro[r][c] = 0;
            }
        }
    }

    //4) Definir pontos de origem (centro) no tabuleiro para cada habilidade
       //Essas são coordenadas fixas (pode alterar conforme quiser)
       //Lembre-se: ao sobrepor, a célula (2,2) da matriz de habilidade é o centro.
    int orgConeLinha = 1, orgConeColuna = 3;  //exemplo: cone perto do topo/
    int orgCruzLinha = 5, orgCruzColuna = 5;  //cruz no centro/
    int orgOctLinha  = 8, orgOctColuna  = 2;  //octaedro perto da base-esquerda/

    ///5) Sobrepor as matrizes no tabuleiro (centro = índice 2,2 da matriz 5x5)
       //Marcar apenas onde havia AGUA (0) — não sobrescrever NAVIO (3)
       //Usa loops aninhados e condicionais
    int center = HSIZE / 2; /* 2 */

    // Sobrepor CONE //
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            if (cone[r][c] == 1) { //só processa células ativas/
                int boardR = orgConeLinha + (r - center);
                int boardC = orgConeColuna + (c - center);
                //verificar limites do tabuleiro/
                if (boardR >= 0 && boardR < LIN && boardC >= 0 && boardC < COL) {
                    if (tabuleiro[boardR][boardC] == AGUA) { //só marca água/
                        tabuleiro[boardR][boardC] = AFETADO;
                    }
                }
            }
        }
    }

    //Sobrepor CRUZ/
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            if (cruz[r][c] == 1) {
                int boardR = orgCruzLinha + (r - center);
                int boardC = orgCruzColuna + (c - center);
                if (boardR >= 0 && boardR < LIN && boardC >= 0 && boardC < COL) {
                    if (tabuleiro[boardR][boardC] == AGUA) {
                        tabuleiro[boardR][boardC] = AFETADO;
                    }
                }
            }
        }
    }

    //Sobrepor OCTAEDRO (losango)/
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            if (octaedro[r][c] == 1) {
                int boardR = orgOctLinha + (r - center);
                int boardC = orgOctColuna + (c - center);
                if (boardR >= 0 && boardR < LIN && boardC >= 0 && boardC < COL) {
                    if (tabuleiro[boardR][boardC] == AGUA) {
                        tabuleiro[boardR][boardC] = AFETADO;
                    }
                }
            }
        }
    }

    //6) Exibir as matrizes de habilidade (opcional, para visualização)
       //Mostra 1 onde afeta e 0 onde não
    printf("MATRIZ - CONE (1 = afetado):\n");
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            printf("%d ", cone[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    printf("MATRIZ - CRUZ (1 = afetado):\n");
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            printf("%d ", cruz[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    printf("MATRIZ - OCTAEDRO/LOSANGO (1 = afetado):\n");
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            printf("%d ", octaedro[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    //7) Exibir o tabuleiro final: 0 = água, 3 = navio, 5 = área afetada
    printf("=== TABULEIRO FINAL (0=Agua, 3=Navio, 5=Area Afetada) ===\n");
    for (int r = 0; r < LIN; r++) {
        for (int c = 0; c < COL; c++) {
            printf("%d ", tabuleiro[r][c]);
        }
        printf("\n");
    }

    return 0;
}