#include "cadastro.hpp"
#include<fstream>
#include<algorithm>
#include<vector>

Jogador::Jogador(const std::string& nome, const std::string& apelido)
: vitoriasReversi(0), derrotasReversi(0), vitoriasLig4(0), derrotasLig4(0), nome(nome), apelido(apelido) {}


Cadastro::Cadastro(){
    carregarCadastro();
}

Cadastro::~Cadastro(){
    salvarCadastro();
}

void Cadastro::salvarCadastro(){
    std::ofstream arquivo("cadastro_jogadores.txt");
    if (!arquivo) {
        std::cerr << "Erro ao abrir arquivo." << std::endl;
        return;
    }

     for (const auto& jogador : jogadores) {
        arquivo << jogador.getVitoriasReversi() << " " << jogador.getDerrotasReversi() << " "
                << jogador.getVitoriasLig4() << " " << jogador.getDerrotasLig4() << " "
                << jogador.getNome() << " " << jogador.getApelido() << std::endl;
    }
}

void Cadastro::cadastraJogador(const std::string& apelido, const std::string& nome) {
    if (jogadores.find(apelido) != jogadores.end()) {
        std::cerr << "ERRO: jogador repetido" << std::endl;
        return;
    }
    jogadores[apelido] = Jogador(apelido, nome);
    std::cout << "Jogador" << apelido << "cadastrado." << std::endl;
}

void removeJogador(const std::string& apelido) {
    if(jogadores.erase(apelido)){
        std::cout << "Jogador " << apelido << "removido. " << std::endl;
    } else {
        std::cerr << "Jogador não cadastrado." << std::endl;
    }
}

void Cadastro::listaJogadores() const {
    for(const auto& [apelido, jogador] : jogadores){
        std::cout << "Apelido: " << apelido << "Nome: " << jogador.nome << std::endl;
    }
}
// 
void Cadastro::salvarCadastro(){
    std::ofstream arquivo("cadastro_jogadores.txt");

    for(int &i : jogadores) {
        arquivo << 
    }
}
