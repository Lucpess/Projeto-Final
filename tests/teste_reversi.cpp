#include "reversi.hpp"
#include "doctest.h"
#include <sstream>
#include <iostream>

TEST_CASE("Teste do construtor Reversi") {
    Reversi jogo;
    Cadastro cadastro;  // Objeto local para passar como referência
    CHECK_FALSE(jogo.verificaFimDeJogo("Jogador1", "Jogador2", cadastro));
}

TEST_CASE("Teste peça adversária") {
    Reversi jogo;
    // Supondo que o turno inicial seja "PRETO".
    CHECK(jogo.pecaAdversaria() == "BRANCO");
}

TEST_CASE("Teste posição permitida") {
    Reversi jogo;
    // Supondo que a posição (0, 0) seja permitida para o turno atual.
    CHECK(jogo.posicaoPermitida(0, 0, "PRETO") == true);
    CHECK(jogo.posicaoPermitida(1, 1, "BRANCO") == false);
}

TEST_CASE("Teste verificação de coluna") {
    Reversi jogo;
    // Supondo que a função de verificação de coluna esteja funcionando corretamente.
    CHECK(jogo.verificaColuna(3, 4, "PRETO") == true);
    CHECK(jogo.verificaColuna(5, 6, "BRANCO") == false);
}

