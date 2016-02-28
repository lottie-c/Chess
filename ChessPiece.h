#ifndef CHESSPIECE_H
#define CHESSPIECE_H


#include <string>
#include <iostream>
#include <map>
#include <stdlib.h> 
#include <string>    

using namespace std;

class ChessBoard;

class ChessPiece{
 
 protected:
  string piece;
  string colour;

  /*Function returns false if there is a piece between 
    'start' and 'end' not inclusive and true otherwise*/
  bool clear_path(string start, string end, ChessBoard* cb);

 public:

  /*Constructor for abstract class ChessPiece*/
  ChessPiece(string _position);

  /*Destructor function for ChessPiece*/
  virtual ~ChessPiece();

  /*Returns the 'colour' attribute of ChessPiece*/
  string get_colour();
  
  /*Returns 'piece' attribute of ChessPiece*/
  string get_piece();

  /*If there are pieces at both positions 'start' and 'end'
    on ChessBoard 'cb'same_colour(...) returns true if
    those pieces are of the same colour and false otherwise. */
  bool same_colour(string start, string end, ChessBoard* cb);

  /*Function returns true if moving the piece at 'start' to 
    position 'end'on ChessBoard 'cb' is a legal move in terms 
    of the pathway taken and if the pathway is clear*/
  virtual bool movement_legal(string start, string end, ChessBoard* cb) = 0;
  
};


class Pawn : public ChessPiece{

 public: 
  /*Constructor for Pawn*/
  Pawn(string _position);
 
  /*Destructor for Pawn*/
  virtual ~Pawn();

  /*See function description for ChessPiece movement_legal(...)*/
  virtual bool movement_legal(string start, string end, ChessBoard* cb);

  /*Function returns true if moving the white Pawn at 'start' to
    position 'end' on ChessBoard 'cb' is a legal move in terms 
    of pathway taken*/
  bool white_pawn_movement(string start, string end, ChessBoard* cb);

  /*Function returns true if moving the black Pawn at 'start' to
    position 'end' on ChessBoard 'cb' is a legal move in terms 
    of pathway taken*/
  bool black_pawn_movement(string start, string end, ChessBoard* cb);
};



class Rook : public ChessPiece{

 public: 

  /*Constructor for Rook*/
  Rook(string _position);
 
  /*Destructor for Rook*/
  virtual ~Rook();

  /*See function description for ChessPiece movement_legal(...)*/
  virtual bool movement_legal(string start, string end, ChessBoard* cb);
};

class Knight : public ChessPiece{

 public: 
  /*Constructor for Knight*/
  Knight(string _position);
 
  /*Destructor for Knight*/
  virtual ~Knight();

  /*See function description for ChessPiece movement_legal(...)*/
  virtual bool movement_legal(string start, string end, ChessBoard* cb);
};

class Bishop : public ChessPiece{

 public: 
  /*Constructor for Bishop*/
  Bishop(string _position);

  /*Destructor for Bishop*/
  virtual ~Bishop();

  /*See function description for ChessPiece movement_legal(...)*/
  virtual bool movement_legal(string start, string end, ChessBoard* cb);
};

class Queen : public ChessPiece{

 public: 
  /*Constructor for Queen*/
  Queen(string _position);

  /*Destructor for Queen*/
  virtual ~Queen();

  /*See function description for ChessPiece movement_legal(...)*/
  virtual bool movement_legal(string start, string end, ChessBoard* cb);
};

class King : public ChessPiece{

 public: 

  /*Constructor for King*/
  King(string _position);

  /*Destructor for King*/
  virtual ~King();

  /*See function description for ChessPiece movement_legal(...)*/
  virtual bool movement_legal(string start, string end, ChessBoard* cb);
};


#endif
