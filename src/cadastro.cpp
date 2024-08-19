#include "cadastro.hpp"
#include<fstream>
#include<algorithm>
#include<vector> 
#include <stdexcept>   

Cadastro::Cadastro() {
    try {
        atualizarCadastro();
    } catch (const std::exception& e) {
        std::cerr << "Erro no cadastro: " << e.what() << std::endl;
    }
}

Cadastro::~Cadastro() {
    try {
        salvarCadastro();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao salvar cadastro: " << e.what() << std::endl;
    }
}

void Cadastro::salvarCadastro() {
    try {
        std::ofstream arquivo("cadastro_jogadores.txt");
        if (!arquivo.is_open()) {
            throw std::runtime_error("ERRO: Não foi possível abrir o arquivo");
        }

        for (const auto& par : jogadores) {
            const Jogador& jogador = par.second;
            arquivo << jogador.getApelido() << " " << jogador.getNome() << " "
                    << jogador.getVitoriasReversi() << " " << jogador.getDerrotasReversi() << " "
                    << jogador.getVitoriasLig4() << " " << jogador.getDerrotasLig4() << " " 
                    << jogador.getVitoriasDama() << " " << jogador.getDerrotasDama() << std::endl;
        }

        arquivo.close();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao salvar cadastro: " << e.what() << std::endl;
        throw; 
    }
} 

void Cadastro::atualizarCadastro(){
    try {
        std::ifstream arquivo("cadastro_jogadores.txt");
        if (!arquivo.is_open()) {
            throw std::runtime_error("ERRO: Não foi possível abrir o arquivo");
        }

        jogadores.clear();

        std::string nome, apelido;
        int vitoriasReversi, derrotasReversi, vitoriasLig4, derrotasLig4, vitoriasDama, derrotasDama;

        while(arquivo >> apelido >> nome >> vitoriasReversi >> derrotasReversi >> vitoriasLig4 >> derrotasLig4 >> vitoriasDama >> derrotasDama) {
            Jogador jogador(apelido, nome, vitoriasReversi, derrotasReversi, vitoriasLig4, derrotasLig4, vitoriasDama, derrotasDama);
            jogadores.emplace(apelido, jogador);
        }

        arquivo.close();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao carregar cadastro: " << e.what() << std::endl;
        throw;
    }
} 

void Cadastro::cadastraJogador(const std::string& apelido, const std::string& nome) {
    try {
        if (apelido.empty() || nome.empty()) {
            throw std::invalid_argument("ERRO: entrada inválida");
        }

        if (jogadores.find(apelido) != jogadores.end()) {
            throw std::runtime_error("ERRO: jogador já cadastrado");
        }

        jogadores[apelido] = Jogador(apelido, nome);
        std::cout << "Jogador " << apelido << " cadastrado com sucesso" << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "ERRO: Erro ao cadastrar jogador" << std::endl;
    }
}

void Cadastro::removeJogador(const std::string& apelido) {
    try {
        if (jogadores.erase(apelido)) {
            std::cout << "Jogador " << apelido << " removido com sucesso" << std::endl;
        } else {
            throw std::runtime_error("ERRO: jogador inexistente");
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Cadastro::listaJogadores(const std::string& ordem) const {
    try {
        if (jogadores.empty()) {
            throw std::runtime_error("ERRO: Nenhum jogador cadastrado");
        }

        std::vector<std::pair<std::string, Jogador>> lista(jogadores.begin(), jogadores.end());

        if (ordem == "A") {
            std::sort(lista.begin(), lista.end(), [](const std::pair<std::string, Jogador>& a, const std::pair<std::string, Jogador>& b) {
                return a.first < b.first; 
            });
        } else if (ordem == "N") {
            std::sort(lista.begin(), lista.end(), [](const std::pair<std::string, Jogador>& a, const std::pair<std::string, Jogador>& b) {
                return a.second.getNome() < b.second.getNome(); 
            });
        } else {
            throw std::runtime_error("ERRO: ordem inválida");
        }

        for (const auto& par : lista) {
            const std::string& apelido = par.first;
            const Jogador& jogador = par.second;
            std::cout << apelido << " " << jogador.getNome() << std::endl;
            std::cout << "REVERSI - V: " << jogador.getVitoriasReversi() << " D: " << jogador.getDerrotasReversi() << std::endl;
            std::cout << "LIG4 - V: " << jogador.getVitoriasLig4() << " D: " << jogador.getDerrotasLig4() << std::endl;
            std::cout << "DAMA - V: " << jogador.getVitoriasDama() << " D: " << jogador.getDerrotasDama() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
} 

void Cadastro::registrarResultado(const std::string& vencedor, const std::string& perdedor, char jogo){
    try {
        if(jogadores.find(vencedor)==jogadores.end() || jogadores.find(perdedor)==jogadores.end()){
            throw std::runtime_error("ERRO: jogador não existe");
        }
        if(jogo == 'R') {
            jogadores[vencedor].addVitoriaReversi();
            jogadores[perdedor].addDerrotaReversi();
        } else if (jogo == 'L') {
            jogadores[vencedor].addVitoriaLig4();
            jogadores[perdedor].addDerrotaLig4();
        } else if (jogo == 'D') {
            jogadores[vencedor].addVitoriaDama();
            jogadores[perdedor].addDerrotaDama();
        } else {
            throw std::runtime_error("ERRO: Jogo inválido");
        }
        std::cout << "Resultado registrado." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

bool Cadastro::existeJogador(const std::string& apelido) const {
        return jogadores.find(apelido) != jogadores.end();
}