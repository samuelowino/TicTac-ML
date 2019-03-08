#include <iostream>
#include <string>

using namespace std;

const int P1[2] = {0,0};
const int P2[2] = {0,1};
const int P3[2] = {0,2};

const int P4[2] = {2,0};
const int P5[2] = {2,1};
const int P6[2] = {2,2};

const int P7[2] = {3,0};
const int P8[2] = {3,1};
const int P9[2] = {3,2};

/**
 * This check whether one of the players
 * has won the game round, or if the players
 * are stuck in a tie.
 *
 * @returns char representing either
 * 	X - player X winds
 * 	O - O player wins
 * 	T - Players are in a tie
 * 	N - None of the players won
 * */
char check_winning_player(const char tic_tac_board_state[3][3]);

/**
 * Defines playing rules and strategies
 * to AI player
 *
 * 1. If human player has a "threat" (that is, two in a row), take the remaining square. Otherwise
 * 2. If a move "forks" to create two threats at once, play that move. Otherwise
 * 3. take the center square if it is freee. Otherwise
 * 4. if your opponent has played in a corner, take the opposite corner. Otherwise,
 * 5. take an empty corner if one exists. Otherwise
 * 6. take any empty square.
 *
 **/

/**
 * Maps the specified cell index with the player code
 *
 * **/
void update_board_state(const char cell_index[2],const char& player_code);

void outline_strategy_to_machine_player(const char tic_tac_board_state[3][3]);

/**
 * Validate move and reverse if neccessary
 * Move is invalid if the following happens;
 * 1.The cell is not empty
 * 2.The game is over
 * 3.Check turn to play
 *
 * @param string[3][3] board state
 *
 * @returns const int
 *
 * VALID_MOVE = 200
 * INVALID_MOVE = 500
 * OUT_OF_MOVES = 404
 *
 * */

bool validate_move(char usr_move, char tic_tac_board_state[3][3],char player_code);

/**
 * Utility function that converts a char
 * representing a user's move to an int[]
 * representing the matching index in the board
 * 
 * **/
int* get_move_index(char chr_move);



/**
 *
* Draws the board in its updated state on screen when called
*
* @param board_state 3-D matrix
***/
void draw_board(const char tic_tac_board_state[3][3]);

void get_player_move();

void updateBoard(int selected_point[2]);

char human_player = 'X';

char machine_player = 'O';

char player_move = '-';

int usr_move[2] = {0,0};

char board_state[3][3] = {
	{'A','B','C'},
	{'D','E','F'},
	{'G','H','I'}
};


int main(){

	cout<<"=============================== " <<endl;
	cout<<"|	TIC-TAC-TOE	     |"<<endl;
	cout<<"=============================== " <<endl;


	cout<<"Select Player Code:" <<endl;
	cout<<"Player X [X] "<<endl;
	cout<<"Player O [O] "<<endl;

	cout<<"===================================================="<<endl;
	cin.get(human_player);

	switch(human_player){
		case '0':
			cout<<"Computer | X"<<endl;
			cout<<"You are O "<<endl;
			machine_player ='X';
			human_player = 'O';
		break;

		case 'X':
			cout<<"You are [Xs]"<<endl;
			cout<<"Computer is [Os]"<<endl;
			machine_player = 'O';

		break;

		case 'x':
			cout<<"you are [Xs]"<<endl;
			cout<<"computer is [Os]"<<endl;
			machine_player = 'O';

		break;

		case 'o':
			cout<<"you are [Os]"<<endl;
			cout<<"Computer is [Xs]"<<endl;
			human_player = 'O';
			machine_player = 'X';

		case 'O':
			cout<<"You are [Os]"<<endl;
			cout<<"Computer is [Xs]"<<endl;
			machine_player = 'X';
		break;

		default:
			cout<<"Computer is [Xs]"<<endl;
			cout<<"You are [Os]"<<endl;
		break;
	}

	cout << " ============ START =============== \n"<<endl;

	draw_board(board_state);
	
	cout<<"+++++++++++++++++++++"<<endl;
	cout<<"| ROUND ONE |"<<endl;
	cout<<"*********************"<<endl;

	cout<<"======== Player Xs Move ==========="<<endl;
	get_player_move();

	bool is_move_valid = validate_move(player_move, board_state,human_player);

	if(!is_move_valid)
		cout<<"You made an invalid move"<<endl;		


}


void get_player_move(){
	cin.ignore();
	cin.get(player_move);
	cin.ignore();

	cout<<"Player Entered ["<<player_move<<endl;
}

/**
* Draws the board in its updated state on screen when called
*
* @param board_state 3-D matrix
***/
void draw_board(const char tic_tac_board_state[3][3]){

	for(int i = 0; i<3;i++){

		cout<<" ---------------------- \n";

		for(int j = 0; j<3;j++){

			cout<<" | ";

			if(tic_tac_board_state[i][j] == 'X'){
				cout<<" X ";
			}else if(tic_tac_board_state[i][j] == 'O'){
				cout<<" O ";
			}else
				cout<<" "<<tic_tac_board_state[i][j]<<" ";
		}

		cout<<" | "<<endl;
	}

	cout<<" ---------------------- \n";

	cout<<endl;
}

bool validate_move(char usr_move,char board_state[3][3],char player_code){
	
	/**
	 * Check if index is used; if used warn the user and re-run game play
	 * if not used; call update_board_state(cell_index, and value to write)
	 * **/

	int* move_index = get_move_index(usr_move);
	int x = move_index[0];
	int y = move_index[1];

	if(board_state[x][y] != 'X' && board_state[x][y] != 'O'){
		board_state[x][y] = {player_code};
		draw_board(board_state);
		return true; 
	}else
		return false;
}

int* get_move_index(char chr_move){
	
	usr_move[0] = 1;

	switch(chr_move){
		case 'A':
			usr_move[0] = 0;
			usr_move[1] = 0;
		break;
		case 'a':
		break;
		case 'B':
		break;
		case 'b':
		break;
		case 'C':
		break;
		case 'c':
		break;
		case 'D':
		break;
		case 'd':
		break;
		case 'E':
		break;
		case 'e':
		break;
		case 'F':
		break;
		case 'f':
		break;
		case 'G':
		break;
		case 'g':
		break;
		case 'H':
		break;
		case 'h':
		break;
		case 'I':
		break;
		case 'i':
		break;

	}

	return usr_move;
}
