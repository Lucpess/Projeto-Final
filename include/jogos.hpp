#ifndef JOGOS_HPP
#define JOGOS_HPP

#include "tabuleiro.hpp"
#include "cadastro.hpp"

class Jogos {
    public:
    Jogos(char jogo);
    virtual ~Jogos();

    virtual void start(std::string jogador1, std::string jogador2, Cadastro& cadastro) = 0;
    void printTabuleiro() const;

    protected:
    bool fimDeJogo;
    Tabuleiro tabuleiro;
    std::string turno;

    void mudaTurno();
    virtual void anunciaTurno(std::string jogador1, std::string jogador2) = 0;
};

#endif