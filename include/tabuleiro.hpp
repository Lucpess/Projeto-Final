/**
 * @file tabuleiro.hpp
 * @brief Declaração da classe Tabuleiro e estrutura Casa para gerenciar o estado do tabuleiro de diferentes jogos.
 */

#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <string>

/**
 * @struct Casa
 * @brief Estrutura que representa uma célula no tabuleiro.
 * 
 * A estrutura `Casa` armazena o estado de uma célula no tabuleiro, que pode ser "PRETO", "BRANCO", ou "NULO".
 */
struct Casa {
    /**
     * @brief Estado da célula.
     * 
     * Pode ser "PRETO = X", "BRANCO = O", ou "NULO =' ' ".
     */
    std::string estado;
};

/**
 * @class Tabuleiro
 * @brief Classe que representa o tabuleiro de um jogo e suas operações.
 * 
 * A classe `Tabuleiro` é usada para gerenciar o estado do tabuleiro, incluindo a inicialização, modificação e impressão do mesmo.
 */
class Tabuleiro {
    private:
        /**
         * @brief Matriz que representa o tabuleiro.
         * 
         * É uma matriz de objetos `Casa` que armazena o estado de cada célula no tabuleiro.
         */
        std::vector<std::vector<Casa>> tabuleiro;

    public:
        /**
         * @brief Construtor padrão da classe Tabuleiro.
         */
        Tabuleiro();

        /**
         * @brief Inicializa o tabuleiro com base no tipo de jogo.
         * 
         * @param jogo Caracter que indica o tipo de jogo:
         * - 'R': Reversi (8x8)
         * - 'L': Lig4 (6x7)
         * - 'D': Dama (8x8)
         */
        void inicializaTabuleiro(char jogo);

        /**
         * @brief Imprime o estado atual do tabuleiro no console.
         * 
         * O tabuleiro é impresso com as células representadas por espaços em branco, "X" para peças pretas, e "O" para peças brancas.
         */
        void imprimeTabuleiro() const;

        /**
         * @brief Verifica o estado de uma célula específica no tabuleiro.
         * 
         * @param linha Linha da célula a ser verificada.
         * @param coluna Coluna da célula a ser verificada.
         * @param _estado Estado a ser comparado ("PRETO", "BRANCO", "NULO").
         * @return Verdadeiro se o estado da célula corresponde ao estado fornecido, falso caso contrário.
         */
        bool verificaCasa(int linha, int coluna, std::string _estado) const;

        /**
         * @brief Modifica o estado de uma célula específica no tabuleiro.
         * 
         * @param linha Linha da célula a ser modificada.
         * @param coluna Coluna da célula a ser modificada.
         * @param _estado Novo estado a ser definido para a célula ("PRETO", "BRANCO", "NULO").
         */
        void modificaTabuleiro(int linha, int coluna, std::string _estado);
};  

#endif 
