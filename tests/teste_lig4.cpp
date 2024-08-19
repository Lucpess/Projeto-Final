#include "doctest.h"
#include "lig4.hpp"
#include "tabuleiro.hpp" // Inclua o arquivo apropriado
#include <sstream>
#include <iostream>

// Testa a construtora da classe Lig4
TEST_CASE("Testar construtora da classe Lig4") {
    CHECK_NOTHROW(Lig4 lig4);
}

// Testa a função printTabuleiro
TEST_CASE("Testar printTabuleiro") {
    Lig4 lig4;

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream outputStream;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputStream.rdbuf());

    lig4.printTabuleiro();

    std::string output = outputStream.str();
    // Aqui você deve verificar a saída para garantir que o tabuleiro foi impresso corretamente
    CHECK(output.find("Tabuleiro") != std::string::npos); // Ajuste o padrão conforme necessário

    std::cout.rdbuf(originalBuffer);
}

// Testa a função start
TEST_CASE("Testar start") {
    Lig4 lig4;
    Cadastro cadastro;

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream outputStream;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputStream.rdbuf());

    // Simula a entrada do usuário para as jogadas
    std::istringstream inputStream("1\n2\n3\n4\n5\n6\n7\n");
    std::streambuf* originalInputBuffer = std::cin.rdbuf();
    std::cin.rdbuf(inputStream.rdbuf());

    lig4.start("Jogador1", "Jogador2", cadastro);

    std::string output = outputStream.str();
    
    // Verifica as mensagens esperadas usando SUBCASE para evitar complexidade
    SUBCASE("Verificar turno de Jogador1") {
        CHECK(output.find("TURNO DE Jogador1") != std::string::npos);
    }
    
    SUBCASE("Verificar turno de Jogador2") {
        CHECK(output.find("TURNO DE Jogador2") != std::string::npos);
    }

    std::cin.rdbuf(originalInputBuffer);
    std::cout.rdbuf(originalBuffer);
}
