#ifndef DAMAS_HPP
#define DAMAS_HPP

#include "jogos.hpp"

class Damas : public Jogos {
public:
    Damas();
    ~Damas();

    void start(std::string jogador1, std::string jogador2, Cadastro& cadastro) override;

private:
    void anunciaTurno(std::string jogador1, std::string jogador2) override;
    bool movimentaPeca(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    bool verificaJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    bool verificaVitoria();
    bool temCapturaDisponivel();
    bool podeCapturar(int linhaOrigem, int colunaOrigem, std::string pecaAdversario);
    void realizaCapturaObrigatoria();
    void realizaCaptura(int linhaOrigem, int colunaOrigem, std::string pecaAdversario);
};

#endif