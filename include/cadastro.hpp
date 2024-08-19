/**
 * @file cadastro.hpp
 * @brief Declaração da classe Cadastro para gerenciar jogadores e seus resultados.
 */

#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "jogador.hpp"
#include <string>
#include <iostream>
#include <map>
#include <vector>

/**
 * @class Cadastro
 * @brief Classe responsável pelo cadastro e gerenciamento de jogadores e seus resultados.
 */
class Cadastro {
    private:
        /**
         * @brief Mapa que armazena os jogadores cadastrados, usando o apelido como chave.
         */
        std::map<std::string, Jogador> jogadores;

        /**
         * @brief Salva os dados do cadastro de jogadores em um arquivo.
         */
        void salvarCadastro();

        /**
         * @brief Atualiza o cadastro de jogadores carregando os dados do arquivo.
         */
        void atualizarCadastro();
        
    public:
        /**
         * @brief Construtor da classe Cadastro.
         */
        Cadastro();

        /**
         * @brief Destrutor da classe Cadastro.
         */
        ~Cadastro();

        /**
         * @brief Cadastra um novo jogador.
         * @param apelido Apelido do jogador.
         * @param nome Nome completo do jogador.
         */
        void cadastraJogador(const std::string& apelido, const std::string& nome);

        /**
         * @brief Lista todos os jogadores cadastrados.
         * @param ordem Especifica a ordem de listagem: "A" para ordenar por apelido, "N" para ordenar por nome.
         */
        void listaJogadores(const std::string& ordem) const;

        /**
         * @brief Remove um jogador do cadastro.
         * @param apelido Apelido do jogador a ser removido.
         */
        void removeJogador(const std::string& apelido);

        /**
         * @brief Registra o resultado de uma partida entre dois jogadores.
         * @param vencedor Apelido do jogador vencedor.
         * @param perdedor Apelido do jogador perdedor.
         * @param jogo Identificador do jogo: 'R' para Reversi, 'L' para Lig4, 'D' para Dama.
         */
        void registrarResultado(const std::string& vencedor, const std::string& perdedor, char jogo);

        /**
         * @brief Verifica se um jogador com determinado apelido está cadastrado.
         * @param apelido Apelido do jogador a ser verificado.
         * @return true se o jogador existir, false caso contrário.
         */
        bool existeJogador(const std::string& apelido) const;
};

#endif // CADASTRO_HPP
