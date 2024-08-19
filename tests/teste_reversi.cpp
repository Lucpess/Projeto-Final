#include "reversi.hpp"
#include "doctest.h"
#include <sstream>
#include <iostream>

TEST_CASE("Teste do construtor Reversi") {
    Reversi jogo;
    Cadastro cadastro;
    CHECK_FALSE(jogo.verificaFimDeJogo("Jogador1", "Jogador2", cadastro));
}

TEST_CASE("Teste peça adversária") {
    Reversi jogo;
    
    CHECK(jogo.pecaAdversaria() == "BRANCO");
}

TEST_CASE("Teste posição permitida inicial") {
    Reversi jogo;
    
    CHECK(jogo.posicaoPermitida(0, 0, "PRETO") == false);
    CHECK(jogo.posicaoPermitida(1, 1, "BRANCO") == false);
    CHECK(jogo.posicaoPermitida(2, 3, "PRETO") == true);
    CHECK(jogo.posicaoPermitida(3, 2, "PRETO") == true);
}

TEST_CASE("Teste verificação de coluna inicial") {
    Reversi jogo;
    
    CHECK(jogo.verificaColuna(2, 3, "PRETO") == true);
    CHECK(jogo.verificaColuna(3, 2, "PRETO") == false);
    CHECK(jogo.verificaColuna(1, 1, "BRANCO") == false);

}

