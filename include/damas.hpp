/**
 * @file damas.hpp
 * @brief Definição da classe Damas que representa o jogo de Damas.
 * 
 * Este arquivo contém a declaração da classe `Damas`, que herda da classe `Jogos` e
 * implementa a lógica específica para o jogo de Damas, incluindo métodos para
 * movimentar peças, verificar jogadas válidas, e determinar o vencedor.
 */

#ifndef DAMAS_HPP
#define DAMAS_HPP

#include "jogos.hpp"

/**
 * @class Damas
 * @brief Representa o jogo de Damas.
 * 
 * A classe `Damas` herda de `Jogos` e implementa a lógica específica do jogo de Damas.
 * Inclui métodos para inicializar o jogo, gerenciar os turnos dos jogadores, movimentar
 * peças, verificar jogadas válidas e determinar se houve uma vitória.
 */
class Damas : public Jogos {
public:
    /**
     * @brief Construtor da classe Damas.
     * 
     * Inicializa o jogo de Damas, definindo o turno inicial como "BRANCO" e configurando
     * o tabuleiro para o início do jogo.
     */
    Damas();

    /**
     * @brief Destrutor da classe Damas.
     * 
     * Realiza a limpeza necessária ao finalizar um jogo de Damas.
     */
    ~Damas();

    /**
     * @brief Inicia o jogo de Damas entre dois jogadores.
     * 
     * Este método controla o fluxo do jogo, alternando entre os turnos dos jogadores
     * até que haja um vencedor ou que o jogo seja encerrado. Se houver capturas obrigatórias,
     * realiza-as automaticamente. Permite também que o usuário saia do jogo.
     * 
     * @param jogador1 Nome do primeiro jogador.
     * @param jogador2 Nome do segundo jogador.
     * @param cadastro Referência ao objeto Cadastro para registrar o resultado do jogo.
     */
    void start(std::string jogador1, std::string jogador2, Cadastro& cadastro) override;

private:
    /**
     * @brief Anuncia o turno atual do jogador.
     * 
     * Exibe uma mensagem indicando de quem é o turno e solicita a entrada de uma jogada
     * ou o comando para sair do jogo.
     * 
     * @param jogador1 Nome do primeiro jogador.
     * @param jogador2 Nome do segundo jogador.
     */
    void anunciaTurno(std::string jogador1, std::string jogador2) override;

    /**
     * @brief Movimenta uma peça no tabuleiro.
     * 
     * Move uma peça da posição de origem para a posição de destino, se a jogada for válida.
     * Se o movimento for uma captura, a peça adversária é removida do tabuleiro.
     * 
     * @param linhaOrigem Linha de origem da peça.
     * @param colunaOrigem Coluna de origem da peça.
     * @param linhaDestino Linha de destino da peça.
     * @param colunaDestino Coluna de destino da peça.
     * @return true Se a peça foi movida com sucesso.
     * @return false Se a jogada foi inválida.
     */
    bool movimentaPeca(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

    /**
     * @brief Verifica se uma jogada é válida.
     * 
     * Determina se a jogada solicitada é permitida de acordo com as regras do jogo de Damas.
     * Inclui verificações para movimentos simples e capturas.
     * 
     * @param linhaOrigem Linha de origem da peça.
     * @param colunaOrigem Coluna de origem da peça.
     * @param linhaDestino Linha de destino da peça.
     * @param colunaDestino Coluna de destino da peça.
     * @return true Se a jogada é válida.
     * @return false Se a jogada é inválida.
     */
    bool verificaJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

    /**
     * @brief Verifica se o jogo terminou com uma vitória.
     * 
     * Analisa o tabuleiro para determinar se restam peças de apenas um jogador, o que
     * indica que o jogo terminou com a vitória do outro jogador.
     * 
     * @return true Se houve uma vitória.
     * @return false Se o jogo ainda não terminou.
     */
    bool verificaVitoria();

    /**
     * @brief Verifica se há capturas obrigatórias disponíveis.
     * 
     * Examina o tabuleiro para verificar se o jogador atual tem capturas obrigatórias
     * que devem ser realizadas antes de qualquer outro movimento.
     * 
     * @return true Se há capturas disponíveis.
     * @return false Se não há capturas disponíveis.
     */
    bool temCapturaDisponivel();

    /**
     * @brief Verifica se uma peça pode capturar outra.
     * 
     * Determina se uma peça pode capturar uma peça adversária com base na posição
     * atual e na posição da peça adversária.
     * 
     * @param linhaOrigem Linha de origem da peça que tenta capturar.
     * @param colunaOrigem Coluna de origem da peça que tenta capturar.
     * @param pecaAdversario String que representa a peça do adversário.
     * @return true Se a captura é possível.
     * @return false Se a captura não é possível.
     */
    bool podeCapturar(int linhaOrigem, int colunaOrigem, std::string pecaAdversario);

    /**
     * @brief Realiza as capturas obrigatórias no tabuleiro.
     * 
     * Executa automaticamente quaisquer capturas obrigatórias disponíveis para o
     * jogador atual, continuando até que não haja mais capturas disponíveis. Se não houver
     * capturas, o turno é alternado para o próximo jogador.
     */
    void realizaCapturaObrigatoria();

    /**
     * @brief Realiza uma captura de uma peça adversária.
     * 
     * Move a peça da posição de origem para a posição de destino, removendo a peça
     * adversária capturada do tabuleiro.
     * 
     * @param linhaOrigem Linha de origem da peça que realiza a captura.
     * @param colunaOrigem Coluna de origem da peça que realiza a captura.
     * @param pecaAdversario String que representa a peça do adversário a ser capturada.
     */
    void realizaCaptura(int linhaOrigem, int colunaOrigem, std::string pecaAdversario);
};

#endif // DAMAS_HPP
