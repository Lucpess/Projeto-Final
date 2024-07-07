#include "cadastro.hpp"
#include<fstream>
#include<algorithm>
#include<vector>

Cadastro::Cadastro(){
    atualizarCadastro();
}

Cadastro::~Cadastro(){
    salvarCadastro();
}

void Cadastro::salvarCadastro(){
    std::ofstream arquivo("cadastro_jogadores.txt");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir arquivo." << std::endl;
        return;
    }

     for (const auto& par : jogadores) {
        const Jogador& jogador = par.second;
        arquivo << jogador.getApelido() << " " << jogador.getNome() << " "
                << jogador.getVitoriasReversi() << " " << jogador.getDerrotasReversi() << " "
                << jogador.getVitoriasLig4() << " " << jogador.getDerrotasLig4() << std::endl;
    }
}

void Cadastro::atualizarCadastro(){
    std::ifstream arquivo("cadastro_jogadores.txt");
    if(!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    jogadores.clear();

    std::string nome, apelido;
    int vitoriasReversi, derrotasReversi, vitoriasLig4, derrotasLig4;

    while(arquivo >> apelido >> nome >> vitoriasReversi >> derrotasReversi >> vitoriasLig4 >> derrotasLig4) {
        Jogador jogador(apelido, nome, vitoriasReversi, derrotasReversi, vitoriasLig4, derrotasLig4);
        jogadores.emplace(apelido, jogador);
    }
}

void Cadastro::cadastraJogador(const std::string& apelido, const std::string& nome) {
    if(apelido.empty() || nome.empty()) {
        std::cout << "ERRO: dados incorretos" << std::endl;
        return;
    }
    //if (jogadores.find(apelido) != jogadores.end()) {
       // std::cerr << "ERRO: dados incorretos" << std::endl;
      //  return;
   // }

    for(const auto& par : jogadores) {
        if(par.first == apelido) {
            std::cerr << "ERRO: jogador repetido" <<std:: endl;
        }
        return;
    }

    jogadores.emplace(apelido, Jogador(apelido, nome));
    std::cout << "Jogador" << apelido << "cadastrado com sucesso" << std::endl;
}

void removeJogador(const std::string& apelido) {
    if(jogadores.erase(apelido)){
        std::cout << "Jogador " << apelido << "removido com sucesso " << std::endl;
    } else {
        std::cerr << "ERRO: jogador inexistente" << std::endl;
    }
}

void Cadastro::listaJogadores(const std::string& ordem) const {
    
