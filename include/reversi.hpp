/**
 * @file reversi.hpp
 * @brief Declarações da classe Reversi para o jogo de Reversi.
 * 
 * Este arquivo contém a definição da classe `Reversi`, que é uma subclasse da classe `Jogos`.
 * A classe `Reversi` implementa a lógica do jogo Reversi (também conhecido como Othello).
 */

#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogos.hpp"

/**
 * @class Reversi
 * @brief Classe que implementa o jogo de Reversi.
 * 
 * A classe `Reversi` define os métodos e atributos necessários para gerenciar o estado do jogo,
 * verificar jogadas válidas e atualizar o tabuleiro. Ela herda da classe `Jogos` e sobrecarrega
 * alguns dos seus métodos para adaptar à lógica do Reversi.
 */
class Reversi : public Jogos{
public:
   /**
    * @brief Construtor padrão da classe Reversi.
    */
   Reversi();

   /**
    * @brief Destrutor da classe Reversi.
    */
   ~Reversi();

   /**
    * @brief Inicia o jogo com os jogadores especificados.
    * @param jogador1 Nome do primeiro jogador.
    * @param jogador2 Nome do segundo jogador.
    * @param cadastro Referência ao objeto Cadastro para registrar resultados.
    */
   void start(std::string jogador1, std::string jogador2, Cadastro& cadastro ) override;

   /**
    * @brief Verifica se o jogo chegou ao fim.
    * @param jogador1 Nome do primeiro jogador.
    * @param jogador2 Nome do segundo jogador.
    * @param cadastro Referência ao objeto Cadastro para registrar resultados.
    * @return Verdadeiro se o jogo terminou, falso caso contrário.
    */
   bool verificaFimDeJogo(std::string jogador1, std::string jogador2, Cadastro& cadastro);

    /**
    * @brief Verifica se uma jogada é válida em uma linha específica.
    * @param i Linha onde a jogada será feita.
    * @param j Coluna onde a jogada será feita.
    * @param estado Estado da peça (PRETO ou BRANCO).
    * @return Verdadeiro se a jogada é válida na linha, falso caso contrário.
    */
   bool verificaLinha(int, int, std::string estado);

    /**
    * @brief Verifica se uma jogada é válida em uma coluna específica.
    * @param i Linha onde a jogada será feita.
    * @param j Coluna onde a jogada será feita.
    * @param estado Estado da peça (PRETO ou BRANCO).
    * @return Verdadeiro se a jogada é válida na coluna, falso caso contrário.
    */
   bool verificaColuna(int, int, std::string estado);

   /**
    * @brief Verifica se uma jogada é válida em uma diagonal específica.
    * @param i Linha onde a jogada será feita.
    * @param j Coluna onde a jogada será feita.
    * @param estado Estado da peça (PRETO ou BRANCO).
    * @return Verdadeiro se a jogada é válida na diagonal, falso caso contrário.
    */
   bool verificaDiagonal(int, int, std::string estado);

    /**
    * @brief Conta o número de peças brancas e pretas no tabuleiro.
    * @param pecasBrancas Referência para o número de peças brancas.
    * @param pecasPretas Referência para o número de peças pretas.
    */
   void contarPecas(int& pecasBrancas, int& pecasPretas);

   /**
    * @brief Retorna a peça adversária (BRANCO se o turno é PRETO e vice-versa).
    * @return Estado da peça adversária.
    */
   std::string pecaAdversaria();

   /**
    * @brief Verifica se uma posição é permitida para a jogada.
    * @param i Linha onde a jogada será feita.
    * @param j Coluna onde a jogada será feita.
    * @param turno Estado da peça do jogador atual (PRETO ou BRANCO).
    * @return Verdadeiro se a posição é permitida, falso caso contrário.
    */
   bool posicaoPermitida(int i, int j, std::string turno);

   /**
    * @brief Verifica se há jogadas válidas para um jogador.
    * @param jogador Estado da peça do jogador (PRETO ou BRANCO).
    * @return Verdadeiro se há jogadas válidas, falso caso contrário.
    */
   bool temJogadasValidas(std::string jogador);

   /**
    * @brief Imprime as jogadas válidas para o jogador atual.
    * @param turno Estado da peça do jogador atual (PRETO ou BRANCO).
    */
   void jogadasValidas(std::string turno);

private:

   /**
    * @brief Vira as peças na coluna em torno da jogada feita.
    * @param linha Linha da jogada.
    * @param col Coluna da jogada.
    * @param turno Estado da peça do jogador atual (PRETO ou BRANCO).
    */
   void viraPecasColuna(int linha, int col, std::string turno);

   /**
    * @brief Vira as peças na linha em torno da jogada feita.
    * @param linha Linha da jogada.
    * @param col Coluna da jogada.
    * @param turno Estado da peça do jogador atual (PRETO ou BRANCO).
    */
   void viraPecasLinha(int linha, int col, std::string turno);

   /**
    * @brief Vira as peças nas diagonais em torno da jogada feita.
    * @param linha Linha da jogada.
    * @param col Coluna da jogada.
    * @param turno Estado da peça do jogador atual (PRETO ou BRANCO).
    */
   void viraPecasDiagonal(int linha, int col, std::string turno);

   /**
    * @brief Anuncia o turno do jogador atual.
    * @param jogador1 Nome do primeiro jogador.
    * @param jogador2 Nome do segundo jogador.
    */
   void anunciaTurno(std::string jogador1, std::string jogador2) override;

   /**
    * @brief Lista de jogadas válidas para o jogador atual.
    */
   std::vector<std::pair<int, int>> jogadasValidas_;
};

#endif 