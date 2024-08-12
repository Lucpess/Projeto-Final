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

bool Reversi::verificafimDeJogo() const {

    bool tabuleiroCheio = true;
    for(int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
        if(tabuleiro.verificaCasa(i, j, "NULO")){
            tabuleiroCheio = false;
            break;
        }
        } if (!tabuleiroCheio) break;
    }

    if(tabuleiroCheio) {
        int pecasBrancas, pecasPretas;
        tabuleiro.contarPecas(pecasBrancas, pecasPretas); 
        if (pecasBrancas > pecasPretas) {
            std::cout << "BRANCAS VENCERAM!" << std::endl;
        }
        else if (pecasPretas > pecasBrancas) {
            std::cout << "PRETAS VENCERAM!" << std::endl;
        }
        else {
            std::cout << "EMPATE. TABULEIRO CHEIO!" << std::endl;
        }
        return true;
    }
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