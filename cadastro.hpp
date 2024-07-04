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
        void salvarCadastro();
        void carregarCadastro();

    public:
        void cadastraJogador(const std::string& apelido, const std::string& nome);
        void verificaJogador();
        void listaJogadores();
        void removeJogador(std::string& apelido);
        void executarPartida();

};

#endif