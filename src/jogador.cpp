#include "jogador.hpp"

Jogador::Jogador()
    : apelido(""), nome(""), vitoriasReversi(0), derrotasReversi(0), vitoriasLig4(0), derrotasLig4(0)  {}

Jogador::Jogador(const std::string& apelido, const std::string& nome, const int vitoriasR, 
                 const int derrotasR, const int vitoriasL, const int derrotasL, const int vitoriasD, const int derrotasD)
    : apelido(apelido), nome(nome), vitoriasReversi(vitoriasR), derrotasReversi(derrotasR),
      vitoriasLig4(vitoriasL), derrotasLig4(derrotasL), vitoriasDama(vitoriasD), derrotasDama(derrotasD){}
      

std::string Jogador::getApelido() const {
    return apelido;
}

std::string Jogador::getNome() const {
    return nome;
}

int Jogador::getVitoriasReversi() const {
    return vitoriasReversi;
}

int Jogador::getDerrotasReversi() const {
    return derrotasReversi;
}

int Jogador::getVitoriasLig4() const {
    return vitoriasLig4;
}

int Jogador::getDerrotasLig4() const {
    return derrotasLig4;
}

int Jogador::getVitoriasDama() const { 
    return vitoriasDama; 
}

int Jogador::getDerrotasDama() const { 
    return derrotasDama; 
}

void Jogador::printResultados() const {
    std::cout << apelido << " " << nome << std::endl;
    std::cout << "REVERSI - V: " << vitoriasReversi << " D: " << derrotasReversi << std::endl;
    std::cout << "LIG4    - V: " <<vitoriasLig4 << " D: " << derrotasLig4 <<std::endl;
}

void Jogador::setApelido(const std::string& apelido) { 
    this->apelido = apelido;
}

void Jogador::addVitoriaLig4(){
     vitoriasLig4++; 
}

void Jogador::addVitoriaReversi(){
     vitoriasReversi++;
}

void Jogador::addDerrotaLig4 (){
     derrotasLig4++;
}

void Jogador::addDerrotaReversi (){
     derrotasReversi++;
}

void Jogador::addVitoriaDama() { 
    vitoriasDama++; 
}

void Jogador::addDerrotaDama() { 
    derrotasDama++; 
}