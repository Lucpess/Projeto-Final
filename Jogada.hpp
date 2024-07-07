#ifndef JOGADA_HPP
#define JOGADA_HPP

#include "tabuleiro.hpp"

class Jogada {
public:
virtual void start() = 0;
    virtual bool escolheJogada (int linha, int col) = 0;
    virtual bool fimDeJogo () const = 0;
    virtual void printTabuleiro () const = 0;
}; 

#endif 