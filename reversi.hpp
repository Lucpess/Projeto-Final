   #ifndef REVERSI_HPP
   #define REVERSI_HPP

   #include "tabuleiro.hpp"
   #include "cadastro.hpp"
   class Reversi {
   public:
      Reversi();
      void start(std::string jogador1, std::string jogador2 );
      bool verificaFimDeJogo();
      void printTabuleiro() const;
      void jogadorAtual(std::string jogador1, std::string jogador2);
      bool confereLinha(int, int, std::string estado);
      bool confereColuna(int, int, std::string estado);
      bool confereDiagonal(int, int, std::string estado);
      void contarPecas(int& pecasBrancas, int& pecasPretas);
      std::string pecaAdversaria();
      bool posicaoPermitida(int i, int j, std::string turno);
      bool temJogadasValidas(std::string jogador);

   private:
      bool fimDeJogo;
      Tabuleiro tabuleiro;
      std::string turno;
      bool jogadaPermitida(int linha, int col);
      void viraPecasColuna(int linha, int col, std::string turno);
      void viraPecasLinha(int linha, int col, std::string turno);
      void viraPecasDiagonal(int linha, int col, std::string turno);
      void mudaTurno();
      void anunciaTurno(std::string jogador1, std::string jogador2);
      void adicionaPeca(int linha, int col);
      std::vector<int> jogadasLinha;
      std::vector<int> jogadasColuna;
      std::string jogador;
   };

   #endif 