#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <string>
#include "cadastro.hpp"
#include "lig4.hpp"
#include "reversi.hpp"

// Declaração da função main
int main(); // Declaração necessária para que o teste possa compilar

// Função auxiliar para testar a função main com entrada simulada
void test_main(const std::string& input, const std::string& expectedOutput) {
    std::streambuf* origCin = std::cin.rdbuf();
    std::streambuf* origCout = std::cout.rdbuf();

    std::istringstream simulatedInput(input);
    std::ostringstream simulatedOutput;

    std::cin.rdbuf(simulatedInput.rdbuf());
    std::cout.rdbuf(simulatedOutput.rdbuf());

    // Captura o valor de retorno da função main
    int returnValue = main(); 

    std::cin.rdbuf(origCin);
    std::cout.rdbuf(origCout);

    CHECK(simulatedOutput.str() == expectedOutput);
}

// Test cases
TEST_CASE("Testando a função main") {
    SUBCASE("Cadastrar jogador") {
        std::string input = "CJ jogador1 Nome1\nFS\n";
        std::string expectedOutput = 
            "--BEM VINDO AOS JOGOS--\n"
            "--------------------------------------------------------------------\n"
            "O QUE VOCE DESEJA FAZER? PARA:\n"
            ".CADASTRAR JOGADOR: DIGITE ''CJ <Apelido> <Nome>''\n"
            ".REMOVER JOGADOR: DIGITE ''RJ <APELIDO>''\n"
            ".LISTAR JOGADORES: DIGITE ''LJ [A/N]''\n"
            ".EXECUTAR PARTIDA: DIGITE ''EP <JOGO: (R/L)> <Apelido1> <Apelido2>''\n"
            ".FINALIZAR SISTEMA: DIGITE ''FS''\n"
            "--------------------------------------------------------------------\n"
            "-> Comando invalido para cadastrar jogador!" // Ajuste conforme necessário
            "\nFinalizando o programa!\n";

        test_main(input, expectedOutput);
    }

    SUBCASE("Remover jogador") {
        std::string input = "RJ jogador1\nFS\n";
        std::string expectedOutput = 
            "--BEM VINDO AOS JOGOS--\n"
            "--------------------------------------------------------------------\n"
            "O QUE VOCE DESEJA FAZER? PARA:\n"
            ".CADASTRAR JOGADOR: DIGITE ''CJ <Apelido> <Nome>''\n"
            ".REMOVER JOGADOR: DIGITE ''RJ <APELIDO>''\n"
            ".LISTAR JOGADORES: DIGITE ''LJ [A/N]''\n"
            ".EXECUTAR PARTIDA: DIGITE ''EP <JOGO: (R/L)> <Apelido1> <Apelido2>''\n"
            ".FINALIZAR SISTEMA: DIGITE ''FS''\n"
            "--------------------------------------------------------------------\n"
            "-> Comando invalido para registrar jogador!"  // Ajuste a saída esperada conforme necessário
            "\nFinalizando o programa!\n";

        test_main(input, expectedOutput);
    }

    SUBCASE("Listar jogadores") {
        std::string input = "LJ A\nFS\n";
        std::string expectedOutput = 
            "--BEM VINDO AOS JOGOS--\n"
            "--------------------------------------------------------------------\n"
            "O QUE VOCE DESEJA FAZER? PARA:\n"
            ".CADASTRAR JOGADOR: DIGITE ''CJ <Apelido> <Nome>''\n"
            ".REMOVER JOGADOR: DIGITE ''RJ <APELIDO>''\n"
            ".LISTAR JOGADORES: DIGITE ''LJ [A/N]''\n"
            ".EXECUTAR PARTIDA: DIGITE ''EP <JOGO: (R/L)> <Apelido1> <Apelido2>''\n"
            ".FINALIZAR SISTEMA: DIGITE ''FS''\n"
            "--------------------------------------------------------------------\n"
            "-> Comando invalido para listar jogadores!"  // Ajuste a saída esperada conforme necessário
            "\nFinalizando o programa!\n";

        test_main(input, expectedOutput);
    }

    SUBCASE("Executar partida") {
        std::string input = "EP R jogador1 jogador2\nFS\n";
        std::string expectedOutput = 
            "--BEM VINDO AOS JOGOS--\n"
            "--------------------------------------------------------------------\n"
            "O QUE VOCE DESEJA FAZER? PARA:\n"
            ".CADASTRAR JOGADOR: DIGITE ''CJ <Apelido> <Nome>''\n"
            ".REMOVER JOGADOR: DIGITE ''RJ <APELIDO>''\n"
            ".LISTAR JOGADORES: DIGITE ''LJ [A/N]''\n"
            ".EXECUTAR PARTIDA: DIGITE ''EP <JOGO: (R/L)> <Apelido1> <Apelido2>''\n"
            ".FINALIZAR SISTEMA: DIGITE ''FS''\n"
            "--------------------------------------------------------------------\n"
            "ERRO: dados incorretos\nFinalizando o programa!\n";

        test_main(input, expectedOutput);
    }

    SUBCASE("Finalizar sistema") {
        std::string input = "FS\n";
        std::string expectedOutput = 
            "--BEM VINDO AOS JOGOS--\n"
            "--------------------------------------------------------------------\n"
            "O QUE VOCE DESEJA FAZER? PARA:\n"
            ".CADASTRAR JOGADOR: DIGITE ''CJ <Apelido> <Nome>''\n"
            ".REMOVER JOGADOR: DIGITE ''RJ <APELIDO>''\n"
            ".LISTAR JOGADORES: DIGITE ''LJ [A/N]''\n"
            ".EXECUTAR PARTIDA: DIGITE ''EP <JOGO: (R/L)> <Apelido1> <Apelido2>''\n"
            ".FINALIZAR SISTEMA: DIGITE ''FS''\n"
            "--------------------------------------------------------------------\n"
            "-> Finalizando o programa!\n";

        test_main(input, expectedOutput);
    }
}