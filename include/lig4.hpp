#ifndef LIG4_H
#define LIG4_H

#include "jogos.hpp"

class Lig4 : public Jogos {
public: 
    Lig4();
    ~Lig4();
    void start(std::string jogador1, std::string jogador2, Cadastro& cadastro) override;
    bool verifica4(int linha, int coluna);
    int verificaFimDeJogo (int coluna, std::string jogador1, std::string jogador2, Cadastro& cadastro);

private: 
        bool jogadaPermitida(int col);
        void novaJogada(int col);
        void anunciaTurno(std::string jogador1, std::string jogador2) override;
};

#endif
