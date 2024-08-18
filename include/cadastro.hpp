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

        int numJogadores = 0; //?
        void salvarCadastro();
        void atualizarCadastro();
        
    public:
        void cadastraJogador(const std::string& apelido, const std::string& nome);
        void listaJogadores(const std::string& ordem) const;
        void removeJogador(const std::string& apelido);
        void registrarResultado(const std::string& vencedor, const std::string& perdedor, char jogo); 
        bool existeJogador(const std::string& apelido) const;
        void executarPartida(); //?

        Cadastro();
        ~Cadastro();

};

#endif