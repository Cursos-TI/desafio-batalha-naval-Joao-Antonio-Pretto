
#include <stdio.h>
#include <stdbool.h>

// Constantes para o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Representação dos elementos no tabuleiro
#define AGUA 0
#define NAVIO 3


void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}


void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Cabeçalho das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Cabeçalho das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


bool validarPosicionamento(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        // Verifica se o navio horizontal excede os limites do tabuleiro
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return false;
        }
        // Verifica sobreposição para navio horizontal
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[linha][coluna + j] == NAVIO) {
                return false;
            }
        }
    } else if (orientacao == 'V') {
        // Verifica se o navio vertical excede os limites do tabuleiro
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return false;
        }
        // Verifica sobreposição para navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                return false;
            }
        }
    } else {
        // Orientação inválida
        return false;
    }
    return true;
}


bool posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (!validarPosicionamento(tabuleiro, linha, coluna, orientacao)) {
        printf("Erro: Nao foi possivel posicionar o navio em (%d, %d) com orientacao %c. Verifique limites ou sobreposicao.\n", linha, coluna, orientacao);
        return false;
    }

    if (orientacao == 'H') {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[linha][coluna + j] = NAVIO;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    printf("Navio posicionado com sucesso em (%d, %d) com orientacao %c.\n", linha, coluna, orientacao);
    return true;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    printf("--- Batalha Naval - Nivel Novato ---\n\n");

    // Posicionamento do primeiro navio (horizontal)
    // Coordenadas iniciais: linha 2, coluna 3
    posicionarNavio(tabuleiro, 2, 3, 'H');

    // Posicionamento do segundo navio (vertical)
    // Coordenadas iniciais: linha 5, coluna 6
    posicionarNavio(tabuleiro, 5, 6, 'V');

    printf("\n--- Tabuleiro Atual ---\n");
    exibirTabuleiro(tabuleiro);

    // Teste de posicionamento inválido (fora dos limites)
    printf("\n--- Teste de Posicionamento Invalido (fora dos limites) ---\n");
    posicionarNavio(tabuleiro, 9, 8, 'H'); // Navio horizontal que excede o limite
    posicionarNavio(tabuleiro, 8, 9, 'V'); // Navio vertical que excede o limite

    // Teste de posicionamento inválido (sobreposição)
    printf("\n--- Teste de Posicionamento Invalido (sobreposicao) ---\n");
    posicionarNavio(tabuleiro, 2, 4, 'H'); // Tenta sobrepor o primeiro navio

    printf("\n--- Tabuleiro Final ---\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}


