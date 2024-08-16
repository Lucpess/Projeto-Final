   #ifndef REVERSI_HPP
   #define REVERSI_HPP

   #include "tabuleiro.hpp"
   using namespace std;

   class Reversi {
   public:
      Reversi();
      void start(std::string jogador1, std::string jogador2 );
      bool escolheJogada(int linha, int col);
      bool verificaFimDeJogo() const;
      void printTabuleiro() const;
      void listarJogadasValidas();
      bool confereLinha(int, int, std::string estado);
      bool confereColuna(int, int, std::string estado);
      bool confereDiagonal(int, int, std::string estado);
      void contarPecas(int& brancas, int& pretas);
      std::string corOposta();
      bool posicaoPermitida(int i, int j, std::string turno);
      void jogadasValidas();

   private:
      bool fimDeJogo;
      Tabuleiro tabuleiro;
      Casa casa;
      std::string turno;
      bool jogadaPermitida(int linha, int col) const;
      void novaJogada(int linha, int col);
      vector<vector<string>> viraPecasVertical(int linha, int col, string turno);
      vector<vector<string>> viraPecasHorizontal(int linha, int col, string turno);
      vector<vector<string>> viraPecasDiagonal(int linha, int col, string turno);
      void mudaTurno();
      void anunciaTurno(std::string jogador1, std::string jogador2);
      void adicionaPeca(int linha, int col);
      std::vector<int> jogadasLinha;
      std::vector<int> jogadasColuna;
   };

   #endif 