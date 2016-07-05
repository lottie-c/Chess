#include <iostream>
#include <string>
#include <map>
#include "ChessBoard.h"
#include "ChessPiece.h"

using namespace std;


ChessBoard::ChessBoard(){
  
  initial_board_config();
}

ChessBoard::~ChessBoard(){
   for (map<string, ChessPiece*>::const_iterator
	 it = board.begin(); it != board.end(); it++){
    delete it->second;
   }
}

void ChessBoard::initial_board_config(){
   //white goes first
  turn = "White";
  white_king = "E1";
  black_king = "E8";
  game_over = false;

  //make white pawns
  board["A2"] = new Pawn("White");
  board["B2"] = new Pawn("White");
  board["C2"] = new Pawn("White");
  board["D2"] = new Pawn("White");
  board["E2"] = new Pawn("White");
  board["F2"] = new Pawn("White");
  board["G2"] = new Pawn("White");
  board["H2"] = new Pawn("White");
  
  //other white pieces

  board["A1"] = new Rook("White");
  board["B1"] = new Knight("White");
  board["C1"] = new Bishop("White");
  board["D1"] = new Queen("White");
  board["E1"] = new King("White"); 
  board["F1"] = new Bishop("White");
  board["G1"] = new Knight("White");
  board["H1"] = new Rook("White");;
  
  //make black pawns
  board["A7"] = new Pawn("Black");
  board["B7"] = new Pawn("Black");
  board["C7"] = new Pawn("Black");
  board["D7"] = new Pawn("Black");
  board["E7"] = new Pawn("Black");
  board["F7"] = new Pawn("Black");
  board["G7"] = new Pawn("Black");
  board["H7"] = new Pawn("Black");
  
  //make other black pieces
  board["A8"] = new Rook("Black");
  board["B8"] = new Knight("Black");
  board["C8"] = new Bishop("Black");
  board["D8"] = new Queen("Black");
  board["E8"] = new King("Black");
  board["F8"] = new Bishop("Black");
  board["G8"] = new Knight("Black");
  board["H8"] = new Rook("Black");
 
  //Fill in rest of board
  board["A3"] = NULL;
  board["A4"] = NULL;
  board["A5"] = NULL;
  board["A6"] = NULL;
  board["B3"] = NULL;
  board["B4"] = NULL;
  board["B5"] = NULL;
  board["B6"] = NULL;
  board["C3"] = NULL;
  board["C4"] = NULL;
  board["C5"] = NULL;
  board["C6"] = NULL;
  board["D3"] = NULL;
  board["D4"] = NULL;
  board["D5"] = NULL;
  board["D6"] = NULL;
  board["E3"] = NULL;
  board["E4"] = NULL;
  board["E5"] = NULL;
  board["E6"] = NULL;
  board["F3"] = NULL;
  board["F4"] = NULL;
  board["F5"] = NULL;
  board["F6"] = NULL;
  board["G3"] = NULL;
  board["G4"] = NULL;
  board["G5"] = NULL;
  board["G6"] = NULL;
  board["H3"] = NULL;
  board["H4"] = NULL;
  board["H5"] = NULL;
  board["H6"] = NULL;

   cout << "A new chess game is started!" << endl;
}

void ChessBoard::resetBoard(){
  
  for (map<string, ChessPiece*>::const_iterator
	 it = board.begin(); it != board.end(); it++){
    delete it->second;
  }

  board.clear();
  initial_board_config();
}


void ChessBoard::submitMove(string start, string end){

  /*make sure that 'start' and 'end' are squares on an
   8X8 chessboard*/
  if (game_over){
    cout << "Cannot make move, game is over." << endl;
    return;
  }

  if(!(square_on_board(start)&&square_on_board(end))){
    return;
  }
  
  //make sure that we are moving a piece
  if (board[start] == NULL){
    cout << "There is no piece at " << start << endl;
    return;
  }
 
  string colour = board[start]->get_colour();
  string piece = board[start]->get_piece();
  

  if (!( turn == colour)){
    cout << "It is not " << colour 
	 << "'s turn to move!" << endl;
    return;
  }
  
  ChessBoard* board_ptr = this;
  if(! board[start]->movement_legal(start,end,board_ptr)){
    cout << colour << "'s " << piece
	 << " cannot move to " << end 
	 << "!" << endl;
    return;
  }
 
  string opponent;
   
  if (turn == "White"){
    opponent = "Black"; 
  }else{
    opponent = "White"; 
  } 
  
  make_move(start, end);
  
  if (check_check(opponent)){
    /*if piece has put opponent in check, check if opponent is
     in check mate*/
    if(check_checkmate(opponent)){
      cout << opponent << " is in checkmate" << endl;
      game_over = true;
      return;
    }else{
      cout << opponent << " is in check" << endl;
    }
  }else if (check_checkmate(opponent)){
    /*if opponent is not in check but there is no legal move 
      that they can make without putting themselves in check
      then they are in stalemate.*/
    cout << opponent << " is in stalemate" << endl;
    game_over = true;
    return;
  }

  return;
}


bool ChessBoard:: check_check(string colour){

  string opponent, my_king;

  if (colour =="White"){
    my_king = white_king;
    opponent = "Black";
  }else{
    my_king = black_king;
    opponent = "White";
  }
  
  /*Iterate through map, if one or more of opponent's king 
  pieces can take 'colour's king, return true */
  for (map<string, ChessPiece*>::const_iterator
	 it =board.begin(); it != board.end(); it++){
   
    if ((it->second != NULL)&&
	(it->second->get_colour() == opponent) &&
	(it->second->movement_legal(it->first,
				    my_king, this))){
      return true;
    }
  }
  return false;
}



bool ChessBoard::check_checkmate(string colour){
  
  bool checkmate = true;
  string my_king;
  
  if (colour =="White"){
    my_king = white_king;
  }else{
    my_king = black_king;
  }

  for (map<string, ChessPiece*>::const_iterator
	 it_piece = board.begin(); it_piece != board.end(); it_piece++){
    
    //for every piece on the team 'colour'
    if ((it_piece->second != NULL)&&
	(it_piece->second->get_colour() == colour)){
      for (map<string, ChessPiece*>::const_iterator
	     it_square = board.begin(); it_square != board.end(); it_square++){

	// if that piece can make a legal move check if that move
	// will get the king out of check
	if ((it_square->first != it_piece->first) && 
	    (it_piece->second->
	     movement_legal(it_piece->first, it_square->first, this))){

	   
	  ChessPiece* temp_ptr = NULL; 
	  string end = it_square->first;
	  string start = it_piece->first;
	   
	  temp_ptr = board[end];
	  board[end] = board[start];
	  board[start] = NULL;
	  change_my_king(end);
	    
	  if(!check_check(colour)){
	    checkmate = false;
	    board[start] = board[end];
	    board[end] = temp_ptr;
	    change_my_king(start);
	    temp_ptr = NULL;
	    return checkmate;
	  }

	  board[start] = board[end];
	  board[end] = temp_ptr;
	  temp_ptr = NULL;
	   
	}
      }
	
    }

  }
  return checkmate;
}


void ChessBoard::make_move(string start, string end){
 
  ChessPiece* temp_ptr;
  string colour = board[start]->get_colour();
  string piece = board[start]->get_piece();

  /*put taken piece in temporary pointer if no piece
   at 'end' temp_ptr will be null*/
  temp_ptr = board[end];
  
  // put capturing piece in the end square
  board[end] = board[start];
  board[start] = NULL;

  //if moved piece is a king, update appropriate king position
  change_my_king(end);
  
  if (check_check(colour)){
    //if in check undo move as it is not legal
    board[start] = board[end];
    board[end] = temp_ptr;
    temp_ptr = NULL;

    change_my_king(start);
   
    cout << colour << "'s " << piece
	 << " cannot move to " << end
	 << "!" << endl;
  }else{
    //if move is legal make the move
    cout << colour << "'s " << piece << " moves from " 
	 << start << " to " << end;

    if (temp_ptr != NULL){
      cout<< " taking " << temp_ptr->get_colour() << "'s "
	  << temp_ptr->get_piece();
      temp_ptr = NULL;
    }
    cout << endl;
   
    change_turn();
   
  }
}  

map<string, ChessPiece*> ChessBoard::get_board(){
  return(board);
}

bool ChessBoard::square_on_board(string square){
 
  char  file = square.at(0), rank = square.at(1);
  if(file < 'A'|| 
     file > 'H'|| 
     rank < '1'||
     rank > '8'){

    cout << square << " is not a valid position on a chess board.";
    return false;
  }else{
    return true;
  }
}

bool ChessBoard::square_empty(string square){
  if(board[square] != NULL){
    return false;
  }else{
    return true;
  }
  
}

void ChessBoard::change_turn(){
  if (turn == "Black"){
    turn = "White";
    return;
  }else{
    turn = "Black";
    return;
  }
}


void ChessBoard::change_my_king(string square){
  if (!square_empty(square)){
    if (board[square]->get_piece() == "King"){
      if (board[square]->get_colour()== "White"){
	white_king = square; 
      }else{
	black_king = square;
      }
    }
  }  
}
