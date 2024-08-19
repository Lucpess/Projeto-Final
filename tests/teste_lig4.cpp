#include "doctest.h"
#include "tabuleiro.hpp"
#include "lig4.hpp"
#include "cadastro.hpp"

// Testa a inicialização do tabuleiro para o jogo Lig4
TEST_CASE("Testa inicializaTabuleiro para o jogo Lig4") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('L');

    // Verifica que todas as casas estão inicializadas como "NULO"
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            CHECK(tab.verificaCasa(i, j, "NULO"));
        }
    }
}

// Testa a modificação de algumas casas no tabuleiro para o jogo Lig4
TEST_CASE("Testa modificaTabuleiro para o jogo Lig4") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('L');

    // Modifica o estado de algumas casas
    tab.modificaTabuleiro(0, 0, "BRANCO");
    tab.modificaTabuleiro(1, 1, "PRETO");
    
    // Verifica se o estado das casas foi alterado corretamente
    CHECK(tab.verificaCasa(0, 0, "BRANCO"));
    CHECK(tab.verificaCasa(1, 1, "PRETO"));

    // Verifica que casas que não foram modificadas ainda têm o estado correto
    CHECK(tab.verificaCasa(2, 2, "NULO"));
}

TEST_CASE("Testa modificaTabuleiro para o jogo Lig4") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('L');

    // Modifica o estado de algumas casas
    tab.modificaTabuleiro(0, 0, "BRANCO");
    tab.modificaTabuleiro(1, 1, "PRETO");
    
    // Verifica se o estado das casas foi alterado corretamente
    CHECK(tab.verificaCasa(0, 0, "BRANCO"));
    CHECK(tab.verificaCasa(1, 1, "PRETO"));

    // Verifica que casas que não foram modificadas ainda têm o estado correto
    CHECK(tab.verificaCasa(2, 2, "NULO"));
}

TEST_CASE("Teste verifica 4 inicial"){
    Lig4 jogo;

    for(int i = 0; i<6; i++){
        for(int j = 0; j<7; j++){
            CHECK(!jogo.verifica4(i, j));
        }
    }
}

TEST_CASE("Teste verifica 4 vertical"){
    Lig4 jogo;

    jogo.novaJogada(0);
    jogo.novaJogada(0);
    jogo.novaJogada(0);
    jogo.novaJogada(0);

    CHECK(jogo.verifica4(5,0));
    CHECK(jogo.verifica4(4,0));
    CHECK(jogo.verifica4(3,0));
    CHECK(jogo.verifica4(2,0));

    for(int i = 0; i<5; i++){
        for(int j = 1; j<7; j++){
            CHECK(!jogo.verifica4(i, j));
        }
    }
}

TEST_CASE("Teste verifica 4 horizontal"){
    Lig4 jogo;

    jogo.novaJogada(0);
    jogo.novaJogada(1);
    jogo.novaJogada(2);
    jogo.novaJogada(3);

    CHECK(jogo.verifica4(5,0));
    CHECK(jogo.verifica4(5,1));
    CHECK(jogo.verifica4(5,2));
    CHECK(jogo.verifica4(5,3));

    for(int i = 0; i<5; i++){
        for(int j = 0; j<7; j++){
            CHECK(!jogo.verifica4(i, j));
        }
    }
}

TEST_CASE("Teste verifica 4 diagonal"){
    Lig4 jogo;

    jogo.novaJogada(0);
    jogo.novaJogada(1);
    jogo.novaJogada(1);
    jogo.novaJogada(2);
    jogo.novaJogada(2);
    jogo.novaJogada(2);
    jogo.novaJogada(3);
    jogo.novaJogada(3);
    jogo.novaJogada(3);
    jogo.novaJogada(3);

    CHECK(jogo.verifica4(4,1));
    CHECK(jogo.verifica4(3,2));
    CHECK(!jogo.verifica4(4,2));
}
