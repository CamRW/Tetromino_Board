// For implementation with Board.h and Tetromino.cpp

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Board.h"
#include "Tetromino.h"
using namespace std;

//Constructor
/*Board::Board (int sx, int sy)
{ size_x = sx;
  size_y = sy;
};*/

//Add a Tetromino
void Board::addTetromino(char type, int x, int y, int orientation) 
{ Tetromino *T;

  T = Tetromino::makeTetromino(type,x,y,orientation);
//  tList.push_back(T);

  if (fits_on_board(*T) == 0) { throw invalid_argument("does not fit on the board"); }
  
   for (int i = 0; i < tList.size(); i++) {
    if (T -> Tetromino::overlap(*tList.at(i)) == 1) {throw invalid_argument("overlap"); }
}
  tList.push_back(T);
};

//Fits on Board
bool Board::fits_on_board(const Tetromino &t) const
{ 
  int i;
  for (i=0; i<4; i++) {
  if (size_x >= t.getX(i) && size_y >= t.getY(i)) {  return 1; }                     
   
  else{                  
  return 0;}}
;};

//Draw
void Board::draw(void) const
{
cout <<"<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"no\"?>"<< endl;
cout <<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" "<< endl;
cout <<"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"> "<< endl;
cout <<"<svg width=\"570\" height=\"570\" viewBox=\"0 0 550 550\" "<< endl;
cout <<"xmlns=\"http://www.w3.org/2000/svg\" " << endl;
cout <<"xmlns:xlink=\"http://www.w3.org/1999/xlink\" >" << endl;
cout <<"<g transform=\"matrix(1,0,0,-1,50,550)\">" << endl;

cout <<"<rect fill=\"white\" stroke=\"black\" x=\"0\" y=\"0\"  width=\"" << size_x*50 << "\" height=\"" << size_y*50 << "\"/>" << endl;
//Draw Tetrominos
for  (int j = 0; j < tList.size(); j++) {
      tList.at(j) -> Tetromino::draw(); }
cout << "</g>" << endl;
cout << "</svg>" << endl;
};
