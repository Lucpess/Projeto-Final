#ifndef LIG4_H
#define LIG4_H

#include "Jogada.hpp"
#include "tabuleiro.hpp"

class Lig4 : public Jogada {
public: 
    Lig4();
    void start() override;
    bool escolheJogada ();
    bool fimDeJogo () const override;
    void printTabuleiro () const override;
    //void verificaJogada();
    //void executaJogada();
    //void verificaVitoria();
    //void turno();

private: 
        Tabuleiro tabuleiro;
        bool jogadaPermitida(int linha, int col, )
        void Joga(int linha, int col, )
};

#endif 
