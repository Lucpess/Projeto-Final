#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <vector>
#include <string>

struct Casa{
    //"PRETO" == "X"
    //"BRANCO" == "O"
    //"NULO" == " "
    std::string estado;
};

class Tabuleiro {
    private:
        std::vector<std::vector<Casa>> tabuleiro;


    public:
        Tabuleiro();

        void inicializaTabuleiro(char jogo);
        void imprimeTabuleiro() const;
        bool verificaCasa(int linha, int coluna, std::string _estado) const;
        void modificaTabuleiro(int linha, int coluna, std::string _estado);
};  


#endif