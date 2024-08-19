CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude
TARGET = bin/jogo.exe
TEST_TARGET = bin/testes.exe

# Objetos para o programa principal
OBJECTS = obj/tabuleiro.o obj/jogador.o obj/cadastro.o obj/jogos.o obj/damas.o obj/lig4.o obj/reversi.o obj/main.o
# Objetos para os testes
TEST_OBJECTS = obj/teste_cadastro.o obj/teste_jogador.o obj/teste_damas.o obj/teste_lig4.o obj/teste_reversi.o obj/teste_tabuleiro.o obj/teste_main.o

# Compilar o programa principal
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compilar o executável de testes
$(TEST_TARGET): $(filter-out obj/main.o, $(OBJECTS)) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(filter-out obj/main.o, $(OBJECTS)) $(TEST_OBJECTS)


# Regras para compilar os arquivos de objeto principais
obj/tabuleiro.o: src/tabuleiro.cpp include/tabuleiro.hpp
	$(CXX) $(CXXFLAGS) -c src/tabuleiro.cpp -o obj/tabuleiro.o

obj/jogador.o: src/jogador.cpp include/jogador.hpp
	$(CXX) $(CXXFLAGS) -c src/jogador.cpp -o obj/jogador.o

obj/cadastro.o: src/cadastro.cpp include/cadastro.hpp include/jogador.hpp
	$(CXX) $(CXXFLAGS) -c src/cadastro.cpp -o obj/cadastro.o

obj/jogos.o: src/jogos.cpp include/jogos.hpp include/tabuleiro.hpp include/cadastro.hpp
	$(CXX) $(CXXFLAGS) -c src/jogos.cpp -o obj/jogos.o

obj/damas.o: src/damas.cpp include/damas.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -c src/damas.cpp -o obj/damas.o

obj/lig4.o: src/lig4.cpp include/lig4.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -c src/lig4.cpp -o obj/lig4.o

obj/reversi.o: src/reversi.cpp include/reversi.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -c src/reversi.cpp -o obj/reversi.o

obj/main.o: src/main.cpp include/cadastro.hpp include/lig4.hpp include/reversi.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

# Regras para compilar os arquivos de objeto de teste
obj/teste_cadastro.o: tests/teste_cadastro.cpp include/cadastro.hpp include/jogador.hpp
	$(CXX) $(CXXFLAGS) -c tests/teste_cadastro.cpp -o obj/teste_cadastro.o

obj/teste_jogador.o: tests/teste_jogador.cpp include/jogador.hpp
	$(CXX) $(CXXFLAGS) -c tests/teste_jogador.cpp -o obj/teste_jogador.o

obj/teste_damas.o: tests/teste_damas.cpp include/damas.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -c tests/teste_damas.cpp -o obj/teste_damas.o

obj/teste_lig4.o: tests/teste_lig4.cpp include/lig4.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -c tests/teste_lig4.cpp -o obj/teste_lig4.o

obj/teste_reversi.o: tests/teste_reversi.cpp include/reversi.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -c tests/teste_reversi.cpp -o obj/teste_reversi.o

obj/teste_tabuleiro.o: tests/teste_tabuleiro.cpp include/tabuleiro.hpp
	$(CXX) $(CXXFLAGS) -c tests/teste_tabuleiro.cpp -o obj/teste_tabuleiro.o

obj/teste_main.o: tests/teste_main.cpp include/cadastro.hpp include/lig4.hpp include/reversi.hpp include/jogos.hpp include/doctest.h
	$(CXX) $(CXXFLAGS) -c tests/teste_main.cpp -o obj/teste_main.o

# Compila ambos os alvos
all: $(TARGET) $(TEST_TARGET)

# Limpar arquivos gerados
clean:
	del /q obj\*.o
	del /q bin\*.exe

.PHONY: all clean
