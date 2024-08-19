#include "lig4.hpp"
#include <iostream>
#include <limits>

Lig4::Lig4() : Jogos('L'){
}

Lig4::~Lig4(){
}

void Lig4::anunciaTurno(std::string jogador1, std::string jogador2){
    if(turno == "PRETO"){
        std::cout << "-TURNO DE " << jogador1 << " (X)-" << std::endl << "-DIGITE O NUMERO DA COLUNA PARA JOGAR-" << std::endl;
    } else{
        std::cout << "-TURNO DE " << jogador2 << " (O)-"<< std::endl << "-DIGITE O NUMERO DA COLUNA PARA JOGAR-" << std::endl;
    }
    std::cout << "-> ";
}

bool Lig4::jogadaPermitida(int col){
    return tabuleiro.verificaCasa(0, col, "NULO");
}

void Lig4::novaJogada(int col){
    int linhaPraMudar = -1;
    for(int i = 5; i>=0; i--){
        if(tabuleiro.verificaCasa(i, col, "NULO")){
            linhaPraMudar = i;
            break;
        }
    }
    tabuleiro.modificaTabuleiro(linhaPraMudar, col, turno);
}

bool Lig4::verifica4(int linha, int col) {
  const int LINHAS = 6;
  const int COLUNAS = 7;
  std::string peca = turno;

  // Verifica horizontal
  int count = 0;
  for (int j = 0; j < COLUNAS; j++) {
    if (tabuleiro.verificaCasa(linha, j, peca)) {
      count++;
      if (count == 4)
        return true;
    } else {
      count = 0;
    }
  }

  // Verifica vertical
  count = 0;
  for (int i = 0; i < LINHAS; i++) {
    if (tabuleiro.verificaCasa(i, col, peca)) {
      count++;
      if (count == 4)
        return true;
    } else {
      count = 0;
    }
  }

  // Verifica diagonal (\)
  count = 0;
  for (int i = -3; i <= 3; i++) {
    int l = linha + i;
    int c = col + i;
    if (l >= 0 && l < LINHAS && c >= 0 && c < COLUNAS) {
      if (tabuleiro.verificaCasa(l, c, peca)) {
        count++;
        if (count == 4)
          return true;
      } else {
        count = 0;
      }
    }
  }

  // Verifica diagonal (/)
  count = 0;
  for (int i = -3; i <= 3; i++) {
    int l = linha - i;
    int c = col + i;
    if (l >= 0 && l < LINHAS && c >= 0 && c < COLUNAS) {
      if (tabuleiro.verificaCasa(l, c, peca)) {
        count++;
        if (count == 4)
          return true;
      } else {
        count = 0;
      }
    }
  }

  return false;
}

int Lig4::verificaFimDeJogo(int col, std::string jogador1, std::string jogador2, Cadastro& cadastro) {
    
    int linhaColocada = -1;
    for(int i = 0; i<6; i++){
        if(!tabuleiro.verificaCasa(i, col, "NULO")){
            linhaColocada = i;
            break;
        }
    }
    
    if(verifica4(linhaColocada, col)){
        fimDeJogo = true;
        if(turno == "PRETO"){
            std::cout << "** " << jogador1 << " VENCEU **" << std::endl;
            cadastro.registrarResultado(jogador1, jogador2, 'L');
        } else{
            std::cout << "** " << jogador2 << " VENCEU **" << std::endl;
            cadastro.registrarResultado(jogador2, jogador1, 'L');
        }
        return 0;
    }

    bool tabuleiroCheio = true;
    for(int i = 0; i<7; i++){
        if(tabuleiro.verificaCasa(0, i, "NULO")){
            tabuleiroCheio = false;
            break;
        }
    }
    if(tabuleiroCheio){
        fimDeJogo = true;
        std::cout << "EMPATE :/, TABULEIRO CHEIO" << std::endl;
    }
    return 0;
}

void Lig4::start(std::string jogador1, std::string jogador2, Cadastro& cadastro) {
    turno = "PRETO";
    printTabuleiro();
    while(!fimDeJogo){
        int coluna;
        while (true) {
                anunciaTurno(jogador1, jogador2);
                if (!(std::cin >> coluna)) {
                    std::cout << "Entrada invalida. Por favor, insira um numero valido." << std::endl;
                    std::cin.clear();  // Limpa o estado de erro
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descarta entrada inválida
                } else if (coluna < 1 || coluna > 7 || !jogadaPermitida(coluna - 1)) {
                    std::cout << "Coluna invalida. Por favor, escolha uma coluna valida." << std::endl;
                } else {
                    break;
                }
        }
        novaJogada(coluna - 1);
        printTabuleiro();
        verificaFimDeJogo(coluna - 1, jogador1, jogador2, cadastro);
        mudaTurno();
    }
    
}
