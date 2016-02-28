#include "ChessPiece.h"
#include "ChessBoard.h"
#include "Pawn.h"


Pawn::Pawn(string _position) : ChessPiece(_position){
  piece = "Pawn";
}

Pawn::~Pawn(){}

bool Pawn::movement_legal(string start, string end, ChessBoard* cb ){
 
  if(same_colour(start, end, cb)){
    return false;
  }
  
  if (start == end){
    cout << colour <<"'s " << piece
	 << " is already at " << end <<endl;
    return false;
  }

  if (colour == "White"){
    return (white_pawn_movement(start, end, cb));
  }else{
    return(black_pawn_movement(start, end, cb));
  }
}

bool Pawn::white_pawn_movement(string start, string end, ChessBoard* cb){
  
  char start_file = start.at(0), end_file = end.at(0);
  int  start_rank = static_cast<int>(start.at(1))-48;
  int  end_rank = static_cast<int>(end.at(1)) - 48;

  if((end_rank == start_rank + 2) &&
     (start_rank == 2) &&
     (start_file == end_file) &&
     (clear_path(start, end, cb)) && 
     (cb->square_empty(end))){
   
    return true;
  }
  
  if((end_rank == start_rank + 1)&&
     (start_file == end_file)&&
     cb->square_empty(end)){
    
    return true;
  }
  
  if( (end_rank == start_rank + 1) &&
      ((end_file == start_file + 1)||
       (end_file == start_file - 1)) &&
      (!cb->square_empty(end))){
    return true;   
  }
 
  return false;
}


bool Pawn::black_pawn_movement(string start, string end, ChessBoard* cb){
  
  char start_file = start.at(0), end_file = end.at(0);
  int  start_rank = static_cast<int>(start.at(1))-48;
  int  end_rank = static_cast<int>(end.at(1)) - 48;
  
  if((end_rank == start_rank - 2) &&
     (start_rank == 7) &&
     (start_file == end_file) &&
     (clear_path(start, end, cb)) && 
     (cb->square_empty(end))){
   
    return true;
  }
  
  if((end_rank == start_rank - 1)&&
     (start_file == end_file)&&
     cb->square_empty(end)){
    
    return true;
  }
  
  if((end_rank == start_rank - 1) &&
     ((end_file == start_file + 1)||
      (end_file == start_file - 1)) &&
     (!cb->square_empty(end))){
    return true;   
  }
  return false;
}
