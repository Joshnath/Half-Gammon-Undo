//Description: Create an undo function for the game HalfGammon by using linked list to go back to a previous state of the game.
//Author: Joshua Atienza
//Date: 4/30/2025
#include <iostream>
#include <string>
#include "HalfGammonBoard.h"
#include "GameList.h"
#include "GameNode.h"
#include "mersenne-twister.h"

using namespace std;

int rollDie();

// Simulates rolling a die, choosing a result 1 to 6
// The seed function must have already been called
// Returns an int, chosen randomly, 1-6
int rollDie() {
	return chooseRandomNumber(1, 6);
}

int main() {
	// Initializes the random number generator with seed from the user
	int randSeed;
	cout << "Enter seed: ";
	cin >> randSeed;
	seed(randSeed);

	// Repeat, allows user to play multiple games
	string keepPlaying;
	do {
		// Game board used to keep track of the current game
		HalfGammonBoard board;

		//Linked List used to keep tract of previous game states
		GameList Gammon;
		
		//Adds the first state to the linked list
		Gammon.addToBeginning(board);

		// Display the board and roll dice
		board.displayBoard();
		int roll = rollDie();
		board.displayRoll(roll);
		while (!board.gameOver()) {
			// If the player has a bumped piece, then they must move that
			if (board.hasBumpedPiece()) {
				cout << "Bumped checker must move." << endl;
				if (!board.isMovePossible(roll)) {
					cout << "No move possible." << endl;
				}
				else {
					board.moveBumpedPiece(roll);
				}
			}
			else {
				// Otherwise they can move any of their pieces
				if (!board.isMovePossible(roll)) {
					// No move is possiible with their roll on the current board
					cout << "No move possible." << endl;
				}
				else {
					string movePositionString;
					bool moveSuccessful;

					// Get move from user, and make that move. Repeat loop until a valid move has been chosen
					cout << "What position would you like to move (Q to quit, U to undo)? ";
					cin >> movePositionString;
					if (movePositionString == "q" || movePositionString == "Q") {
						break;
					}
					else if (movePositionString == "u" || movePositionString == "U") {
						//Makes sure there is a state to go back to
						if(Gammon.size() > 1) {
							//Set the baord to previous state
							board = Gammon.get(0);

							//Remove the current state
							Gammon.removeFromBeginning();
							
							//Steps to show and run steps for previous board
							board.displayBoard();
							roll = rollDie();
							board.displayRoll(roll);

						}
						else {
							//Tells user undo cannot be done
							cout << "Cannot undo." << endl;
						}

						//Makes code go back to the start of the while loop
						continue;
					}

					//Save game state into a temp variable
					HalfGammonBoard prevMove = board;


					int movePosition = stoi(movePositionString);
					moveSuccessful = board.performMove(movePosition, roll);
					if (!moveSuccessful) {
						cout << "Invalid move. Try again." << endl;
						// Continue, so the user can enter input again
						// (this skips changing current player and displaying the board, rolling dice)
						continue;
					}
					else {
						//Add the game states to linked list and makes sure the only game states saved are the ones without bumps
						Gammon.addToBeginning(prevMove);
					}
				}
			}

			// Switch who the current player is
			board.changePlayer();

			if (!board.gameOver()) {
				// Display the board and roll dice
				board.displayBoard();
				roll = rollDie();
				board.displayRoll(roll);
			}
		}

		// If we have left the loop, someone has won--determine whether it's X or O
		if (board.isXWin()) {
			cout << "Player X Wins!" << endl;
		}
		else if (board.isOWin()) {
			cout << "Player O Wins!" << endl;
		}

		cout << "Do you want to play again (y/n)? ";
		cin >> keepPlaying;
	} while (tolower(keepPlaying.at(0)) == 'y');
}