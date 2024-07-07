   #ifndef REVERSI_HPP
   #define REVERSI_HPP

   #include "tabuleiro.hpp"

   class Reversi {
   public:
      Reversi();
      void start();
      bool escolheJogada (int linha, int col);
      bool fimDeJogo () const;
      void printTabuleiro () const;
      //jogada()
      //void verificaJogada();
      //void executaJogada();
      //void verificaVitoria();
      //void passaTurno();
      //void imprime();

   private:
      Tabuleiro tabuleiro;
      bool jogadaPermitida(int linha, int col) const;
      void viraPeca(int linha, int col);
   };

   #endif 
