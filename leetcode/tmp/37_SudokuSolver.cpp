#include "utils.h"

#define vec2dChar std::vector<std::vector<char>> 
const int N = 9;

bool isValid(vec2dInt& board, int row, int column, char num) {
	for(int i = 0; i < N; ++i) {
		if(board[row][i] == num || board[i][column] == num) {
			return false;
		}
	}

	int startRow = row - row%3; //This is how you can always chunk a range 
	int startColumn = column - column%3;

	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			if(board[startRow+i][startColumn+j] == num) {
				return false;
			}
		}
	}
			
	return true;
}



bool _solveSudoku(vec2dInt& board) {
	for(int row = 0; row < N; ++row) {
		for(int column = 0;column < N; ++column) {
			if(board[row][column] == '.') {
				for(char ch = '1'; ch <= '9'; ++ch) {
					if(isValid(board,row,column,ch))  {
						board[row][column]=ch;
					}
					if(_solveSudoku(board)) {
						return true;
					}
					board[row][column] = '.';
				}
			}
			return false;
		}
	}
	return true;
}

//TODO: revesit
const int N = 9; // Size of Sudoku grid

bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    // Check row and column
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = '.'; // Backtrack
                    }
                }
                return false; // No valid number found for this cell
            }
        }
    }
    return true; // All cells filled, Sudoku solved
}
