#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogada.hpp"
#include "tabuleiro.hpp"

class Reversi : public Jogada {
public:
   Reversi();

   void start() override;
   bool escolheJogada (int linha, int col, ) override;
   bool fimDeJogo () const override;
   void printTabuleiro () const override;
   //jogada()
   //void verificaJogada();
   //void executaJogada();
   //void verificaVitoria();
   //void passaTurno();
   //void imprime();

private:
   Tabuleiro tabuleiro;
   bool jogadaPermitida(int linha, int col, )
   void Joga(int linha, int col, )
};

#endif 
