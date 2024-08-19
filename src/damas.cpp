#include "damas.hpp"
#include <iostream>
#include <sstream>

Damas::Damas() : Jogos('D') {
    turno = "BRANCO";
}

Damas::~Damas() {
}

void Damas::start(std::string jogador1, std::string jogador2, Cadastro& cadastro) {
    while (!fimDeJogo) {
        printTabuleiro();
        if (temCapturaDisponivel()) {
            // Se há captura obrigatória, execute-a automaticamente
            realizaCapturaObrigatoria();
            std::cout << "*CAPTURA OBRIGATORIA*" << std::endl;
            if (verificaVitoria()) {
                            printTabuleiro();
                            fimDeJogo = true;
                            std::cout << "Parabens, " << (turno == "PRETO" ? jogador2 : jogador1) << " venceu!" << std::endl;
                            if(turno == "PRETO"){
                                cadastro.registrarResultado(jogador2, jogador1, 'D');
                            } else{
                                cadastro.registrarResultado(jogador1, jogador2, 'D');
                            }
                            break;
                        }
        } else {
            anunciaTurno(jogador1, jogador2);
            std::string input;
            std::getline(std::cin, input);

            if (input == "SAIR") {
                std::cout << "JOGO ENCERRADO" << std::endl;
                fimDeJogo = true;
                break;
            }

            int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
            std::istringstream iss(input);

            if (iss >> linhaOrigem >> colunaOrigem >> linhaDestino >> colunaDestino) {
                linhaOrigem--;
                colunaOrigem--;
                linhaDestino--;
                colunaDestino--;

                if (linhaOrigem >= 0 && linhaOrigem < 8 && colunaOrigem >= 0 && colunaOrigem < 8 &&
                    linhaDestino >= 0 && linhaDestino < 8 && colunaDestino >= 0 && colunaDestino < 8) {

                    if (movimentaPeca(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
                        if (verificaVitoria()) {
                            printTabuleiro();
                            fimDeJogo = true;
                            std::cout << "Parabens, " << (turno == "BRANCO" ? jogador2 : jogador1) << " venceu!" << std::endl;
                            if(turno == "BRANCO"){
                                cadastro.registrarResultado(jogador2, jogador1, 'D');
                            } else{
                                cadastro.registrarResultado(jogador1, jogador2, 'D');
                            }
                            break;
                        } else {
                            mudaTurno();
                        }
                    } else {
                        std::cout << "Movimento invalido, tente novamente." << std::endl;
                    }
                } else {
                    std::cout << "Entrada invalida, por favor, tente novamente." << std::endl;
                }
            } else {
                std::cout << "Entrada invalida, por favor, tente novamente." << std::endl;
            }
        }
    }
}

void Damas::anunciaTurno(std::string jogador1, std::string jogador2) {
    if (turno == "PRETO") {
        std::cout << "-TURNO DE " << jogador1 << " (X)-" << std::endl
                  << "-DIGITE A LINHA E A COLUNA DE ORIGEM E DESTINO (EX: 2 4 3 5) OU 'SAIR' PARA SAIR-" << std::endl;
    } else {
        std::cout << "-TURNO DE " << jogador2 << " (O)-" << std::endl
                  << "-DIGITE A LINHA E A COLUNA DE ORIGEM E DESTINO (EX: 2 4 3 5) OU 'SAIR' PARA SAIR-" << std::endl;
    }
    std::cout << "-> ";
}

bool Damas::movimentaPeca(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    if (verificaJogada(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
        std::string pecaAtual = turno;
        tabuleiro.modificaTabuleiro(linhaOrigem, colunaOrigem, "NULO");
        tabuleiro.modificaTabuleiro(linhaDestino, colunaDestino, pecaAtual);

        int variacaoLinha = linhaDestino - linhaOrigem;
        int variacaoColuna = colunaDestino - colunaOrigem;

        // Captura se houve movimento diagonal de 2 casas
        if (abs(variacaoLinha) == 2 && abs(variacaoColuna) == 2) {
            int meioLinha = linhaOrigem + variacaoLinha / 2;
            int meioColuna = colunaOrigem + variacaoColuna / 2;
            tabuleiro.modificaTabuleiro(meioLinha, meioColuna, "NULO");
        }

        return true;
    }
    return false;
}

bool Damas::verificaJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    std::string pecaAtual = turno;
    std::string pecaAdversario = (turno == "BRANCO") ? "PRETO" : "BRANCO";

    if (!tabuleiro.verificaCasa(linhaOrigem, colunaOrigem, pecaAtual)) {
        return false;
    }

    if (!tabuleiro.verificaCasa(linhaDestino, colunaDestino, "NULO")) {
        return false;
    }

    int variacaoLinha = linhaDestino - linhaOrigem;
    int variacaoColuna = colunaDestino - colunaOrigem;

    // Movimento válido simples
    if (abs(variacaoLinha) == 1 && abs(variacaoColuna) == 1) {
        return true;
    }

    // Captura válida
    if (abs(variacaoLinha) == 2 && abs(variacaoColuna) == 2) {
        int meioLinha = linhaOrigem + variacaoLinha / 2;
        int meioColuna = colunaOrigem + variacaoColuna / 2;
        if (tabuleiro.verificaCasa(meioLinha, meioColuna, pecaAdversario)) {
            return true;
        }
    }

    return false;
}

bool Damas::verificaVitoria() {
    bool encontrouPreto = false;
    bool encontrouBranco = false;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro.verificaCasa(i, j, "PRETO")) {
                encontrouPreto = true;
            }
            if (tabuleiro.verificaCasa(i, j, "BRANCO")) {
                encontrouBranco = true;
            }
        }
    }

    return !(encontrouPreto && encontrouBranco);
}

bool Damas::temCapturaDisponivel() {
    std::string pecaAtual = turno;
    std::string pecaAdversario = (turno == "BRANCO") ? "PRETO" : "BRANCO";

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro.verificaCasa(i, j, pecaAtual)) {
                if (podeCapturar(i, j, pecaAdversario)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Damas::podeCapturar(int linhaOrigem, int colunaOrigem, std::string pecaAdversario) {
    int direcoes[4][2] = {{-2, -2}, {-2, 2}, {2, -2}, {2, 2}};

    for (auto& dir : direcoes) {
        int linhaDestino = linhaOrigem + dir[0];
        int colunaDestino = colunaOrigem + dir[1];
        int meioLinha = linhaOrigem + dir[0] / 2;
        int meioColuna = colunaOrigem + dir[1] / 2;

        if (linhaDestino >= 0 && linhaDestino < 8 && colunaDestino >= 0 && colunaDestino < 8) {
            if (tabuleiro.verificaCasa(linhaDestino, colunaDestino, "NULO") &&
                tabuleiro.verificaCasa(meioLinha, meioColuna, pecaAdversario)) {
                return true;
            }
        }
    }
    return false;
}

void Damas::realizaCapturaObrigatoria() {
    std::string pecaAtual = turno;
    std::string pecaAdversario = (turno == "BRANCO") ? "PRETO" : "BRANCO";

    bool capturaRealizada = false;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro.verificaCasa(i, j, pecaAtual)) {
                if (podeCapturar(i, j, pecaAdversario)) {
                    // Execute a captura obrigatória
                    realizaCaptura(i, j, pecaAdversario);
                    capturaRealizada = true;

                    // Verifique se há mais capturas disponíveis após a captura
                    if (temCapturaDisponivel()) {
                        // Continue a realizar capturas se houver mais disponíveis
                        realizaCapturaObrigatoria();
                    } else {
                        // Mude o turno se não houver mais capturas disponíveis
                        mudaTurno();
                    }
                    return; // Retorne após realizar uma captura obrigatória
                }
            }
        }
    }

    if (!capturaRealizada) {
        // Se não houver captura obrigatória, mude o turno
        mudaTurno();
    }
}

void Damas::realizaCaptura(int linhaOrigem, int colunaOrigem, std::string pecaAdversario) {
    std::string pecaAtual = turno;
    int direcoes[4][2] = {{-2, -2}, {-2, 2}, {2, -2}, {2, 2}};

    for (auto& dir : direcoes) {
        int linhaDestino = linhaOrigem + dir[0];
        int colunaDestino = colunaOrigem + dir[1];
        int meioLinha = linhaOrigem + dir[0] / 2;
        int meioColuna = colunaOrigem + dir[1] / 2;

        if (linhaDestino >= 0 && linhaDestino < 8 && colunaDestino >= 0 && colunaDestino < 8) {
            if (tabuleiro.verificaCasa(linhaDestino, colunaDestino, "NULO") &&
                tabuleiro.verificaCasa(meioLinha, meioColuna, pecaAdversario)) {
                // Realiza a captura
                tabuleiro.modificaTabuleiro(linhaOrigem, colunaOrigem, "NULO");
                tabuleiro.modificaTabuleiro(meioLinha, meioColuna, "NULO");
                tabuleiro.modificaTabuleiro(linhaDestino, colunaDestino, pecaAtual);
                return; // Retorne após realizar uma captura
            }
        }
    }
}
