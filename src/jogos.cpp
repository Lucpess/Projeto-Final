#include "jogos.hpp"
#include <iostream>

Jogos::Jogos(char jogo){
    tabuleiro.inicializaTabuleiro(jogo);
    fimDeJogo = false;
}

Jogos::~Jogos(){
    
}

void Jogos::printTabuleiro() const{
    tabuleiro.imprimeTabuleiro();
}

void Jogos::mudaTurno(){
    turno = (turno == "PRETO") ? "BRANCO" : "PRETO";
}



