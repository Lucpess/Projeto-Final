#ifndef LIG4_H
#define LIG4_H

#include "tabuleiro.hpp"

class Lig4 {
public: 
    Lig4();
    void start(std::string jogador1, std::string jogador2);
    bool verifica4(int linha, int coluna);
    int verificaFimDeJogo (int coluna, std::string jogador1, std::string jogador2);
    void printTabuleiro () const;

private: 
        bool fimDeJogo;
        Tabuleiro tabuleiro;
        std::string turno;
        bool jogadaPermitida(int col);
        void novaJogada(int col);
        void mudaTurno();
        void anunciaTurno(std::string jogador1, std::string jogador2);
};

#endif 
