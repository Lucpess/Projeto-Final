#ifndef JOGADA_HPP
#define JOGADA_HPP

#include "tabuleiro.hpp"

class Jogada {
public:
    virtual void start();
    virtual bool escolheJogada ();
    virtual bool fimDeJogo ();
    virtual void printTabuleiro ();
};

#endif 