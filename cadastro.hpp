#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include"jogador.hpp"
#include <string>
#include<iostream>
#include<map>
#include<vector>

class Cadastro {
    private:
        std::map<std::string, Jogador> jogadores;

        int numJogadores = 0;
        void salvarCadastro();
        void atualizarCadastro();
        
    public:
        void cadastraJogador(const std::string& apelido, const std::string& nome);
        void listaJogadores() const;
        void removeJogador(std::string& apelido);
        void executarPartida();

        Cadastro();
        ~Cadastro();

};

#endif