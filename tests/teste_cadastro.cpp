#include "doctest.h"
#include "cadastro.hpp"
#include "jogador.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

// Testa a construtora e destrutora da classe Cadastro
TEST_CASE("Testar construtora e destrutora da classe Cadastro") {
    CHECK_NOTHROW(Cadastro cadastro);
}

// Testa a função salvarCadastro com um fluxo de arquivo inválido
TEST_CASE("Testar salvarCadastro com fluxo de arquivo inválido") {
    Cadastro cadastro;

    // Redefine o fluxo de arquivo para um fluxo inválido
    std::ofstream arquivo("arquivo_invalido.txt");
    arquivo.close(); // Fecha o arquivo para simular um erro ao tentar abrir

    // Para garantir que o teste não deixe resíduos, limpe o arquivo
    std::remove("arquivo_invalido.txt");
}
// Helper function to create a test file with sample data
void createTestFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

// Helper function to remove a test file
void removeTestFile(const std::string& filename) {
    std::remove(filename.c_str());
}

// Testa a função atualizarCadastro
TEST_CASE("Testar atualizarCadastro") {
    Cadastro cadastro;

    // Cria um arquivo de teste com dados de jogadores
    std::string filename = "test_cadastro_jogadores.txt";
    std::string content = "apelido1 nome1 5 2 3 1\napelido2 nome2 7 1 4 0";
    createTestFile(filename, content);

    // Limpeza: remove o arquivo de teste
    removeTestFile(filename);
}

// Testa atualizarCadastro quando o arquivo não pode ser aberto
TEST_CASE("Testar atualizarCadastro com falha na abertura do arquivo") {
    Cadastro cadastro;

    // Cria um nome de arquivo inválido
    std::string invalidFilename = "invalid_file.txt";
}
// Testa a função cadastraJogador com sucesso
TEST_CASE("Testar cadastraJogador com entrada válida") {
    Cadastro cadastro;

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream outputStream;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputStream.rdbuf());

    // Cadastra um jogador com entrada válida
    CHECK_NOTHROW(cadastro.cadastraJogador("apelido1", "nome1"));

    // Verifica se a mensagem de sucesso está correta
    std::string output = outputStream.str();
    CHECK(output.find("Jogador apelido1 cadastrado com sucesso") != std::string::npos);

    // Restaura o stream original
    std::cout.rdbuf(originalBuffer);
}

// Testa a função cadastraJogador com entrada inválida
TEST_CASE("Testar cadastraJogador com entrada inválida") {
    Cadastro cadastro;

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream errorStream;
    std::streambuf* originalBuffer = std::cerr.rdbuf();
    std::cerr.rdbuf(errorStream.rdbuf());

    // Testa entrada com apelido vazio
    CHECK_THROWS_AS(cadastro.cadastraJogador("", "nome1"), std::invalid_argument);

    // Testa entrada com nome vazio
    CHECK_THROWS_AS(cadastro.cadastraJogador("apelido1", ""), std::invalid_argument);

    // Testa jogador já cadastrado
    cadastro.cadastraJogador("apelido1", "nome1");
    CHECK_THROWS_AS(cadastro.cadastraJogador("apelido1", "nome2"), std::runtime_error);

    // Restaura o stream original
    std::cerr.rdbuf(originalBuffer);
}
// Testa a função removeJogador com sucesso
TEST_CASE("Testar removeJogador com jogador existente") {
    Cadastro cadastro;

    // Adiciona um jogador para garantir que ele exista
    cadastro.cadastraJogador("apelido1", "nome1");

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream outputStream;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputStream.rdbuf());

    // Remove o jogador
    CHECK_NOTHROW(cadastro.removeJogador("apelido1"));

    // Verifica se a mensagem de sucesso está correta
    std::string output = outputStream.str();
    CHECK(output.find("Jogador apelido1 removido com sucesso") != std::string::npos);

    // Restaura o stream original
    std::cout.rdbuf(originalBuffer);
}

// Testa a função removeJogador com jogador inexistente
TEST_CASE("Testar removeJogador com jogador inexistente") {
    Cadastro cadastro;

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream errorStream;
    std::streambuf* originalBuffer = std::cerr.rdbuf();
    std::cerr.rdbuf(errorStream.rdbuf());

    // Tenta remover um jogador que não existe
    CHECK_NOTHROW(cadastro.removeJogador("apelido_inexistente"));

    // Verifica se a mensagem de erro está correta
    std::string errorOutput = errorStream.str();
    CHECK(errorOutput.find("ERRO: jogador inexistente") != std::string::npos);

    // Restaura o stream original
    std::cerr.rdbuf(originalBuffer);
}
// Testa a função listaJogadores com jogadores cadastrados e ordem por apelido
TEST_CASE("Testar listaJogadores com ordem por apelido") {
    Cadastro cadastro;

    // Adiciona jogadores
    cadastro.cadastraJogador("bapelido", "nomeb");
    cadastro.cadastraJogador("apelidoa", "nomea");

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream outputStream;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputStream.rdbuf());

    // Lista jogadores por apelido
    CHECK_NOTHROW(cadastro.listaJogadores("A"));

    // Verifica a saída
    std::string output = outputStream.str();
    CHECK(output.find("apelidoa nomea") != std::string::npos);
    CHECK(output.find("bapelido nomeb") != std::string::npos);

    // Restaura o stream original
    std::cout.rdbuf(originalBuffer);
}

// Testa a função listaJogadores com ordem por nome
TEST_CASE("Testar listaJogadores com ordem por nome") {
    Cadastro cadastro;

    // Adiciona jogadores
    cadastro.cadastraJogador("apelidoa", "nomeb");
    cadastro.cadastraJogador("bapelido", "nomea");

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream outputStream;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputStream.rdbuf());

    // Lista jogadores por nome
    CHECK_NOTHROW(cadastro.listaJogadores("N"));

    // Verifica a saída
    std::string output = outputStream.str();
    CHECK(output.find("bapelido nomea") != std::string::npos);
    CHECK(output.find("apelidoa nomeb") != std::string::npos);

    // Restaura o stream original
    std::cout.rdbuf(originalBuffer);
}

// Testa a função listaJogadores com jogadores cadastrados e ordem inválida
TEST_CASE("Testar listaJogadores com ordem inválida") {
    Cadastro cadastro;

    // Adiciona jogadores
    cadastro.cadastraJogador("apelidoa", "nomea");

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream errorStream;
    std::streambuf* originalBuffer = std::cerr.rdbuf();
    std::cerr.rdbuf(errorStream.rdbuf());

    // Tenta listar jogadores com ordem inválida
    CHECK_THROWS_AS(cadastro.listaJogadores("X"), std::runtime_error);

    // Verifica a mensagem de erro
    std::string errorOutput = errorStream.str();
    CHECK(errorOutput.find("ERRO: ordem inválida") != std::string::npos);

    // Restaura o stream original
    std::cerr.rdbuf(originalBuffer);
}

// Testa a função listaJogadores com nenhum jogador cadastrado
TEST_CASE("Testar listaJogadores com nenhum jogador cadastrado") {
    Cadastro cadastro;

    // Redireciona a saída para um stream para capturar a mensagem
    std::ostringstream errorStream;
    std::streambuf* originalBuffer = std::cerr.rdbuf();
    std::cerr.rdbuf(errorStream.rdbuf());

    // Tenta listar jogadores com nenhum jogador cadastrado
    CHECK_THROWS_AS(cadastro.listaJogadores("A"), std::runtime_error);

    // Verifica a mensagem de erro
    std::string errorOutput = errorStream.str();
    CHECK(errorOutput.find("ERRO: Nenhum jogador cadastrado") != std::string::npos);

    // Restaura o stream original
    std::cerr.rdbuf(originalBuffer);
} 
// Helper function to set up a Cadastro instance with sample data
Cadastro createSampleCadastro() {
    Cadastro cadastro;
    cadastro.cadastraJogador("jogador1", "Nome1");
    cadastro.cadastraJogador("jogador2", "Nome2");
    return cadastro;
}

TEST_CASE("Cadastro::registrarResultado") {
    Cadastro cadastro = createSampleCadastro();

    // Test success case for Reversi
    CHECK_NOTHROW(cadastro.registrarResultado("jogador1", "jogador2", 'R'));

    // Test success case for Lig4
    CHECK_NOTHROW(cadastro.registrarResultado("jogador1", "jogador2", 'L'));

    // Test cases for invalid scenarios
    SUBCASE("Invalid game type") {
        CHECK_THROWS_AS(cadastro.registrarResultado("jogador1", "jogador2", 'X'), std::runtime_error);
    }

    SUBCASE("Non-existent player") {
        CHECK_THROWS_AS(cadastro.registrarResultado("jogador1", "jogador3", 'R'), std::runtime_error);
    }
}

TEST_CASE("Cadastro::existeJogador") {
    Cadastro cadastro = createSampleCadastro();

    // Test existence of a player that exists
    CHECK(cadastro.existeJogador("jogador1") == true);
    CHECK(cadastro.existeJogador("jogador2") == true);

    // Test non-existence of a player that does not exist
    CHECK(cadastro.existeJogador("jogador3") == false);
}