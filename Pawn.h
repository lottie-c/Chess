#ifndef PAWN_H
#define PAWN_H

#include <string>
#include <iostream>
#include <map>
#include <stdlib.h> 
#include <string>    

using namespace std;


class Pawn : public ChessPiece{

 public: 
  Pawn(string _position);
  virtual ~Pawn();

 
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

#endif
