chess: ChessMain.o ChessBoard.o ChessPiece.o
	g++ -Wall -g ChessMain.o ChessBoard.o ChessPiece.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h ChessPiece.h
	g++ -Wall -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h ChessPiece.h 
	g++ -Wall -c ChessBoard.cpp

ChessPiece.o: ChessPiece.cpp ChessPiece.h
	g++ -Wall -c ChessPiece.cpp

.PHONY: clean

clean:
	rm -f chess *.o

