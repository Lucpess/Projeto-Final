   #ifndef REVERSI_HPP
   #define REVERSI_HPP

   #include "tabuleiro.hpp"

   class Reversi {
   public:
      Reversi();
      void start();
      bool escolheJogada (int linha, int col);
      bool verificafimDeJogo () const;
      void printTabuleiro () const;

   private:
      bool fimDeJogo;
      Tabuleiro tabuleiro;
      bool jogadaPermitida(int linha, int col) const;
      void viraPeca(int linha, int col);
   };

   #endif 
