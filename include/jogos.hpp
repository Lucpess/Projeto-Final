/**
 * @file jogos.hpp
 * @brief Declaração da classe base Jogos para gerenciamento de jogos e manipulação de tabuleiros.
 */

#ifndef JOGOS_HPP
#define JOGOS_HPP

#include "tabuleiro.hpp"
#include "cadastro.hpp"

/**
 * @class Jogos
 * @brief Classe base para jogos que utilizam um tabuleiro.
 * 
 * A classe `Jogos` fornece a interface e funcionalidades comuns para todos os jogos que utilizam um tabuleiro.
 * Inclui métodos para iniciar o jogo, imprimir o tabuleiro, e gerenciar o turno dos jogadores.
 */
class Jogos {
    public:
        /**
         * @brief Construtor da classe Jogos.
         * 
         * @param jogo Caracter que indica o tipo de jogo a ser inicializado. 
         * O tabuleiro será configurado de acordo com este tipo.
         */
        Jogos(char jogo);

        /**
         * @brief Destrutor virtual da classe Jogos.
         */
        virtual ~Jogos();

        /**
         * @brief Método virtual puro para iniciar o jogo.
         * 
         * Este método deve ser implementado pelas classes derivadas para iniciar o jogo específico.
         * 
         * @param jogador1 Nome do primeiro jogador.
         * @param jogador2 Nome do segundo jogador.
         * @param cadastro Referência para um objeto `Cadastro` que pode ser utilizado para registrar o jogo.
         */
        virtual void start(std::string jogador1, std::string jogador2, Cadastro& cadastro) = 0;

        /**
         * @brief Imprime o estado atual do tabuleiro no console.
         * 
         * Utiliza o método `imprimeTabuleiro` da classe `Tabuleiro` para exibir o tabuleiro no console.
         */
        void printTabuleiro() const;

    protected:
        /**
         * @brief Indica se o jogo terminou.
         * 
         * É um flag que é atualizado durante a execução do jogo para indicar seu status.
         */
        bool fimDeJogo;

        /**
         * @brief Objeto `Tabuleiro` que representa o tabuleiro do jogo.
         */
        Tabuleiro tabuleiro;

        /**
         * @brief String que representa o turno atual do jogo.
         * 
         * Pode ser "PRETO" ou "BRANCO".
         */
        std::string turno;

        /**
         * @brief Alterna o turno dos jogadores.
         * 
         * Se o turno atual for "PRETO", muda para "BRANCO" e vice-versa.
         */
        void mudaTurno();

        /**
         * @brief Método virtual puro para anunciar o turno dos jogadores.
         * 
         * Este método deve ser implementado pelas classes derivadas para anunciar o turno do jogador.
         * 
         * @param jogador1 Nome do primeiro jogador.
         * @param jogador2 Nome do segundo jogador.
         */
        virtual void anunciaTurno(std::string jogador1, std::string jogador2) = 0;
};

#endif // JOGOS_HPP
