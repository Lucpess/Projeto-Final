#ifndef LIG4_H
#define LIG4_H

#include "jogos.hpp"

/**
 * @class Lig4
 * @brief Classe que implementa o jogo Lig4 (Conecte 4).
 * 
 * A classe Lig4 herda de Jogos e fornece toda a funcionalidade necessária
 * para iniciar e gerenciar uma partida de Lig4, incluindo verificação de
 * jogadas, controle de turnos e detecção de vitória ou empate.
 */

class Lig4 : public Jogos {
public: 
    /**
     * @brief Construtor padrão da classe Lig4.
     * 
     * Inicializa o estado do jogo, preparando o tabuleiro e outros elementos
     * necessários para o início de uma partida.
     */
    Lig4();

    /**
     * @brief Destrutor da classe Lig4.
     * 
     * Libera quaisquer recursos alocados durante o jogo, garantindo uma
     * finalização limpa do objeto Lig4.
     */
    ~Lig4();

    /**
     * @brief Inicia uma nova partida de Lig4.
     * 
     * Configura os jogadores e inicia o loop principal do jogo, onde os
     * jogadores alternam turnos até que haja um vencedor ou empate.
     * 
     * @param jogador1 Nome do primeiro jogador.
     * @param jogador2 Nome do segundo jogador.
     * @param cadastro Referência para o objeto Cadastro, utilizado para
     * registrar informações dos jogadores.
     */
    void start(std::string jogador1, std::string jogador2, Cadastro& cadastro) override;
    /**
     * @brief Verifica se há uma sequência de 4 peças consecutivas.
     * 
     * Analisa a posição especificada no tabuleiro para determinar se há uma
     * sequência de 4 peças consecutivas em qualquer direção (horizontal,
     * vertical ou diagonal), indicando uma vitória.
     * 
     * @param linha Linha da última jogada.
     * @param coluna Coluna da última jogada.
     * @return true Se há uma sequência de 4 peças consecutivas.
     * @return false Caso contrário.
     */
    bool verifica4(int linha, int coluna);
    /**
     * @brief Verifica se o jogo chegou ao fim após a última jogada.
     * 
     * Esta função é chamada após cada jogada para determinar se a partida terminou. 
     * A função verifica se a última peça colocada resultou em uma sequência de 4 peças consecutivas, 
     * declarando vitória para o jogador correspondente. Além disso, verifica se o tabuleiro está cheio, 
     * indicando um empate caso nenhuma outra jogada possa ser feita.
     * 
     * @param col Coluna onde a última peça foi jogada.
     * @param jogador1 Nome do primeiro jogador (associado às peças pretas).
     * @param jogador2 Nome do segundo jogador (associado às peças brancas).
     * @param cadastro Referência para o objeto Cadastro, utilizado para registrar o resultado do jogo.
     * @return int Retorna 0 para indicar o fim do jogo, seja por vitória ou empate.
     */
    int verificaFimDeJogo (int coluna, std::string jogador1, std::string jogador2, Cadastro& cadastro);

private:
    /**
     * @brief Verifica se uma jogada é válida na coluna especificada.
     * 
     * Checa se a coluna escolhida está disponível para receber uma nova peça,
     * ou seja, se não está cheia.
     * 
     * @param col Coluna onde o jogador deseja fazer a jogada.
     * @return true Se a jogada é permitida.
     * @return false Caso contrário.
     */ 
    bool jogadaPermitida(int col);
    /**
     * @brief Realiza a jogada na coluna especificada.
     * 
     * Insere a peça na coluna escolhida, atualizando o estado do tabuleiro e
     * preparando-o para a próxima verificação de vitória.
     * 
     * @param col Coluna onde a jogada será feita.
     */
    void novaJogada(int col);
    /**
     * @brief Exibe de quem é o turno atual.
     * 
     * Informa qual jogador deve realizar a próxima jogada, alternando entre
     * os dois jogadores.
     * 
     * @param jogador1 Nome do primeiro jogador.
     * @param jogador2 Nome do segundo jogador.
     */
    void anunciaTurno(std::string jogador1, std::string jogador2) override;
};

#endif
