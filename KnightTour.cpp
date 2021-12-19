////
// Author: Cami Lacy
//
// Assignment: P5 Knight's Tour
//
// Description: This program accomplishes the Knight's tour with recursion. 
// The Knight's tour solves the problem if the knight piece in chess 
// can travel to every location on an 8x8 chess board without ever landing
// on a square more than once. The user does not input any data, and the
// output data(completed chessboard) is sent to the screen.
//
////

#include<iostream>
#include<iomanip>
using namespace std;

// GLOBAL VARIABLES //
int movCount = 0;
int numTries = 0;
int numBadMove = 0;
const int ROWS = 8;
const int COLS = 8;
int boardType[ROWS][COLS] = {0};


// FUNCTION PROTOTYPES //

// Prints the board
void printBoard(int argBoard[][COLS]);

// Recursively moves knight 
bool moveKnight(int row, int col, int movNum);


int main()
{

	// Welcome message
	cout << "WELCOME TO THE KNIGHT'S TOUR PROGRAM!!!\n\n";

	// BELOW PRINTS THE BOARD
	printBoard(boardType);

	// Move the knight recursively
	moveKnight(0, 0, 1);


	// BELOW PRINTS THE BOARD
	cout << "Yeehaw!!!! After " << numTries << " tries and " << numBadMove << " bad moves. It needed " << movCount << " good moves: \n\n"; 
	printBoard(boardType);



	cout << endl << endl;
	system("pause");
	return 0;
}

/*****************FUNCTION DEFINITIONS*****************/

void printBoard(int argBoard[][COLS])
{

	// Prints row by row
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{

			cout << setw(4) << boardType[i][j];

		}
		cout << endl;
	}
	cout << endl;
}



bool moveKnight(int row, int col, int movNum)
{
	
	// Increments each time function called
	++numTries;

	// Check if in bounds and spot is empty
	if ((0 <= row && row < ROWS) && (0 <= col && col < COLS) && (boardType[row][col] == 0))
	{
		// Set move number to spot
		boardType[row][col] = movNum;

		// If we've reached end condition
		if(movNum == ROWS * COLS)
		{
			movCount = movNum;
			return true;
		}

	}
	// Else don't set number
	else
	{
		return false;
	}


	// 8 potential moves //

	// rows -2 and cols +1
	if (moveKnight(row - 2, col + 1, movNum + 1))
	{
		return true;
	}

	// row -1 and cols +2
	else if (moveKnight(row - 1, col + 2, movNum + 1))
	{
		return true;
	}

	// row +1 and cols +2
	else if (moveKnight(row + 1, col + 2, movNum + 1))
	{
		return true;
	}

	// row +2 and cols +1
	else if (moveKnight(row + 2, col + 1, movNum + 1))
	{
		return true;
	}

	// row +2 and cols -1
	else if (moveKnight(row + 2, col - 1, movNum + 1))
	{
		return true;
	}

	// row +1 and cols -2
	else if (moveKnight(row + 1, col - 2, movNum + 1))
	{
		return true;
	}

	// row -1 and cols -2
	else if (moveKnight(row - 1, col - 2, movNum + 1))
	{

		return true;

	}

	// rows -2 and cols -1
	else if (moveKnight(row - 2, col - 1, movNum + 1))
	{
		return  true;
	}

	else
	{
		// If none valid then undo move
		++numBadMove;
		boardType[row][col] = 0;
		return false;
	}

}

/*

PROGRAM OUTPUT:

WELCOME TO THE KNIGHT'S TOUR PROGRAM!!!

   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0

Yeehaw!!!! After 25936254 tries and 3242001 bad moves. It needed 64 good moves:

   1  38  55  34   3  36  19  22
  54  47   2  37  20  23   4  17
  39  56  33  46  35  18  21  10
  48  53  40  57  24  11  16   5
  59  32  45  52  41  26   9  12
  44  49  58  25  62  15   6  27
  31  60  51  42  29   8  13  64
  50  43  30  61  14  63  28   7



Press any key to continue . . .


*/