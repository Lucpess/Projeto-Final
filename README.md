# Projeto-Final
Repositório do Trabalho Final Jogos de Tabuleiro

## Visão Geral

Este projeto implementa uma série de jogos de tabuleiro em C++, incluindo Lig4, Reversi e Damas. O objetivo é fornecer uma base sólida para o desenvolvimento e gestão de jogos de tabuleiro, oferecendo funcionalidades básicas como gerenciamento de turnos, verificação de condições de vitória e empate, e interação com o usuário.

## Estrutura do Projeto

O projeto está organizado em diretórios e arquivos da seguinte forma:

- *Include*: Contém os arquivos de cabeçalho (.hpp) que definem as classes e interfaces do projeto.
- *Src*: Contém os arquivos de implementação (.cpp) das classes e funcionalidades principais.
- *Obj*: Diretório onde são armazenados os arquivos de objeto (.o) gerados durante a compilação.
- *Bin*: Diretório que armazena o executável final (jogo.exe e testes.exe).
- *Tests*: Diretório que armazena os arquivos de implementação (.cpp) dos testes.

## Funcionalidades Implementadas

### Jogo Lig4

A classe Lig4 é responsável pela implementação do jogo Lig4. As principais funcionalidades incluem:

- *Início do Jogo*: Inicializa o estado do jogo e gerencia o loop principal de jogadas.
- *Verificação de Vitória*: Verifica se há uma sequência de 4 peças consecutivas em qualquer direção.
- *Verificação de Fim de Jogo*: Determina se a partida terminou por vitória ou empate.
- *Gerenciamento de Turnos*: Alterna entre os jogadores e exibe o turno atual.

### Jogo Reversi

A classe Reversi é responsável pela implementação do jogo Reversi, incluindo:

- *Movimento de Peças*: Permite o movimento das peças de acordo com as regras do jogo.
- *Captura de Peças*: Implementa a lógica de captura das peças adversárias.
- *Verificação de Vitória*: Avalia se um jogador ganhou o jogo, ou se houve empate.

## Documentação

A documentação do código foi gerada utilizando Doxygen5. A documentação inclui detalhes sobre:

- *Estruturas de Dados*: Descrição das estruturas utilizadas, como tabuleiro, peças e jogadores.
- *Métodos*: Detalhamento das funções e sua funcionalidade, como movimentação de peças, verificação de condições de vitória, etc.

Para visualizar a documentação, consulte o diretório docs gerado pelo Doxygen. Ao pegar o arquivo de nome "index.html" e arrastá-lo para o navegador, será aberta uma página com a documentação.

## Dificuldades Encontradas

Durante o desenvolvimento do projeto, algumas dificuldades foram encontradas:

- *Gerenciamento de Turnos*: Implementar a alternância de turnos e verificar as condições de vitória exigiu um entendimento aprofundado das regras dos jogos e uma cuidadosa implementação da lógica.
- *Documentação*: Garantir que toda a documentação estivesse completa e precisa foi desafiador, especialmente ao detalhar a estrutura de dados e o funcionamento interno das classes.
- *Testes*: Implementar e garantir que os testes cobrissem todos os casos possíveis, especialmente para teste_cadastro (uma vez que o arquivo já contava com o tratamento de exceções) foi um desafio adicional, pois estavamos nos deparando com problemas de funções que eram definidas multiplas vezes e com detalhes do uso do doctest que foram muito complicados de se compreennder e resolver. Desde problemas que exigiram a reinstalção do mingw e do vs code como alteração completa do código previamente feito.

## Extras Implementados

Além das funcionalidades básicas, foram implementados os seguintes extras:

- *Jogo de Damas*: Implementação completa do jogo de Damas, com todas as regras e lógicas associadas. Entretanto, nessa versão de damas, é permitida a movimentação apra trás, além de a peça nao virar dama ao chegar na última linha. Além disso, quando há uma peça do oponente disponível para ser comida, ela é comida automaticamente.

## Instruções para Compilação e Execução

1. *Compilação*: Execute make all para compilar o projeto completo (jogo.exe e testes.exe), ou apenas make para compilar apenas o jogo.exe.
2. *Execução*: Para executar o arquivo jogo.exe, digite ".\bin\jogo.exe" no terminal, ou, para executar o arquivo de testes unitários, testes.exe, digitando ".\bin\testes.exe" .
