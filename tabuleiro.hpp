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
        //void modificaTabuleiro();
        //^^^^^^^^^^^^^^^^^^^^^^^^
        // talvez precise para modificar o tabuleiro se nao tiver herança
        // de classes para o proprio tad de cada jogo modoficar o tabuleiro
};  


#endif