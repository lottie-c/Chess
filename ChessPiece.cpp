#include "ChessPiece.h"
#include "ChessBoard.h"



ChessPiece::ChessPiece(string _colour){
  colour = _colour;
}

ChessPiece::~ChessPiece(){};

bool ChessPiece::clear_path(string  start, string end, ChessBoard* cb){
 
  char start_file = start.at(0), end_file = end.at(0);
  char start_rank = start.at(1), end_rank = end.at(1);
  
  int file_difference = static_cast<int>(end_file) -
    static_cast<int>(start_file);
  int rank_difference = static_cast<int>(end_rank) -
    static_cast<int>(start_rank); 

  /*if 'start' and 'end' are in same file check that the pathway
    between them is clear, if not return false*/
  if(start_file == end_file){

    int difference = static_cast<int>(end_rank) 
      - static_cast<int>(start_rank);
    
    if (difference > 0){
      for (int i = 1; i < abs(difference); i++){
	char intermediate_rank = start_rank + i;
	string pathway("XX");
	pathway[0] = start_file;
	pathway[1] = intermediate_rank;
        if(!cb->square_empty(pathway)){
	  return false;
	}
      }  
    }
     
    if (difference < 0){
      for (int i = 1 ; i < abs(difference); i++){
        char intermediate_rank = start_rank - i;
	string pathway("XX");
	pathway[0] = start_file;
	pathway[1] = intermediate_rank;
        if(!cb->square_empty(pathway)){
	  return false;
	}
      }
    }
    return true;
  }
  /*if 'start' and 'end' are in same rank check that the pathway between 
    them is clear, if not return false*/
  if(start_rank == end_rank){
    
    int difference = static_cast<int>(end_file) -
      static_cast<int>(start_file);
   
    if (difference > 0){
      for (int i = 1; i < abs(difference); i++){
	
	char intermediate_file = start_file + i;
	string pathway("XX");
	pathway[0] = intermediate_file;
	pathway[1] = start_rank;
        if(!cb->square_empty(pathway)){
	  return false;
	}
      }
    }

    if (difference < 0){
      for (int i = 1 ; i < abs(difference) ; i++){
	char intermediate_file = start_file - i;
	string pathway("XX");
	pathway[0] = intermediate_file;
	pathway[1] = start_rank;
	if(!cb->square_empty(pathway)){
	  return false;
	} 
      }
    }
    return true;
  }

  /*if 'start' and 'end' are on the  same diagonal check that the
    pathway between them is clear, if not return false*/
  if( abs(file_difference) == abs(rank_difference)){
    
    if((file_difference > 0) && (rank_difference > 0)){
      for (int i = 1; i <abs(file_difference); i++){

	char intermediate_file = start_file + i;
	char intermediate_rank = start_rank + i;
	string pathway("XX");
	pathway[0] = intermediate_file;
	pathway[1] = intermediate_rank;
	if(!cb->square_empty(pathway)){
	  return false;
	}
      }
    }

    if(file_difference > 0 && rank_difference < 0){
      for (int i = 1; i < abs(file_difference); i++){

	char intermediate_file = start_file + i;
	char intermediate_rank = start_rank - i;
	string pathway("XX");
	pathway[0] = intermediate_file;
	pathway[1] = intermediate_rank;
	if(!cb->square_empty(pathway)){
	  return false;
	}
      }
    }
     
    if(file_difference < 0 && rank_difference > 0){
      for (int i = 1; i < abs(file_difference); i++){

	char intermediate_file = start_file - i;
	char intermediate_rank = start_rank + i;
	string pathway("XX");
	pathway[0] = intermediate_file;
	pathway[1] = intermediate_rank;
	if(!cb->square_empty(pathway)){
	  return false;
	}
      }
    }
   
    if(file_difference < 0 && rank_difference < 0){
      for (int i = 1; i < abs(file_difference); i++){

	char intermediate_file = start_file - i;
	char intermediate_rank = start_rank - i;
	string pathway("XX");
	pathway[0] = intermediate_file;
	pathway[1] = intermediate_rank;
        
	if(!cb->square_empty(pathway)){
	  return false;
	}
      }
    }
    return true;
  }
  return false; 
}

string ChessPiece::get_colour(){
  return (colour);
}


string ChessPiece::get_piece(){
  return (piece);
}


bool ChessPiece::same_colour(string start, string end, ChessBoard* cb){
  if ((!cb->square_empty(end)) &&
      (colour == cb->get_board()[end]->get_colour())){
    return true;
  }else{
    return false;
  }
}

//-----------------------------PAWN FUNCTIONS---------------------------------


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

  /*On its first move a pawn can move one or two squares forward
    along the same file to an empty square.*/
  if((end_rank == start_rank + 2) &&
     (start_rank == 2) &&
     (start_file == end_file) &&
     (clear_path(start, end, cb)) && 
     (cb->square_empty(end))){
   
    return true;
  }
  
  /*After its first move a pawn can move to an unoccupied square 
   immediately infront of it, on the same file*/
  if((end_rank == start_rank + 1)&&
     (start_file == end_file)&&
     cb->square_empty(end)){
    
    return true;
  }
  
  /*A pawn may move to a square occupied by an opponent's piece
    which is diagonally in front of it on an adjacent file*/
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
  
  /*On its first move a pawn can move one or two squares forward
    along the same file to an empty square.*/
  if((end_rank == start_rank - 2) &&
     (start_rank == 7) &&
     (start_file == end_file) &&
     (clear_path(start, end, cb)) && 
     (cb->square_empty(end))){
   
    return true;
  }
  
  /*After its first move a pawn can move to an unoccupied square 
   immediately infront of it, on the same file*/
  if((end_rank == start_rank - 1)&&
     (start_file == end_file)&&
     cb->square_empty(end)){
    
    return true;
  }
  
  /*A pawn may move to a square occupied by an opponent's piece
    which is diagonally in front of it on an adjacent file*/
  if((end_rank == start_rank - 1) &&
     ((end_file == start_file + 1)||
      (end_file == start_file - 1)) &&
     (!cb->square_empty(end))){
    return true;   
  }
  return false;
}


//-----------------------------ROOK FUNCTIONS---------------------------------

Rook::Rook(string _position) : ChessPiece(_position){
  piece = "Rook";
}

Rook::~Rook(){}


bool Rook::movement_legal(string start, string end, ChessBoard* cb){

  char start_file = start.at(0), end_file = end.at(0);
  char start_rank = start.at(1), end_rank = end.at(1);

  
  if (start == end){
    cout << colour <<"'s " << piece
	 << " is already at " << end <<endl;
    return false;
  }

  if( same_colour(start, end, cb)){
    return false;
  }
  /*The Rook can move any number of squares along any file or
    rank but may not jump over pieces*/
  if(((start_file == end_file)||(start_rank == end_rank))&&
     (clear_path(start, end, cb))){
    return true;
  }else{
    return false;
  }    
}




//---------------------------KNIGHT FUNCTIONS---------------------------------
Knight::Knight(string _position) : ChessPiece(_position){
  piece = "Knight";
}

Knight::~Knight(){}

bool Knight::movement_legal(string start, string end, ChessBoard* cb){
 
  int start_file = static_cast<int>(start.at(0));
  int end_file = static_cast<int>(end.at(0));
  int start_rank = static_cast<int>(start.at(1));
  int end_rank = static_cast<int>(end.at(1));
  
  
  if( same_colour(start, end, cb)){
    return false;
  }
 
  if (start == end){
    cout << colour <<"'s " << piece
	 << " is already at " << end <<endl;
    return false;
  }
  
  /*The knight can move two squares horizontally and one 
   vertically or two vertically and one horizontally, it can 
   jump over other pieces.*/
  if((abs(end_file - start_file) == 2 &&
	    abs(end_rank - start_rank) == 1)||
	   (abs(end_rank - start_rank) == 2 &&
	    abs(end_file - start_file) == 1)){
    return true;
  }else{
    return false;
  }
}


//---------------------------BISHOP FUNCTIONS---------------------------------

Bishop::Bishop(string _position) : ChessPiece(_position){
  piece = "Bishop";
}

Bishop::~Bishop(){}

bool Bishop::movement_legal(string start, string end,  ChessBoard* cb){
  
  int start_file = static_cast<int>(start.at(0));
  int end_file = static_cast<int>(end.at(0));
  int start_rank = static_cast<int>(start.at(1));
  int end_rank = static_cast<int>(end.at(1));

  int file_difference = end_file - start_file;
  int rank_difference = end_rank - start_rank;
 
  if (start == end){
    cout << colour <<"'s " << piece
	 << " is already at " << end <<endl;
    return false;
  }

  if( same_colour(start, end, cb)){
    return false;
  }
  
  /*The bishop can move any number of squares diagonally, but
    may not leap over other pieces.*/
  if(abs(file_difference) == abs(rank_difference) &&
     clear_path(start, end, cb)){
    return true;
  }else{
    return false;
  }

}

//---------------------------QUEEN FUNCTIONS---------------------------------

Queen::Queen(string _position) : ChessPiece(_position){
  piece = "Queen";
}

Queen::~Queen(){}

bool Queen::movement_legal(string start, string end,  ChessBoard* cb){
 
  char start_file = start.at(0), end_file = end.at(0);
  char start_rank = start.at(1), end_rank = end.at(1);
  
  int file_difference = end_file - start_file;
  int rank_difference = end_rank - start_rank;

  if (start == end){
    cout << colour <<"'s " << piece
	 << " is already at " << end <<endl;
    return false;
  }

  if( same_colour(start, end, cb)){
    return false;
  }

  /*The queen combines the power of the rook and bishop and can move 
    any number of squares along rank, file, or diagonal, but
    it may not leap over other pieces.*/
  if(((abs(file_difference) == abs(rank_difference))||
      (start_file == end_file)||
      (start_rank == end_rank))&& clear_path(start, end, cb)){
    return true;
  }else{
    return false;
  }
  
}

//-----------------------------KING FUNCTIONS---------------------------------

King::King(string _position) : ChessPiece(_position){
  piece = "King";
}

King::~King(){}

bool King::movement_legal(string start, string end, ChessBoard* cb){
  
  char start_file = start.at(0), end_file = end.at(0);
  char start_rank = start.at(1), end_rank = end.at(1);

  int file_difference = end_file - start_file;
  int rank_difference = end_rank - start_rank;
  
  
  if (start == end){
    cout << colour <<"'s " << piece
	 << " is already at " << end <<endl;
    return false;
  }

  if( same_colour(start, end, cb)){
    return false;
  }

  /* The king moves one square in any direction.*/
  if((abs(file_difference) == 0 ||
      abs(file_difference) == 1) &&
     (abs(rank_difference) == 0 ||
      abs(rank_difference) == 1)){
    
    return true;
  }else{
    return false;
  } 

  
}

