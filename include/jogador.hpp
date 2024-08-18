#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include<iostream>

class Jogador {
    private:
        std::string apelido;
        std::string nome;
        int vitoriasReversi;
        int derrotasReversi;
        int vitoriasLig4;
        int derrotasLig4;
    
    public:
        std::string getApelido() const; 
        std::string getNome() const; 
        int getVitoriasReversi() const;
        int getDerrotasReversi() const;
        int getVitoriasLig4() const;
        int getDerrotasLig4() const;

        void printResultados() const; 

        void setApelido(const std::string& apelido);
        void addVitoriaReversi();
        void addDerrotaReversi();
        void addVitoriaLig4();
        void addDerrotaLig4();

        Jogador();
        Jogador(const std::string& apelido, const std::string& nome, 
        int vitorias_reversi = 0, int derrotas_reversi = 0, int vitorias_lig4 = 0, int derrotas_lig4 = 0);
}; 

#endif