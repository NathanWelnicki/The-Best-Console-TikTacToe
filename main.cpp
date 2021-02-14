#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

char board[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8'};
int selected_slot;
bool end_game = false;
bool turn_active = false;
bool invalid_turn = false;
char invaid_turn_char;
char winner;
int turns = 0;
char current_turn;

void render_info()
{
	cout << "	" << "Console TikTacToe - By Nathan Welnicki\n\n";
	cout << "	    " << "[Player 1: X]  [Player 2: O]\n\n";
}

void render_board()
{
	cout << "		    " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
	cout << "		    " << "---------\n";
	cout << "		    " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
	cout << "		    " << "---------\n";
	cout << "		    " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n\n";
}

void check_win()
{
	
	if (board[0] == board[1] && board[0] == board[2])
	{
		winner = board[0];
		end_game = true;
	}
	if (board[0] == board[3] && board[0] == board[6])
	{
		winner = board[0];
		end_game = true;
	}
	if (board[0] == board[4] && board[0] == board[8])
	{
		winner = board[0];
		end_game = true;
	}
	if (board[1] == board[4] && board[1] == board[7])
	{
		winner = board[1];
		end_game = true;
	}
	if (board[6] == board[7] && board[6] == board[8])
	{
		winner = board[6];
		end_game = true;
	}
	if (board[2] == board[5] && board[2] == board[8])
	{
		winner = board[2];
		end_game = true;
	}
	if (board[2] == board[4] && board[2] == board[6])
	{
		winner = board[2];
		end_game = true;
	}
}

void restart()
{
	board[0] = '0'; board[1] = '1'; board[2] = '2'; board[3] = '3'; board[4] = '4'; board[5] = '5'; board[6] = '6'; board[7] = '7'; board[8] = '8';
	bool end_game = false;
	bool turn_active = false;
	char winner = NULL;
	char current_turn = NULL;
}

void end()
{
	system("CLS");
	render_board();

	if (winner == 'X') {
		cout << "	" << "Congradulations Player 1, you won!\n\n";
	}else if(winner == 'O')
	{
		cout << "	" << "Congradulations Player 2, you won!\n\n";
	}
	else 
	{
		cout << "	" << "It's a tie!\n\n";
	}
	
	cout << "	" << "Thank you for playing! To quit press ESC\n\a";
	
	char key_press = _getch();
	int ascii_value = key_press;

	if (ascii_value == 27)
	{
		system("CLS");
		cout << "	" << "quitting...";
		Sleep(500);
	}
	else {
		Sleep(60000);
	}
}

void turn()
{
	turn_active = true;
	int input;
	
	if (turns == 8) {
		end_game = true;
	}

	if (invalid_turn == true) {
		current_turn = invaid_turn_char;
	}

	if (current_turn == NULL) {
		current_turn = 'X';
	}

	if (current_turn == 'X')
	{
		cout << "	" << "It's your turn Player 1, pick a slot\n";
	}
	else
	{
		cout << "	" << "It's your turn, Player 2, pick a slot\n";
	}
	
		if (current_turn == 'X')
		{						
			cout << "		        >";
			cin >> input;
			
			if (board[input] == 'O' || board[input] == 'X') 
			{
				cout << "		    " << "Invalid slot\n";
				invalid_turn = true;
				invaid_turn_char = 'X';
				Sleep(500);
			}
			else {
				turns++;
				board[input] = 'X';
			}
			current_turn = 'O';

		}
		else if (current_turn == 'O')
		{						
			cout << "		        >";
			cin >> input;

			if (board[input] == 'X' || board[input] == 'O') {
				cout << "		    " << "Invalid slot\n";
				invalid_turn = true;
				invaid_turn_char = 'O';
				Sleep(500);
			}
			else {
				turns++;
				board[input] = 'O';
			}
			current_turn = 'X';
		}

	system("CLS");
	render_info();
	render_board();
	check_win();
	turn_active = false;
}

int main(int argc, char **argv[]) 
{
	render_info();
	render_board();

	while (turn_active == false && end_game == false)
	{
		turn();
	}

	if (end_game == true) 
	{
		end();
	}
}
