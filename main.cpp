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
                //implementar método para cadastrar jogador
            } else{
                std::cout << "Comando inválido para cadastrar jogador!" << std::endl;
            }

        } else if(acao == "RJ"){
            std::string apelido;
            if(iss>>apelido){
                //implementar método para registrar jogador
            }else{
                std::cout << "Comando inválido para registrar jogador!" << std::endl;
            }

        } else if(acao == "LJ"){
            std::string ordem;
            if(iss>>ordem){
                //implementar método para listar jogadores
            }else{
                std::cout << "Comando inválido para listar jogadores!" << std::endl;
            }

        } else if(acao == "EP"){
            std::string jogo;
            std::string jogador1;
            std::string jogador2;
            if(iss >> jogo >> jogador1 >> jogador2){
                //implementar método para executar partida
            } else{
                std::cout << "Comando inválido para executar partida!" << std::endl;
            }
        } else{
            std::cout<< "Comando inválido. Por favor, digite um comando válido!" << std::endl;
        }

    }
}