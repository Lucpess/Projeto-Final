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
        std::string getApelido() const;
        std::string getNome() const;
        int getVitoriasReversi() const;
        int getDerrotasReversi() const;
        int getVitoriasLig4() const;
        int getDerrotasLig4() const;
        void novaVitoria() const;
        void novaDerrota() const;
        void printResultados() const;  

        Jogador();
}; 

class Cadastro {
    private:
        std::map<std::string, Jogador> jogadores;
        int numJogadores = 0;
        void salvarCadastro();
        void carregarCadastro();
        
    public:
        void cadastraJogador(const std::string& apelido, const std::string& nome);
        void verificaJogador();
        void listaJogadores();
        void removeJogador(std::string& apelido);
        void executarPartida();

        Cadastro();
        ~Cadastro();

};

#endif