#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <string>
#include<iostream>
#include<map>

class Jogador {
    private:
        std::string apelido;
        std::string nome;
        int vitoriasReversi;
        int derrotasReversi;
        int vitoriasLig4;
        int derrotasLig4;

        Jogador();
        
};

class Cadastro {
    private:
        std::map<std::string, Jogador> jogadores;

    public:
        void verificaJogador();
        void cadastraJogador();
        //void escolheJogador();
        void listaJogadores();
        void removeJogador();

};

#endif