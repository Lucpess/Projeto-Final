#include "doctest.h"
#include "jogador.hpp"
#include <sstream> // Necessário para std::stringstream

// Testa o construtor padrão e os métodos getter
TEST_CASE("Testa Jogador - Construtor padrão e getters") {
    Jogador jogador;

    // Verifica se os valores iniciais estão corretos
    CHECK(jogador.getApelido() == "");
    CHECK(jogador.getNome() == "");
    CHECK(jogador.getVitoriasReversi() == 0);
    CHECK(jogador.getDerrotasReversi() == 0);
    CHECK(jogador.getVitoriasLig4() == 0);
    CHECK(jogador.getDerrotasLig4() == 0);
}

// Testa o construtor parametrizado e os métodos getter
TEST_CASE("Testa Jogador - Construtor parametrizado e getters") {
    Jogador jogador("apelido", "nome", 5, 3, 7, 2);

    // Verifica se os valores estão corretos após a inicialização com o construtor parametrizado
    CHECK(jogador.getApelido() == "apelido");
    CHECK(jogador.getNome() == "nome");
    CHECK(jogador.getVitoriasReversi() == 5);
    CHECK(jogador.getDerrotasReversi() == 3);
    CHECK(jogador.getVitoriasLig4() == 7);
    CHECK(jogador.getDerrotasLig4() == 2);
}

// Testa o método setApelido
TEST_CASE("Testa Jogador - setApelido") {
    Jogador jogador;
    jogador.setApelido("novoApelido");

    // Verifica se o apelido foi alterado corretamente
    CHECK(jogador.getApelido() == "novoApelido");
}

// Testa os métodos addVitoria e addDerrota
TEST_CASE("Testa Jogador - Métodos addVitoria e addDerrota") {
    Jogador jogador;

    // Testa as vitórias e derrotas para Lig4
    jogador.addVitoriaLig4();
    jogador.addVitoriaLig4();
    jogador.addDerrotaLig4();
    
    CHECK(jogador.getVitoriasLig4() == 2);
    CHECK(jogador.getDerrotasLig4() == 1);

    // Testa as vitórias e derrotas para Reversi
    jogador.addVitoriaReversi();
    jogador.addDerrotaReversi();
    jogador.addDerrotaReversi();
    
    CHECK(jogador.getVitoriasReversi() == 1);
    CHECK(jogador.getDerrotasReversi() == 2);
}

// Testa o método printResultados
TEST_CASE("Testa Jogador - printResultados") {
    Jogador jogador("apelido", "nome", 1, 2, 3, 4);

    // Captura a saída do std::cout
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf()); // Redireciona std::cout para o buffer

    // Chama o método que imprime os resultados
    jogador.printResultados();

    // Restaura std::cout
    std::cout.rdbuf(oldCout);

    // Define a saída esperada
    std::string expectedOutput =
        "apelido nome\n"
        "REVERSI - V: 1 D: 2\n"
        "LIG4    - V: 3 D: 4\n";

    // Verifica se a saída gerada corresponde à esperada
    CHECK(buffer.str() == expectedOutput);
}