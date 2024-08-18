#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tabuleiro.hpp"
#include <sstream>

// Testa a inicialização do tabuleiro para o jogo Reversi
TEST_CASE("Testa inicializaTabuleiro para o jogo Reversi") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('R');

    // Verifica o estado das casas
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i == 3 && j == 3) || (i == 4 && j == 4)) {
                CHECK(tab.verificaCasa(i, j, "BRANCO"));
            } else if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
                CHECK(tab.verificaCasa(i, j, "PRETO"));
            } else {
                CHECK(tab.verificaCasa(i, j, "NULO"));
            }
        }
    }
}

// Testa a inicialização do tabuleiro para o jogo Lig4
TEST_CASE("Testa inicializaTabuleiro para o jogo Lig4") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('L');

    // Verifica o estado das casas
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            CHECK(tab.verificaCasa(i, j, "NULO"));
        }
    }
}

// Testa a impressão do tabuleiro para o jogo Reversi
TEST_CASE("Testa imprimeTabuleiro para o jogo Reversi") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('R');

    // Captura a saída do std::cout
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf()); // Redireciona std::cout para o buffer

    // Chama o método que imprime o tabuleiro
    tab.imprimeTabuleiro();

    // Restaura std::cout
    std::cout.rdbuf(oldCout);

    // Define a saída esperada
    std::string expectedOutput =
        "| | | |O|X| | | |\n"
        "| | | |X|O| | | |\n"
        "| | | | | | | | |\n"
        "| | | | | | | | |\n"
        "| | | | | | | | |\n"
        "| | | | | | | | |\n"
        "| | | | | | | | |\n"
        "| | | | | | | | |\n";

    // Verifica se a saída gerada corresponde à esperada
    CHECK(buffer.str() == expectedOutput);
}

// Testa a impressão do tabuleiro para o jogo Lig4
TEST_CASE("Testa imprimeTabuleiro para o jogo Lig4") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('L');

    // Captura a saída do std::cout
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf()); // Redireciona std::cout para o buffer

    // Chama o método que imprime o tabuleiro
    tab.imprimeTabuleiro();

    // Restaura std::cout
    std::cout.rdbuf(oldCout);

    // Define a saída esperada
    std::string expectedOutput =
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n"
        "| | | | | | | |\n";

    // Verifica se a saída gerada corresponde à esperada
    CHECK(buffer.str() == expectedOutput);
}
// Testa o método verificaCasa após a inicialização do tabuleiro para o jogo Reversi
TEST_CASE("Testa verificaCasa para o jogo Reversi") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('R');

    // Verifica o estado das casas específicas
    CHECK(tab.verificaCasa(3, 3, "BRANCO"));
    CHECK(tab.verificaCasa(3, 4, "PRETO"));
    CHECK(tab.verificaCasa(4, 3, "PRETO"));
    CHECK(tab.verificaCasa(4, 4, "BRANCO"));

    // Verifica que casas que não devem ter o estado especificado retornam false
    CHECK_FALSE(tab.verificaCasa(0, 0, "BRANCO"));
    CHECK_FALSE(tab.verificaCasa(0, 0, "PRETO"));
    CHECK_FALSE(tab.verificaCasa(3, 3, "NULO"));
}

// Testa o método verificaCasa após a inicialização do tabuleiro para o jogo Lig4
TEST_CASE("Testa verificaCasa para o jogo Lig4") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('L');

    // Verifica o estado das casas para Lig4 (deve ser "NULO")
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            CHECK(tab.verificaCasa(i, j, "NULO"));
        }
    }

    // Verifica que casas fora do intervalo retornam false
    CHECK_FALSE(tab.verificaCasa(6, 7, "NULO"));
    CHECK_FALSE(tab.verificaCasa(5, 6, "PRETO"));
}
// Testa o método modificaTabuleiro para o jogo Reversi
TEST_CASE("Testa modificaTabuleiro para o jogo Reversi") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('R');

    // Verifica o estado inicial de uma casa específica
    CHECK(tab.verificaCasa(3, 3, "BRANCO"));
    CHECK(tab.verificaCasa(3, 4, "PRETO"));
    CHECK(tab.verificaCasa(4, 3, "PRETO"));
    CHECK(tab.verificaCasa(4, 4, "BRANCO"));

    // Modifica o estado de algumas casas
    tab.modificaTabuleiro(3, 3, "NULO");
    tab.modificaTabuleiro(3, 4, "BRANCO");
    tab.modificaTabuleiro(4, 3, "BRANCO");
    tab.modificaTabuleiro(4, 4, "PRETO");

    // Verifica se o estado foi alterado corretamente
    CHECK(tab.verificaCasa(3, 3, "NULO"));
    CHECK(tab.verificaCasa(3, 4, "BRANCO"));
    CHECK(tab.verificaCasa(4, 3, "BRANCO"));
    CHECK(tab.verificaCasa(4, 4, "PRETO"));

    // Verifica que casas não modificadas ainda têm o estado correto
    CHECK(tab.verificaCasa(0, 0, "NULO"));
}

// Testa o método modificaTabuleiro para o jogo Lig4
TEST_CASE("Testa modificaTabuleiro para o jogo Lig4") {
    Tabuleiro tab;
    tab.inicializaTabuleiro('L');

    // Verifica o estado inicial de todas as casas (deve ser "NULO")
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            CHECK(tab.verificaCasa(i, j, "NULO"));
        }
    }

    // Modifica o estado de algumas casas
    tab.modificaTabuleiro(0, 0, "BRANCO");
    tab.modificaTabuleiro(1, 1, "PRETO");

    // Verifica se o estado foi alterado corretamente
    CHECK(tab.verificaCasa(0, 0, "BRANCO"));
    CHECK(tab.verificaCasa(1, 1, "PRETO"));

    // Verifica que casas não modificadas ainda têm o estado correto
    CHECK(tab.verificaCasa(2, 2, "NULO"));
}

