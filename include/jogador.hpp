/**
 * @file jogador.hpp
 * @brief Declaração da classe Jogador para gerenciar informações e estatísticas dos jogadores.
 */

#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <iostream>

/**
 * @class Jogador
 * @brief Classe que representa um jogador e suas estatísticas em diferentes jogos.
 */
class Jogador {
    private:
        /**
         * @brief Apelido do jogador.
         */
        std::string apelido;
        
        /**
         * @brief Nome completo do jogador.
         */
        std::string nome;
        
        /**
         * @brief Número de vitórias em partidas de Reversi.
         */
        int vitoriasReversi;
        
        /**
         * @brief Número de derrotas em partidas de Reversi.
         */
        int derrotasReversi;
        
        /**
         * @brief Número de vitórias em partidas de Lig4.
         */
        int vitoriasLig4;
        
        /**
         * @brief Número de derrotas em partidas de Lig4.
         */
        int derrotasLig4;
        
        /**
         * @brief Número de vitórias em partidas de Dama.
         */
        int vitoriasDama;  
        
        /**
         * @brief Número de derrotas em partidas de Dama.
         */
        int derrotasDama;

    public:
        /**
         * @brief Obtém o apelido do jogador.
         * @return O apelido do jogador.
         */
        std::string getApelido() const; 
        
        /**
         * @brief Obtém o nome completo do jogador.
         * @return O nome completo do jogador.
         */
        std::string getNome() const; 
        
        /**
         * @brief Obtém o número de vitórias em partidas de Reversi.
         * @return O número de vitórias em Reversi.
         */
        int getVitoriasReversi() const;
        
        /**
         * @brief Obtém o número de derrotas em partidas de Reversi.
         * @return O número de derrotas em Reversi.
         */
        int getDerrotasReversi() const;
        
        /**
         * @brief Obtém o número de vitórias em partidas de Lig4.
         * @return O número de vitórias em Lig4.
         */
        int getVitoriasLig4() const;
        
        /**
         * @brief Obtém o número de derrotas em partidas de Lig4.
         * @return O número de derrotas em Lig4.
         */
        int getDerrotasLig4() const;
        
        /**
         * @brief Obtém o número de vitórias em partidas de Dama.
         * @return O número de vitórias em Dama.
         */
        int getVitoriasDama() const; 
        
        /**
         * @brief Obtém o número de derrotas em partidas de Dama.
         * @return O número de derrotas em Dama.
         */
        int getDerrotasDama() const; 
        
        /**
         * @brief Exibe os resultados do jogador.
         */
        void printResultados() const; 
        
        /**
         * @brief Define o apelido do jogador.
         * @param apelido Novo apelido do jogador.
         */
        void setApelido(const std::string& apelido);
        
        /**
         * @brief Incrementa o número de vitórias em partidas de Reversi.
         */
        void addVitoriaReversi();
        
        /**
         * @brief Incrementa o número de derrotas em partidas de Reversi.
         */
        void addDerrotaReversi();
        
        /**
         * @brief Incrementa o número de vitórias em partidas de Lig4.
         */
        void addVitoriaLig4();
        
        /**
         * @brief Incrementa o número de derrotas em partidas de Lig4.
         */
        void addDerrotaLig4();
        
        /**
         * @brief Incrementa o número de vitórias em partidas de Dama.
         */
        void addVitoriaDama(); 
        
        /**
         * @brief Incrementa o número de derrotas em partidas de Dama.
         */
        void addDerrotaDama(); 
        
        /**
         * @brief Construtor padrão da classe Jogador.
         */
        Jogador();
        
        /**
         * @brief Construtor da classe Jogador com parâmetros para inicialização.
         * @param apelido Apelido do jogador.
         * @param nome Nome completo do jogador.
         * @param vitoriasR Número de vitórias em Reversi.
         * @param derrotasR Número de derrotas em Reversi.
         * @param vitoriasL Número de vitórias em Lig4.
         * @param derrotasL Número de derrotas em Lig4.
         * @param vitoriasD Número de vitórias em Dama.
         * @param derrotasD Número de derrotas em Dama.
         */
        Jogador(const std::string& apelido, const std::string& nome, 
                int vitoriasR = 0, int derrotasR = 0, int vitoriasL = 0, int derrotasL = 0, int vitoriasD = 0, int derrotasD = 0);
}; 

#endif // JOGADOR_HPP
