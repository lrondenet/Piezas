#include "Piezas.h"
#include <vector>
#include <iostream>
using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
 * 
**/
Piezas::Piezas()
{
    //init board
    board.resize(3, vector<Piece>(4));
    //cout << "X turn first" << endl;
    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for (int i = 0; i < (int)board.size(); i++) {
        for (int j = 0; j < (int)board[i].size(); j++) {
            board[i][j] = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    if (column > 3 || column < 0) {
         //lose turn
        if (turn == X) {
            turn = O;
        }
        if (turn == O) {
            turn = X;
        }
        return Invalid;
    }
    for (int i = 2; i >= 0; i--) {
        cout << "TURN: " << turn << endl;
            if (board[i][column] == Blank) {
                if (turn == X ) {
                    board[i][column] = X;
                    return board[i][column];
                    turn = O;
                }

            }
            if (turn == O && board[i][column] == Blank) {
                board[i][column] = O;
                return board[i][column];
                turn = X;
            }
            if (board[i][column] == X || O) {
                //piece already there and lose turn
                if (turn == X) {
                    turn = O;
                }
                if (turn == O) {
                    turn = X;
                }
            }
    }
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    
    // if (board[row][column] == Blank) {

    // }
    if (row > 2 || row < 0) {
        return Invalid;
    }
    if (column > 3 || column < 0) {
        return Invalid;
    }
    if (board[row][column] == X) {
        return X;
    }
    if (board[row][column] == O) {
        return O;
    }
    return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == Blank) {
                return Invalid;
            }
        }
    }
    //count the rows 
    int row_one_count_X = 0;
    int row_one_count_O = 0;
    int row_two_count_X = 0;
    int row_two_count_O = 0;
    int row_three_count_X = 0;
    int row_three_count_O = 0;

    int total_row_X = 0;
    int total_row_O = 0;

    for (int j = 0; j < 4; j++) {
        if (board[2][j] == X) {
            row_one_count_X++;
        }
        if (board[2][j] == O) {
            row_one_count_O++;
        }
        if (board[1][j] == X) {
            row_two_count_X++;
        }
        if (board[1][j] == O) {
        row_two_count_O++;
        }
        if (board[0][j] == X) {
        row_three_count_X++;
        }
        if (board[0][j] == O) {
        row_three_count_O++;
        }
    }
    cout << "ROW ONE COUNT X: " << row_one_count_X << endl;
    cout << "ROW ONE COUNT O: " << row_one_count_O << endl;
    cout << "ROW TWO COUNT X: " << row_two_count_X << endl;
    cout << "ROW TWO COUNT O: " << row_two_count_O << endl;
    cout << "ROW THREE COUNT X: " << row_three_count_X << endl;
    cout << "ROW THREE COUNT O: " << row_three_count_O << endl;
    if (row_one_count_X >= row_two_count_X && row_one_count_X >= row_three_count_X) {
        total_row_X = row_one_count_X;
    }
    if (row_two_count_X >= row_one_count_X && row_two_count_X >= row_three_count_X ) {
        total_row_X = row_two_count_X;
    }
    if (row_three_count_X >= row_one_count_X && row_three_count_X >= row_two_count_X) {
        total_row_X = row_three_count_X;
    }
    if (row_one_count_O >= row_two_count_O && row_one_count_O >= row_three_count_O) {
        total_row_O = row_one_count_O;
    }
    if (row_two_count_O >= row_one_count_O && row_two_count_O >= row_three_count_O) {
        total_row_O = row_two_count_O;
    }
    if (row_three_count_O >= row_one_count_O && row_three_count_O >= row_two_count_O){
        total_row_O = row_three_count_O;
    }
    if ((row_one_count_X == row_two_count_X) && (row_two_count_X == row_three_count_X)) {
        total_row_X = row_one_count_X;
    }
    if ((row_one_count_O == row_two_count_O) && (row_two_count_O == row_three_count_O)) {
        total_row_O = row_one_count_O;
    }

    cout << "TOTAL ROW X: " << total_row_X << endl;
    cout << "TOTAL ROW O: " << total_row_O << endl;



    //count columns
    int column_one_count_X = 0;
    int column_one_count_O = 0;
    int column_two_count_X = 0;
    int column_two_count_O = 0;
    int column_three_count_X = 0;
    int column_three_count_O = 0;
    int column_four_count_X = 0;
    int column_four_count_O = 0;


    int total_column_X = 0;
    int total_column_O = 0;

    for (int j = 0; j < 3; j++) {
        if (board[j][0] == X) {
            column_one_count_X++;
        }
        if (board[j][0] == O) {
            column_one_count_O++;
        }
        if (board[j][1] == X) {
            column_two_count_X++;
        }
        if (board[j][1] == O) {
            column_two_count_O++;
        }
        if (board[j][2] == X) {
            column_three_count_X++;
        }
        if (board[j][2] == O) {
            column_three_count_O++;
        }
        if (board[j][3] == X) {
            column_four_count_X++;
        }
        if (board[j][3] == O) {
            column_four_count_O++;
        }
    }
    cout << "COLUMN ONE COUNT X: " << column_one_count_X << endl;
    cout << "COLUMN ONE COUNT O: " << column_one_count_O << endl;
    cout << "COLUMN TWO COUNT X: " << column_two_count_X << endl;
    cout << "COLUMN TWO COUNT O: " << column_two_count_O << endl;
    cout << "COLUMN THREE COUNT X: " << column_three_count_X << endl;
    cout << "COLUMN THREE COUNT O: " << column_three_count_O << endl;
    cout << "COLUMN FOUR COUNT X: " << column_four_count_X << endl;
    cout << "COLUMN FOUR COUNT O: " << column_four_count_O << endl;

    if (column_three_count_X <= column_one_count_X >= column_two_count_X) {
        if (column_one_count_X >= column_four_count_X) {
            total_column_X = column_one_count_X;
        }
    }
    if (column_three_count_O <= column_one_count_O >= column_two_count_O) {
        if (column_one_count_O >= column_four_count_O) {
            total_column_O = column_one_count_O;
        }
    }
    if (column_three_count_X <= column_two_count_X >= column_one_count_X) {
        if (column_two_count_X >= column_four_count_X) {
            total_column_X = column_two_count_X;
        }
    }
    if (column_three_count_O <= column_two_count_O >= column_one_count_O) {
        if (column_two_count_O >= column_four_count_O) {
            total_column_O = column_two_count_O;
        }
    }
    if (column_one_count_X <= column_three_count_X >= column_two_count_X) {
        if (column_three_count_X >= column_four_count_X) {
            total_column_X = column_three_count_X;
        }
    }
    if (column_one_count_O <= column_three_count_O >= column_two_count_O) {
        if (column_three_count_O >= column_four_count_O) {
            total_column_O = column_three_count_O;
        }
    }
    if (column_one_count_X <= column_four_count_X >= column_two_count_X) {
        if (column_four_count_X >= column_three_count_X) {
            total_column_X = column_four_count_X;
        }
    }
    if (column_one_count_O <= column_four_count_O >= column_two_count_O) {
        if (column_four_count_O >= column_three_count_O) {
            total_column_O = column_four_count_O;
        }
    }
    if ((column_one_count_X == column_two_count_X) && (column_two_count_X == column_three_count_X) && (column_three_count_X == column_four_count_X)) {
        total_column_X = column_one_count_X;
    }
    if ((column_one_count_O == column_two_count_O) && (column_two_count_O == column_three_count_O) && (column_three_count_O == column_four_count_O)) {
        total_column_O = column_one_count_O;
    }
    cout << "TOTAL COLUMN X: " << total_column_X << endl;
    cout << "TOTAL COLUMN O: " << total_column_O << endl;

    int winner_X = 0;
    int winner_O = 0;

    if (total_row_X > total_column_X) {
        winner_X = total_row_X;
    }
    if (total_column_X > total_row_X) {
        winner_X = total_column_X;
    }
    if(total_row_X == total_column_X) {
        winner_X = total_row_X;
    }
    if (total_row_O > total_column_O) {
        winner_O = total_row_O;
    }
    if (total_column_O > total_row_O) {
        winner_O = total_column_O;
    }
    if (total_row_O == total_column_O) {
        winner_O = total_row_O;
    }

    cout << "Winner X: " << winner_X << endl;
    cout << "Winner O: " << winner_O << endl;

    if (winner_X > winner_O) {
        return X;
    }
    if (winner_O > winner_X) {
        return O;
    }
    //if (winner_X == winner_O) {
    return Blank;
    //}

}