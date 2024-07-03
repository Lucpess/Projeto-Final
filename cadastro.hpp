#ifndef CADASTRO_H
#define CADASTRO_H
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
        void escolheJogador();
        void listaJogadores();
        void removeJogador();

};

#endif