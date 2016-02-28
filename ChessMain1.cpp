//	Kathryn Shea
//	December 14, 2015
//	Assessed Exercise #3, C++
//	chess: ChessMain.cpp

#include <iostream>
#include <string>
#include "ChessBoard.h"
#include "ChessPiece.h"

using namespace std;

int main() {

	cout << "============================" << endl;
    cout << "  Testing the Chess Engine  " << endl;
    cout << "============================" << endl;
    cout << endl;

    ChessBoard cb;
    cout << endl;

    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;
   
   	cout << "============================" << endl;
    cout << "        Katie's Tests       " << endl;
    cout << "============================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;
	
    cb.submitMove("A1", "A4"); // can w rook jump?
    cout << endl;

    cb.submitMove("A1", "B1"); // can w rook take a piece of it's own color?
    cout << endl;

    cb.submitMove("B2", "B4"); // move w pawn two spaces
    cout << endl;
    
    cb.submitMove("D8", "D6"); // can b queen jump a pawn?
    cout << endl;

    cb.submitMove("E8", "E7"); // can b king take a piece of it's own color?
    cout << endl;
    
    cb.submitMove("D8", "C8"); // can b queen take a piece of it's own color?
    cout << endl;

    cb.submitMove("B8", "C6"); // move b knight
    cout << endl;

    cb.submitMove("A1", "C3"); // can w rook move diagonally?
    cout << endl;
    
    cb.submitMove("C1", "E3"); // can w bishop jump the pawn?
    cout << endl;

    cb.submitMove("C1", "D2"); // can w bishop take a piece of it's own color?
    cout << endl;

    cb.submitMove("C1", "A3"); // move w bishop 2 spaces
    cout << endl;
    
    cb.submitMove("E7", "E5"); // move b pawn two spaces
    cout << endl;

    cb.submitMove("B1", "C3"); // move w knight
    cout << endl;

    cb.submitMove("D8", "F6"); // move b queen diagonally
    cout << endl;
    
    cb.submitMove("A1", "B1"); // move w rook horizontally
    cout << endl;

    cb.submitMove("F6", "D6"); // move b queen horizontally
    cout << endl;

    cb.submitMove("B1", "B2"); // move w rook vertically
    cout << endl;
    
    cb.submitMove("D6", "D2");	// capture w pawn with b queen
    cout << endl;				// CHECK!!! (but not checkmate)
    
    cb.submitMove("E1", "D2"); // capture b queen with w king diagonally
    cout << endl;
    
    cb.submitMove("E5", "E3"); // try to move b pawn two spaces when it can't
    cout << endl;
    
    cb.submitMove("E5", "E6"); // try to move b pawn backwards
    cout << endl;
    
    cb.submitMove("E5", "F4"); // try to "capture" nothing with b pawn
    cout << endl;
    
    cb.submitMove("E5", "E4"); // move b pawn one space
    cout << endl;
    
    cb.submitMove("F2", "F3"); // move w pawn one space
    cout << endl;
    
    cb.submitMove("E4", "F3"); // b pawn captures w pawn
    cout << endl;
    
    cb.submitMove("E2", "F3"); // capture b pawn with w pawn
    cout << endl;
    
    cb.submitMove("F8", "B4"); // capture w pawn with b bishop 
    cout << endl;
    
    cb.submitMove("C3", "D5"); // attempt to move knight, putting king in check
    cout << endl;
    
    cb.submitMove("B2", "B5"); // check if w rook can jump b bishop
    cout << endl;
    
    cb.submitMove("B2", "B4"); // take bishop with w rook
    cout << endl;
    
    cb.submitMove("C6", "B4"); // take w rook with b knight
    cout << endl;
    
    cb.submitMove("A3", "B4"); // take b knight with w bishop 
    cout << endl;

    cb.submitMove("B7", "B5"); // move b pawn 2 spaces
    cout << endl;
    
    cb.submitMove("D1", "E2"); // w queen to E2, check!
    cout << endl;
    
    cb.submitMove("G8", "E7"); // put b knight in the way
    cout << endl;
    
    cb.submitMove("B4", "E7"); // take b knight with w bishop
    cout << endl;
    
    cb.submitMove("A8", "B8"); // move b rook horizontally one space
    cout << endl;
    
    cb.submitMove("E2", "B5"); // take b pawn with w queen
    cout << endl;
    
    cb.submitMove("F7", "F6"); // move b pawn one space
    cout << endl;
    
    cb.submitMove("B5", "B8"); // take b rook with w queen
    cout << endl;
    
    cb.submitMove("F6", "F5"); // move b pawn one space
    cout << endl;
    
    cb.submitMove("B8", "C8"); // take b bishop with w queen, check!
    cout << endl;
    
    cb.submitMove("E8", "F7"); // move b king out of the way
    cout << endl;
    
    cb.submitMove("C8", "H8"); // take b rook with w queen
    cout << endl;
    
    cb.submitMove("F5", "F4"); // move b pawn one space
    cout << endl;
    
    cb.submitMove("G2", "G4"); // move w pawn two spaces
    cout << endl;
    
    cb.submitMove("G7", "G5"); // move b pawn two spaces
    cout << endl;
    
    cb.submitMove("H2", "H4"); // move w pawn two spaces
    cout << endl;
    
    cb.submitMove("H7", "H6"); // move b pawn one space
    cout << endl;
    
    cb.submitMove("H4", "H5"); // move w pawn one space
    cout << endl;
    
    cb.submitMove("D7", "D5"); // move b pawn two spaces
    cout << endl;
    
    cb.submitMove("C3", "D5"); // take b pawn with w knight
    cout << endl;
    
    cb.submitMove("A7", "A5"); // move b pawn two spaces
    cout << endl;
    
    cb.submitMove("D5", "C7"); // take b pawn with w knight
    cout << endl;
    
    cb.submitMove("F7", "G6"); // try to move the b king
    cout << endl;
    
    cb.submitMove("A5", "A4"); // move b pawn one space
    cout << endl;
    
    cb.submitMove("E7", "B4"); // move w bishop
    cout << endl;
    
    cb.submitMove("A4", "A3"); // move b pawn one space
    cout << endl;
    
    cb.submitMove("B4", "A3"); // move w bishop, stalemate!
    cout << endl;
   
    cout << "===========================" << endl;
    cout << " Alekhine vs. Vasic (1931) " << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;

    return 0;
}
