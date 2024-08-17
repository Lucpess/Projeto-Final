#include <iostream>
#include <sstream>
#include <string>
#include "cadastro.hpp"
#include "lig4.hpp"
#include "reversi.hpp"

int main() {
    Cadastro cadastro;
    std::string comando;

    std::cout << "--BEM VINDO AOS JOGOS--"<< std::endl;

    while(1){
        std::cout<< "O QUE VOCÊ DESEJA FAZER? PARA:" << std::endl;
        std::cout<< ".CADASTRAR JOGADOR: DIGITE ''CJ <Apelido> <Nome>''" << std::endl;
        std::cout<< ".REMOVER JOGADOR: DIGITE ''RJ <APELIDO>''" << std::endl;
        std::cout<< ".LISTAR JOGADORES: DIGITE ''LJ [A/N]''" <<std::endl;
        std::cout<< ".EXECUTAR PARTIDA: DIGITE ''EP <JOGO: (R/L)> <Apelido1> <Apelido2>''" << std::endl;
        std::cout<< ".FINALIZAR SISTEMA: DIGITE ''FS''" << std::endl;

        std::getline(std::cin,comando);
        std::istringstream iss(comando);
        std::string acao;
        iss>>acao;

        if(acao == "FS"){
            std::cout<< "Finalizando o programa!" <<std::endl;
            break;

        } else if(acao == "CJ"){
            std::string apelido;
            std::string nome;
            if(iss >> apelido >> nome){
                cadastro.cadastraJogador(apelido, nome);
            } else{
                std::cout << "Comando inválido para cadastrar jogador!" << std::endl;
            }

        } else if(acao == "RJ"){
            std::string apelido;
            if(iss>>apelido){
                cadastro.removeJogador(apelido);
            }else{
                std::cout << "Comando inválido para registrar jogador!" << std::endl;
            }

        } else if(acao == "LJ"){
            std::string ordem;
            if(iss>>ordem){
                cadastro.listaJogadores(ordem);
            }else{
                std::cout << "Comando inválido para listar jogadores!" << std::endl;
            }

        } else if(acao == "EP"){
            std::string jogo;
            std::string jogador1;
            std::string jogador2;
            if(iss >> jogo >> jogador1 >> jogador2){
                if(jogo != "R" && jogo != "L") {
                    std::cout << "ERRO: dados incorretos" << std:: endl;
                    continue;
                }

                if(!cadastro.existeJogador(jogador1) || !cadastro.existeJogador(jogador2)) {
                    std::cout << "ERRO: jogador inexistente" << std::endl;
                    continue;
                }

                if(jogador1 == jogador2){
                    std::cout << "ERRO: jogadores iguais" << std::endl;
                    continue;
                }

                if(jogo == "R") {
                    Reversi* jogo = new Reversi();
                    jogo->start(jogador1, jogador2);
                    delete jogo;
                    
                } else if (jogo == "L") {
                        Lig4* jogo = new Lig4();
                        jogo->start(jogador1, jogador2, cadastro);
                        delete jogo;
                    }
            } else{
                std::cout << "Comando inválido para executar partida!" << std::endl;
                }
        } else{
            std::cout<< "Comando inválido. Por favor, digite um comando válido!" << std::endl;
        }

    }
}