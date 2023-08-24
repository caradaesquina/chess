all: prog

prog: main.o game_handler.o 
	g++ -o prog main.o

main.o: main.cpp game_handler.o 
	g++ -o main.o main.cpp

game_handler.o: game_handler.cpp game_handler.h board.h board.o 
	g++ -o game_handler.o game_handler.cpp 

board.o: board.cpp board.h piece.h piece.o 
	g++ -o board.o board.cpp

piece.o: piece.cpp piece.h square.h piece_move.h square.o piece_move.o
	g++ -o piece.o piece.cpp 

square.o: square.cpp square.h
	g++ -o square.o square.cpp -c

piece_move.o: piece_move.cpp piece_move.h
	g++ -o piece_move.o piece_move.cpp -c 

clean:
	rm -rf *.o *~ printy
