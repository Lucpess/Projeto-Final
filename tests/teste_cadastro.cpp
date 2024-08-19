#include "cadastro.hpp"
#include "doctest.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>

// Função auxiliar para limpar o arquivo de cadastro antes dos testes
static void limparArquivoCadastro() {
    std::ofstream arquivo("cadastro_jogadores.txt", std::ios::trunc);
    arquivo.close();
}

TEST_CASE("Testes da classe Cadastro") {
    limparArquivoCadastro(); // Garante que o arquivo esteja vazio antes de cada teste

    Cadastro cadastro;

    SUBCASE("Testa cadastro de jogador") {
        // Suprime cout
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        cadastro.cadastraJogador("apelido1", "Nome Um");

        // Restaura cout
        std::cout.rdbuf(oldCout);
        
        CHECK(cadastro.existeJogador("apelido1") == true);
    }

    SUBCASE("Testa remoção de jogador") {
        // Suprime cout
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        cadastro.cadastraJogador("apelido2", "Nome Dois");
        CHECK(cadastro.existeJogador("apelido2") == true);

        cadastro.removeJogador("apelido2");
        
        // Restaura cout
        std::cout.rdbuf(oldCout);

        CHECK(cadastro.existeJogador("apelido2") == false);
    }

    SUBCASE("Testa registro de resultado") {
        // Suprime cout
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        cadastro.cadastraJogador("apelido3", "Nome Três");
        cadastro.cadastraJogador("apelido4", "Nome Quatro");

        cadastro.registrarResultado("apelido3", "apelido4", 'R');
        CHECK(cadastro.existeJogador("apelido3") == true);
        CHECK(cadastro.existeJogador("apelido4") == true);

        cadastro.registrarResultado("apelido4", "apelido3", 'L');

        // Restaura cout
        std::cout.rdbuf(oldCout);

        CHECK(cadastro.existeJogador("apelido3") == true);
        CHECK(cadastro.existeJogador("apelido4") == true);
    }

    SUBCASE("Testa lista de jogadores ordenados") {
        // Suprime cout
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        cadastro.cadastraJogador("apelido5", "Carlos");
        cadastro.cadastraJogador("apelido6", "Ana");

        CHECK_NOTHROW(cadastro.listaJogadores("N"));
        CHECK_NOTHROW(cadastro.listaJogadores("A"));

        cadastro.removeJogador("apelido5");
        cadastro.removeJogador("apelido6");

        // Restaura cout
        std::cout.rdbuf(oldCout);
    }
}
