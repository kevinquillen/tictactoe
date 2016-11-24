#include <iostream>

using namespace std;

char board[3][3] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'}
};

char player = 'X';
char winner;
bool tie_found = false;
bool game_in_progress = true;

/**
 * Draws the board.
 */
void Draw() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

/**
 * Gather and validate input from player.
 */
void Input() {
	bool mark_is_accepted = false;
	int slot;

	while (!mark_is_accepted) {
		cout << "Player " << player << ", press the number where you want to mark your spot: ";
		cin >> slot;
		slot--;

		if (board[slot/3][slot%3] != 'X' && board[slot/3][slot%3] != 'O') {
		  board[slot/3][slot%3] = player;
		  mark_is_accepted = true;
		} else {
		  cout << "You cannot move there. Select another spot." << endl;
		}
	}
}

/**
 * Based on current player value, flip to the other player.
 */
void TogglePlayer() {
	if (player == 'X') {
		player = 'O';
	} else {
		player = 'X';
	}
}

void CheckWinner(char current_player) {
  // check matrix for a winner
  // there is probably a much better way to do this but for now, just make it work

  // check horizontal wins
  if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
	  game_in_progress = false;
  }

  if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
  	  game_in_progress = false;
  }

  if (board[2][0] == board[2][1] && board[0][1] == board[2][2]) {
	  game_in_progress = false;
  }

  // check vertical wins
  if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
  	  game_in_progress = false;
  }

  if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
	  game_in_progress = false;
  }

  if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
      game_in_progress = false;
  }

  // check diagonal wins
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
	  game_in_progress = false;
  }

  if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
	  game_in_progress = false;
  }

  if (!game_in_progress) {
	  winner = current_player;
  }
}

void CheckTie() {
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
		if (board[i][j] != 'X' && board[i][j] != 'O') {
			tie_found = false;
			break;
		}
	}
  }
}

int main() {
	cout << "Tic Tac Toe!" << endl << endl;

	// initial board draw
	Draw();

	cout << endl;

	// game loop
	do {
		Input();
		Draw();
        CheckWinner(player);
        CheckTie();
		TogglePlayer();
	} while (game_in_progress);

	// if winner found or tie.... need some logic here
	if (winner) {
		cout << "That's game! Tic tac toe! Congratulations player '" << winner << "' is the winner!";
	}

	if (tie_found) {
		cout << "Its a tie! Game over! Neither player wins.";
	}

	cout << endl << endl;

	return 0;
}

