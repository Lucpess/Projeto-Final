#ifndef CADASTRO_H
#define CADASTRO_H
#include <string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>

class Jogador {
    private:
        std::string apelido;
        std::string nome;
        int vitoriasReversi;
        int derrotasReversi;
        int vitoriasLig4;
        int derrotasLig4;

        Jogador() : vitoriasReversi(0), derrotasReversi(0), vitoriasLig4(0), derrotasLig4(0);
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