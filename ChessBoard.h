#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class ChessPiece;

class ChessBoard{

 private:
  map<string, ChessPiece*> board;
  string turn;
  //position on board of black king
  string black_king;
  //position on board of white king
  string white_king;
 public: 

  /*Constructor function for chessboard.*/
  ChessBoard();

  /*Destructor function for chessboard*/
  ~ChessBoard();


  /*Function sets up the board for the start of
    a chess game*/
  void initial_board_config();

  /*Function clears board and resets it for a new
    game*/
  void resetBoard();

  /*Function to submit a move to the board,
    start is the position of the piece to move, 
    end is destination of that piece*/
  void submitMove(string start, string end);


  /*Function returns true if 'colour''s king is 
    under immediate attack by one or more of
    the opponents pieces and false otherwise.*/
  bool check_check(string colour);

  /*Function returns false if any of 'colour's
    pieces can move such that 'colour' is not in
    check, and true otherwise*/
  bool check_checkmate(string colour);

  /*Function moves the piece at 'start' to the 
    destination 'end' if said move is a legal move in chess,
    otherwise  an appropriate message is output*/
  void make_move(string start, string end);
 

  /* function returns the map, 'board'*/
  map<string, ChessPiece*> get_board();


  /*Function returns true if 'square' is a 
    square on an 8x8 chess board*/
  bool square_on_board(string square);

  /*Function returns true if there is not a piece
    occupying 'square'*/
  bool square_empty(string square);

  /*Function changes the attribute turn, 
    from Black to White and vice versa*/
  void change_turn();
 
  /*Function ensures that the attributes
    'black_king' and 'white_king' are 
    up to date. */
  void change_my_king(string square);
};

#endif
