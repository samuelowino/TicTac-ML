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
char check_winning_player(const string tic_tac_board_state[3][3]);

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

void outline_strategy_to_machine_player(const string tic_tac_board_state[3][3]);

/**
 * Validate move and reverse if neccessary
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

bool validate_move(const string  move, const string tic_tac_board_state[3][3]);

/**
*Draws the board in its updated state on screen when called
*@param board_state 3-D matrix
***/
void draw_board(const string tic_tac_board_state[3][3]);

void updateBoard(string slected_point);

string human_player_code = "";

string player_move = "";

string board_state[3][3] = {
	{"P0","P4","P7"},
	{"P1","P5","P8"},
	{"P2","P6","P9"}
};


int main(){

	cout<<"=============================== " <<endl;
	cout<<"|	TIC-TAC-TOE	     |"<<endl;
	cout<<"=============================== " <<endl;


	cout<<"Select Player:" <<endl;
	cout<<"Player X [X] "<<endl;
	cout<<"Player O [O] "<<endl;

	cout<<"===================================================="<<endl;
	getline(cin,human_player_code);
	//cin>>human_player_code;

	switch(human_player_code){
		case 0:
			cout<<"Computer | X"<<endl;
			cout<<"You are O "<<endl;
		break;

		case 'X':
			cout<<"You are [Xs]"<<endl;
			cout<<"Computer is [Os]"<<endl;
		break;

		case 'O':
			cout<<"You are [Os]"<<endl;
			cout<<"Computer is [Xs]"<<endl;
		break;

		default:
			cout<<"Computer is [Xs]"<<endl;
			cout<<"You are [Os]"<<endl;
		break;
	}

	cout << " ============ START =============== \n"<<endl;

	draw_board(board_state);

	cout<<"======== Player Xs Move ==========="<<endl;
	//getline(cin,player_move);

	validate_move(player_move, board_state);

	board_state[1][1] = "X";

	draw_board(board_state);

//	board_state 

	//define rules to machine player

	//check if one player has won

	//check tie

	//draw board before move

	//draw board after move

	//draw board at end of game with results summary

}

/**
*Draws the board in its updated state on screen when called
*@param board_state 3-D matrix
***/
void draw_board(const string tic_tac_board_state[3][3]){

	for(int i = 0; i<3;i++){

		cout<<" ---------------------- \n";

		for(int j = 0; j<3;j++){

			cout<<" | ";

			if(tic_tac_board_state[i][j] == "X"){
				cout<<" X ";
			}else if(tic_tac_board_state[i][j] == "O"){
				cout<<" O ";
			}else
				cout<<" "<<tic_tac_board_state[i][j]<<" ";
		}

		cout<<" | "<<endl;
	}

	cout<<" ---------------------- \n";

	cout<<endl;
}

bool validate_move(const string move, const string tic_tac_toe_board_state[3][3]){

}
