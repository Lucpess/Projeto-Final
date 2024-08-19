#include "doctest.h"
#include "damas.hpp"
#include "tabuleiro.hpp"


// Teste da inicialização e movimentação do tabuleiro para o jogo de Damas
TEST_CASE("Teste - Inicialização do tabuleiro e movimentação em Damas") {
    Tabuleiro tabuleiro;
    tabuleiro.inicializaTabuleiro('D');

    // Verificar se o tabuleiro foi inicializado corretamente para o jogo de Damas
    CHECK(tabuleiro.verificaCasa(0, 0, "PRETO")); // Deve ter uma peça PRETA na linha 0
    CHECK(tabuleiro.verificaCasa(7, 7, "BRANCO")); // Deve ter uma peça BRANCA na linha 7
    CHECK(tabuleiro.verificaCasa(3, 3, "NULO")); // Centro do tabuleiro deve estar vazio (NULO)

    // Teste de movimentação
    tabuleiro.modificaTabuleiro(5, 0, "NULO"); // Remove uma peça BRANCA
    tabuleiro.modificaTabuleiro(4, 1, "BRANCO"); // Movimenta a peça BRANCA para uma nova posição

    CHECK(tabuleiro.verificaCasa(5, 0, "NULO")); // Verifica se a casa original está vazia
    CHECK(tabuleiro.verificaCasa(4, 1, "BRANCO")); // Verifica se a casa de destino está com a peça BRANCA
}

TEST_CASE("Teste - Inicialização do tabuleiro e movimentação em Damas (Valores Diferentes)") {
    Tabuleiro tabuleiro;
    tabuleiro.inicializaTabuleiro('D');

    // Verificar se o tabuleiro foi inicializado corretamente para o jogo de Damas em posições diferentes
    CHECK(tabuleiro.verificaCasa(0, 2, "PRETO")); // Deve ter uma peça PRETA na linha 0, coluna 2
    CHECK(tabuleiro.verificaCasa(7, 5, "BRANCO")); // Deve ter uma peça BRANCA na linha 7, coluna 5
    CHECK(tabuleiro.verificaCasa(4, 4, "NULO")); // Casa (4, 4) deve estar vazia (NULO)

    // Teste de movimentação
    tabuleiro.modificaTabuleiro(2, 1, "NULO"); // Remove uma peça PRETA
    tabuleiro.modificaTabuleiro(3, 2, "PRETO"); // Movimenta a peça PRETA para uma nova posição

    CHECK(tabuleiro.verificaCasa(2, 1, "NULO")); // Verifica se a casa original está vazia
    CHECK(tabuleiro.verificaCasa(3, 2, "PRETO")); // Verifica se a casa de destino está com a peça PRETA
}