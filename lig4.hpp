#ifndef LIG4_H
#define LIG4_H

#include "tabuleiro.hpp"

class Lig4 {
public: 
    Lig4();
    void start();
    bool escolheJogada (int col);
    bool fimDeJogo () const;
    void printTabuleiro () const;
    //void verificaJogada();
    //void executaJogada();
    //void verificaVitoria();
    //void turno();  

private: 
        Tabuleiro tabuleiro;
        bool jogadaPermitida(int col) const;
        void novaJogada(int col) const;
};

#endif 
