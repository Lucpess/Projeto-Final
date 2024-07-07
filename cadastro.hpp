#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <string>
#include<iostream>
#include<map>
#include<vector>

class Jogador {
    private:
        std::string apelido;
        std::string nome;
        int vitoriasReversi;
        int derrotasReversi;
        int vitoriasLig4;
        int derrotasLig4;
    
    public:
        Jogador(const std::string& nome, const std::string& apelido);
        std::string getApelido();
        std::string getNome();
        void novaVitoria();
        void novaDerrota();
        void printResultados();  

        Jogador();
}; 

class Cadastro {
    private:
        std::vector<Jogador> jogadores;
        int numJogadores = 0;
        void salvarCadastro();
        void carregarCadastro();
        
    public:
        Cadastro();
        ~Cadastro();
        void cadastraJogador(const std::string& apelido, const std::string& nome);
        void verificaJogador();
        void listaJogadores();
        void removeJogador(std::string& apelido);
        void executarPartida();

};

#endif