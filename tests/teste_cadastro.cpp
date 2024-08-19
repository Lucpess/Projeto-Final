#include "cadastro.hpp"
#include "doctest.h"
#include <stdexcept>
#include <fstream>

// Função auxiliar para limpar o arquivo de cadastro antes dos testes
void limparArquivoCadastro() {
    std::ofstream arquivo("cadastro_jogadores.txt", std::ios::trunc);
    arquivo.close();
}

TEST_CASE("Testes da classe Cadastro") {
    limparArquivoCadastro(); // Garante que o arquivo esteja vazio antes de cada teste

    Cadastro cadastro;

    SUBCASE("Testa cadastro de jogador") {
        cadastro.cadastraJogador("apelido1", "Nome Um");
        CHECK(cadastro.existeJogador("apelido1") == true);
        CHECK_THROWS_AS(cadastro.cadastraJogador("apelido1", "Nome Um"), std::runtime_error);
    }

    SUBCASE("Testa remoção de jogador") {
        cadastro.cadastraJogador("apelido2", "Nome Dois");
        CHECK(cadastro.existeJogador("apelido2") == true);

        cadastro.removeJogador("apelido2");
        CHECK(cadastro.existeJogador("apelido2") == false);

        CHECK_THROWS_AS(cadastro.removeJogador("apelido2"), std::runtime_error);
    }

    SUBCASE("Testa registro de resultado") {
        cadastro.cadastraJogador("apelido3", "Nome Três");
        cadastro.cadastraJogador("apelido4", "Nome Quatro");

        CHECK_THROWS_AS(cadastro.registrarResultado("apelido3", "inexistente", 'R'), std::runtime_error);
        CHECK_NOTHROW(cadastro.registrarResultado("apelido3", "apelido4", 'R'));
        CHECK_NOTHROW(cadastro.registrarResultado("apelido4", "apelido3", 'L'));
    }

    SUBCASE("Testa lista de jogadores ordenados") {
        cadastro.cadastraJogador("apelido5", "Carlos");
        cadastro.cadastraJogador("apelido6", "Ana");

        CHECK_NOTHROW(cadastro.listaJogadores("N"));
        CHECK_NOTHROW(cadastro.listaJogadores("A"));
        CHECK_THROWS_AS(cadastro.listaJogadores("X"), std::runtime_error);
    }
}