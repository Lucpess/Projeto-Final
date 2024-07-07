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

void Cadastro::carregarCadastro(){
    std::ofstream arquivo("cadastro_jogadores.txt");
}
