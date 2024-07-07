#include "reversi.hpp"

Reversi::Reversi() {
    tabuleiro.inicializaTabuleiro('R');
}

void Reversi::start(){
    //
}

bool Reversi::escolheJogada(int linha, int col) {
    if(jogadaPermitida(linha, col)) {
        viraPeca(linha, col);
        return true;
    }
    return false;
}

bool Reversi::fimDeJogo() const {
    //
    return false;
}

void Reversi::printTabuleiro() const {
    tabuleiro.imprimeTabuleiro();
}

bool Reversi::jogadaPermitida(int linha, int col) const {
    //
    return true;
}

void Reversi::viraPeca(int linha, int col){
    //
}