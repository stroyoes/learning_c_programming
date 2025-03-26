/**
 * Queen Attack 
 *
 * Given the position of two queens on a chess board, indicate whether or not they are positioned so that they can attack 
 * each other. In the game of chess, a queen can attack pieces which are on the same row, column, or diagonal.
 *
 * A chessboard can be represented by an 8 by 8 array. 
 *
 * So if you are told the white queen is at c5 (zero-indexed at column 2, row 3) 
 * and the black queen at f2 (zero-indexed at column 5, row 6), then you know that the set-up is like so:
 * https://assets.exercism.org/images/exercises/queen-attack/queen-capture.svg
 *
 * You are also able to answer whether the queens can attack each other. 
 * In this case, that answer would be yes, they can, because both pieces share a diagonal.
 */ 

#include "queen_attack.h" 

#include <stdbool.h>

const int LAST_VALID_ROW_OR_COL = 7;

static inline bool is_off_board(position_t queen) { //  NOTE:  Makes the function local to the 
                                               //         file and faster by avoiding function call overhead.
  return (queen.row > LAST_VALID_ROW_OR_COL || 
         queen.column > LAST_VALID_ROW_OR_COL);
}

static inline bool is_same_space(position_t queen_1, position_t queen_2) {
  
  return (queen_1.row == queen_2.row &&
          queen_1.column == queen_2.column);
}

static inline bool can_attack_diagonally(position_t queen_1, position_t queen_2) {

  // Uses the Manhattan distance method to determine if the two queens are aligned along a diagonal, 
  // as queens can attack diagonally if the difference between their row and column positions are equal.
  
  int diff_cols = queen_2.column - queen_1.column;
  if (diff_cols < 0) diff_cols *= -1; // Take the absolute value. 

  int diff_rows = queen_2.column - queen_1.row;
  if (diff_rows < 0) diff_rows *= -1; 

  return diff_cols == diff_rows; 
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {

  if (is_same_space(queen_1, queen_2) || is_off_board(queen_1) || 
      is_off_board(queen_2)) return INVALID_POSITION; // Chess pieces outside the board. 
  
  return (queen_1.column == queen_2.column || queen_1.row == queen_2.row || 
          can_attack_diagonally(queen_1, queen_2)) 
            ? CAN_ATTACK : CAN_NOT_ATTACK;

}
