#include "tabuleiro.hpp"
#include <iostream>

Tabuleiro::Tabuleiro(){

}

void Tabuleiro::inicializaTabuleiro(char jogo){
    if (jogo == 'R') {
        tabuleiro.resize(8, std::vector<Casa>(8));
        for (int i = 0; i< 8; i++) {
            for (int j = 0; j < 8; j++){
                tabuleiro[i][j].estado = "NULO";
            }
        }
        tabuleiro[4 - 1][4 - 1].estado = "BRANCO";
        tabuleiro[4 - 1][5 - 1].estado = "PRETO";
        tabuleiro[5 - 1][4 - 1].estado = "PRETO";
        tabuleiro[5 - 1][5 - 1].estado = "BRANCO";
    } else  
    if (jogo == 'L'){
        tabuleiro.resize(6, std::vector<Casa>(7));
        for (int i = 0; i< 6; i++) {
            for (int j = 0; j < 7; j++){
                tabuleiro[i][j].estado = "NULO";
            }
        }
    } else
    if (jogo == 'D'){
        tabuleiro.resize(8, std::vector<Casa>(8));
        for (int i = 0; i< 8; i++) {
            for (int j = 0; j < 8; j++){
                if ((i + j) % 2 == 0) {
                    if (i < 3) {
                        tabuleiro[i][j].estado = "PRETO"; // Peças pretas nas duas primeiras linhas
                    } else if (i > 4) {
                        tabuleiro[i][j].estado = "BRANCO"; // Peças brancas nas duas últimas linhas
                    } else {
                        tabuleiro[i][j].estado = "NULO";
                    }
                } else {
                    tabuleiro[i][j].estado = "NULO";
                }
            }
        }
    }
}

void Tabuleiro::imprimeTabuleiro() const {
    for (std::size_t i=0; i < tabuleiro.size(); i++) {
        for (std::size_t j=0; j < tabuleiro[i].size(); j++) {
            std::cout << "|";
            if(tabuleiro[i][j].estado == "NULO"){
                std::cout << " ";
            } else
            if(tabuleiro[i][j].estado == "PRETO"){
                std::cout << "X";
            } else
            if(tabuleiro[i][j].estado == "BRANCO"){
                std::cout << "O";
            }
        }
        std::cout << "|" << std::endl;
    }
}

bool Tabuleiro::verificaCasa(int linha, int coluna, std::string _estado) const{
    if(tabuleiro[linha][coluna].estado == _estado){
        return true;
    } else{
        return false;
    }
}

void Tabuleiro::modificaTabuleiro(int linha, int coluna, std::string _estado){
    tabuleiro[linha][coluna].estado = _estado;
}