#include <iostream>
#include "reversi.hpp"
#include <limits>
#include <vector>

using namespace std;

Reversi::Reversi() {
    tabuleiro.inicializaTabuleiro('R');
    fimDeJogo = false;
}

void Reversi::printTabuleiro() const {
    tabuleiro.imprimeTabuleiro();
}

void Reversi::anunciaTurno(std::string jogador1, std::string jogador2){
    if(turno == "PRETO"){
        std::cout << "TURNO DE " << jogador1 << std::endl << "-DIGITE O NÚMERO DA LINHA E COLUNA, RESPECTIVAMENTE, PARA JOGAR-";
    } else{
        std::cout << "TURNO DE " << jogador2 << std::endl << "-DIGITE O NÚMERO DA LINHA E COLUNA, RESPECTIVAMENTE, PARA JOGAR-";
    }
}

std::string Reversi::corOposta() {
    if("PRETO" == turno) {
        return "BRANCO";
    } else {
        return "PRETO";
    }
    return "NULO";
}

bool Reversi::posicaoPermitida(int i, int j, std::string turno) {
    if (confereColuna(i, j, turno))
        return true;
    if (confereLinha(i, j, turno))
        return true;
    if (confereDiagonal(i, j, turno))
        return true;
    else return false;
}

bool Reversi::jogadaPermitida(int linha, int col) const {
    if (tabuleiro.verificaCasa(linha, col, "NULO"))
    return true;
}

bool Reversi::confereColuna(int i, int j, std::string turno) {
    if (tabuleiro.verificaCasa(i, j, "NULO")) {
        if ( i >= 2) { // confere coluna para cima
            if (tabuleiro.verificaCasa(i-1, j, corOposta())) {
                for ( int x = i - 2; x >= 0 ; --x) {
                    if(tabuleiro.verificaCasa(x, j, corOposta()))
                        continue;

                    if(tabuleiro.verificaCasa(x, j, turno)) 
                        return true;

                    if (tabuleiro.verificaCasa(x, j, "NULO")) 
                        break;
                }
            } 
        }
        if (i <= 5) { // confere coluna para baixo
            if (tabuleiro.verificaCasa(i+1, j, corOposta())) {
                for ( int x = i+2; x < 8; ++x) {
                    if (tabuleiro.verificaCasa(x, j, corOposta())) 
                        continue;

                    if(tabuleiro.verificaCasa(x, j, turno))
                        return true;

                    if (tabuleiro.verificaCasa(x, j, "NULO"))
                        break;
                }
            }
        }
    }
    return false;
}

bool Reversi::confereLinha(int i, int j, std::string turno) {
    if (tabuleiro.verificaCasa(i, j, "NULO")) {
        if (j >=2) {// confere linha p esquerda
            if (tabuleiro.verificaCasa(i, j - 1, corOposta())) {
                for(int y = j - 2; y>=0; --y) {
                    if(tabuleiro.verificaCasa(i, y, corOposta()))
                        continue;
                    if(tabuleiro.verificaCasa(i, y, turno))
                        return true;
                    if(tabuleiro.verificaCasa(i, y, "NULO"))
                        break;
                }
            }
        }
        if (j <= 5) {// confere linha p direita
            if(tabuleiro.verificaCasa(i, j+1, corOposta())) {
                for (int y = j+2; y < 8; ++y) {
                    if(tabuleiro.verificaCasa(i, y, corOposta()))
                        continue;
                    if(tabuleiro.verificaCasa(i, y, turno))
                        return true;
                    if(tabuleiro.verificaCasa(i, y, "NULO"))
                        break;
                }            
            }
        }
    }
    return false;
} 

bool Reversi::confereDiagonal(int i, int j, std::string turno) {
    if (tabuleiro.verificaCasa( i, j, "NULO")) {
        if (i >= 2 && j >= 2 ) { // confere diagonal p/ esquerda e p/ cima
            if (tabuleiro.verificaCasa(i-1, j-1, corOposta())) {
                for (int x = i-2, y = j-2; x >=0 && y>=0; --x, --y ) {
                    if (tabuleiro.verificaCasa(x, y, corOposta()))
                        continue;

                    if(tabuleiro.verificaCasa(x, y, turno))
                        return true;

                    if(tabuleiro.verificaCasa(x, y, "NULO"))
                        break;
                }
            }
        }
        if (i <=5 && j >= 2) { // confere diagonal p/ esquerda e p/ baixo
            if (tabuleiro.verificaCasa(i+1, j-1, corOposta())) {
                for (int x = i+2, y = j-2; x < 8 && y >=0; ++x, ++y) {
                    if (tabuleiro.verificaCasa(x, y, corOposta()))
                        continue;

                    if (tabuleiro.verificaCasa(x, y, turno))
                        return true;

                    if (tabuleiro.verificaCasa(x, y, "NULO"))
                        break;
                }
            }
        }
        if (i >=2 && j <= 5) { // confere diagonal p/ direita e p/ cima
            if(tabuleiro.verificaCasa(i-1, j+1, corOposta())) {
                for (int x = i-2, y = j+2; x >= 0 && y < 8; --x, ++y) {
                    if(tabuleiro.verificaCasa(x, y, corOposta()))
                        continue;

                    if(tabuleiro.verificaCasa(x, y, turno))
                        return true;

                    if(tabuleiro.verificaCasa(x, y, "NULO"))
                        break;
                }
            }
        }
        if(i <=5 && j <=5) {// confere diagonal p/ direita e p/ baixo
            if(tabuleiro.verificaCasa(i+1, j+1, "NULO")) {
                for(int x = i+2, y = j+2; x < 8 && y < 8; ++x, ++y) {
                    if (tabuleiro.verificaCasa(x, y, corOposta()))
                        continue;

                    if(tabuleiro.verificaCasa(x, y, turno))
                        return true;

                    if(tabuleiro.verificaCasa(x, y, "NULO"))
                        break;
                }
            }
        }
    }
    return false;
}

void Reversi::jogadasValidas() {
    jogadasLinha.clear();
    jogadasColuna.clear();

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(posicaoPermitida(i, j, turno)) {
            jogadasLinha.push_back(i);
            jogadasColuna.push_back(j);
            std::cout << "[" << i << "," << j << "]" << std::endl;
            }
        }
    }
}
vector<vector<string>> Reversi::viraPecasVertical(int i, int j, string turno){
    int x;

    if(i >= 2) {//vira as peças na vertical pra cima
        if(tabuleiro.verificaCasa(i-1, j, corOposta())) {
            for(x = i-2; x>= 0; --x) {
                if (tabuleiro.verificaCasa(x, j, corOposta()))
                continue;

                if (tabuleiro.verificaCasa(x, j, turno)){
                    for (int k= i-1; k>x; --k)
                    tabuleiro.modificaTabuleiro(k, j, turno);
                    break;
                }

                if (tabuleiro.verificaCasa(x, j, "NULO"))
                break;
            }
        }
    }
    if (i <= 5) {//vira as peças na vertical p/ baixo
        if(tabuleiro.verificaCasa(i+1, j, corOposta())) {
            for(x = i+2; x<8;++x) {
                if(tabuleiro.verificaCasa(x, j, corOposta()))
                    continue;

                if (tabuleiro.verificaCasa(x, j, turno)) {
                    for(int k = i+1; k<x; ++k)
                    tabuleiro.modificaTabuleiro(k, j, turno);
                    break;
                }

                if (tabuleiro.verificaCasa(x,j, "NULO"))
                    break;
            }
        }
    }
    printTabuleiro();
}

vector<vector<string>> Reversi::viraPecasHorizontal(int i, int j, string turno) {
    int y;

    if(j >= 2) {//vira as peças na horizontal p/ esquerda
       if (tabuleiro.verificaCasa(i, j-1, corOposta())) {
            for( y = j-2; y >=0; --y) {
                if (tabuleiro.verificaCasa(i, y, corOposta())) 
                    continue;

                if (tabuleiro.verificaCasa(i, y, turno)) {
                    for (int k = j-1; k > y; --k)
                        tabuleiro.modificaTabuleiro(i, k, turno);
                        break;
                }

                if (tabuleiro.verificaCasa(i, y, "NULO"))
                    break;
            }
        }
    }
    if(j <=5) {
        if (tabuleiro.verificaCasa(i, j+1, corOposta())) {
            for(y = j+2; y < 8; ++y) {
                if (tabuleiro.verificaCasa(i, y, corOposta()))
                    continue;

                if (tabuleiro.verificaCasa(i, y, turno)) {
                    for (int k = j+1; k<y; ++k)
                        tabuleiro.modificaTabuleiro(i, k, turno);
                        break;
                }
                if (tabuleiro.verificaCasa(i, y, "NULO"))
                    break;
            }
        }
    }
    printTabuleiro();
}

vector<vector<string>> Reversi::viraPecasDiagonal(int i, int j, string turno) {
    int x, y;

    if (i >= 2 && j >= 2) {//vira as peças em cima e para a esq.
        if (tabuleiro.verificaCasa(i-1, j-1, corOposta())) {
            for (x=i-2,y=j-2;x>=0 && y>=0;--x,--y) {
                if (tabuleiro.verificaCasa(x, y, corOposta()))
                    continue;

                if (tabuleiro.verificaCasa(x, y, turno)) {
                    for(int k=i - 1, l=j - 1;k>x && l>y;--k,--l)
                        tabuleiro.modificaTabuleiro(k, l, turno);
                        break;
                }
                if (tabuleiro.verificaCasa(x, y, "NULO"))
                    break;
            }
        }
    }
    if(i <=5 && j >= 2) {//vira as peças em baixo e para a esq.
        if(tabuleiro.verificaCasa(i+1, j-1, corOposta())) {
            for(x=i+2, y=j-2; x<8 && y >=0;++x,--y) {
                if (tabuleiro.verificaCasa(x, y, corOposta()))
                    continue;

                if (tabuleiro.verificaCasa(x, y, turno)) {
                    for(int k=i+1, l=j-1; k<x && l>y; ++k,--l)
                        tabuleiro.modificaTabuleiro(k, l, turno);
                        break;
                }
                if (tabuleiro.verificaCasa(x, y, "NULO"))
                    break;
            }
        }
    }
    if(i >=2 && j <= 5) {//vira as peças em cima e para a direita
        if(tabuleiro.verificaCasa(i-1,j+1, corOposta())) {
            for(x = i-2, y=j+2; x>=0 && y <= 7; --x, ++y) {
                if(tabuleiro.verificaCasa(x, y, corOposta()))
                    continue;
                if(tabuleiro.verificaCasa(x,y,turno)) {
                    for(int k= i-1, l= j+1;k>x && l<y;--k,++l)
                    tabuleiro.modificaTabuleiro(k, l, turno);
                    break; 
                }
                if(tabuleiro.verificaCasa(x, y, "NULO"))
                    break;
            }
        }
    }
    if( i<=5 && j<=5) {//vira as peças em baixo e para a direita
        if(tabuleiro.verificaCasa(i+1, j+1, corOposta())){
            for(x=i+2,y=j+2;x<8 && y<8; ++x,++y) {
                if(tabuleiro.verificaCasa(x, y, corOposta()))
                    continue;
                if(tabuleiro.verificaCasa(x, y, turno)) {
                    for(int k=i+1,l=j+1; k<x && l<y;++k,++l)
                    tabuleiro.modificaTabuleiro(k, l, turno);
                    break;
                }
                if(tabuleiro.verificaCasa(x, y, "NULO"))
                    break;
            }
        }
    }
    printTabuleiro();
}

bool Reversi::verificaFimDeJogo() const {

    bool tabuleiroCheio = true;
    int pecasBrancas, pecasPretas;
    contarPecas(pecasBrancas, pecasPretas);
    int totalPecas = pecasBrancas + pecasPretas;

    while(tabuleiroCheio) {

        if (totalPecas < 64 ) {
            tabuleiroCheio = false;
            break;
        } else if (pecasBrancas > pecasPretas) {
            std::cout << "BRANCAS VENCERAM!" << std::endl;
        } else if (pecasPretas > pecasBrancas) {
            std::cout << "PRETAS VENCERAM!" << std::endl;
        } else {
            std::cout << "EMPATE. TABULEIRO CHEIO!" << std::endl;
        }
        return true;
    }

    if(tabuleiroCheio) { 
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
    else { 
        if (pecasBrancas == 0) {
            std::cout << "AS BRANCAS NÃO TEM MAIS PEÇAS.PRETAS VENCERAM!" << std::endl;
        }
        else if (pecasPretas == 0) {
            std::cout << "AS PRETAS NÃO TEM MAIS PEÇAS.BRANCAS VENCERAM!" << std::endl;
        }
        return true;
    }
    return false;
}

void Reversi::mudaTurno(){
    if(turno == "PRETO"){
        turno = "BRANCO";
    } else{
        turno = "PRETO";
    }
}

void Reversi::contarPecas(int& brancas, int& pretas) const{
    brancas = 0;
    pretas = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if (casa.estado == "BRANCO") {
                brancas++;
            } else if (casa.estado == "PRETO") {
                pretas++;
            }
        }
    }
}

void Reversi::start(std::string jogador1, std::string jogador2) {
    turno = "PRETO";
    printTabuleiro();
    std::cout << jogador1 << " == X | " << jogador2 << " == O" << std::endl;
    while(!fimDeJogo){
        int linha;
        int coluna;
        while (true) {
                anunciaTurno(jogador1, jogador2);
                if (!(std::cin >> linha >> coluna)) {
                    std::cout << "Formato da jogada incorreto. Por favor, insira coordenadas válidas." << std::endl;
                    std::cin.clear();  // Limpa o estado de erro
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descarta entrada inválida
                } 
                else if (!jogadaPermitida(linha, coluna) || coluna < 0 || coluna > 7 || linha < 0 || linha > 7 ) {
                   std::cout << "Jogada inválida. Por favor, escolha coordenadas válidas." << std::endl;
                } 
                 else {
                    break;  // Sai do loop se a entrada for válida
                }
        }
        posicaoPermitida(linha, coluna, turno);
        tabuleiro.modificaTabuleiro(linha, coluna, turno);
        viraPecasVertical(linha, coluna, turno);
        viraPecasHorizontal(linha, coluna, turno);
        viraPecasDiagonal(linha, coluna, turno);
        verificaFimDeJogo();
        mudaTurno();
    } 
}