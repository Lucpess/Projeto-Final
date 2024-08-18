#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogos.hpp"

class Reversi : public Jogos{
public:
   Reversi();
   ~Reversi();
   void start(std::string jogador1, std::string jogador2, Cadastro& cadastro ) override;
   bool verificaFimDeJogo(std::string jogador1, std::string jogador2, Cadastro& cadastro);
   bool verificaLinha(int, int, std::string estado);
   bool verificaColuna(int, int, std::string estado);
   bool verificaDiagonal(int, int, std::string estado);
   void contarPecas(int& pecasBrancas, int& pecasPretas);
   std::string pecaAdversaria();
   bool posicaoPermitida(int i, int j, std::string turno);
   bool temJogadasValidas(std::string jogador);
   void jogadasValidas(std::string turno);

private:
   bool jogadaPermitida(int linha, int col);
   void viraPecasColuna(int linha, int col, std::string turno);
   void viraPecasLinha(int linha, int col, std::string turno);
   void viraPecasDiagonal(int linha, int col, std::string turno);
   void anunciaTurno(std::string jogador1, std::string jogador2) override;
   std::vector<std::pair<int, int>> jogadasValidas_;
   std::string jogador;
};

#endif 