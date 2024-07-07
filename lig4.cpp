#include "lig4.hpp"
#include <iostream>

Lig4::Lig4() {
    tabuleiro.inicializaTabuleiro('L');
}

void Lig4::start() {
    //
}

bool Lig4::escolheJogada(int col) {
    if (jogadaPermitida(col)) {
            novaJogada(col);
            return true;
    }
    return false;
}

bool Lig4::fimDeJogo() const {
    //
    return false;
}

void Lig4::printTabuleiro() const {
    tabuleiro.imprimeTabuleiro();
}

bool Lig4::jogadaPermitida(int col) const{
    //
    return true;
}

void Lig4::novaJogada(int col) const {
    //
}