CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = bin/jogo

OBJECTS = obj/tabuleiro.o obj/jogador.o obj/cadastro.o obj/jogos.o obj/lig4.o obj/reversi.o obj/main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

obj/tabuleiro.o: src/tabuleiro.cpp include/tabuleiro.hpp
	$(CXX) $(CXXFLAGS) -Iinclude -c src/tabuleiro.cpp -o obj/tabuleiro.o

obj/jogador.o: src/jogador.cpp include/jogador.hpp
	$(CXX) $(CXXFLAGS) -Iinclude -c src/jogador.cpp -o obj/jogador.o

obj/cadastro.o: src/cadastro.cpp include/cadastro.hpp include/jogador.hpp
	$(CXX) $(CXXFLAGS) -Iinclude -c src/cadastro.cpp -o obj/cadastro.o

obj/jogos.o: src/jogos.cpp include/jogos.hpp include/tabuleiro.hpp
	$(CXX) $(CXXFLAGS) -Iinclude -c src/jogos.cpp -o obj/jogos.o

obj/lig4.o: src/lig4.cpp include/lig4.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -Iinclude -c src/lig4.cpp -o obj/lig4.o

obj/reversi.o: src/reversi.cpp include/reversi.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -Iinclude -c src/reversi.cpp -o obj/reversi.o

obj/main.o: src/main.cpp include/cadastro.hpp include/lig4.hpp include/reversi.hpp include/jogos.hpp
	$(CXX) $(CXXFLAGS) -Iinclude -c src/main.cpp -o obj/main.o

clean:
	del /q obj\*.o
	del /q bin\*.exe
