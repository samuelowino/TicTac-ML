#include <iostream>
#include <string>
#include "include/tictacheader.h"

char human_player = 'X';

char machine_player = 'O';

char player_move;

using namespace std;

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
	cin.get(player_move,2);
	cin.ignore();

	cout<<"Player Entered ["<<player_move<<endl;
}

/**
* Draws the board in its updated state on screen when called
* @param board_state 3-D matrix
*
**/

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

//return  true if any row is crossed with simmilar player moves
bool row_crossed(char board_state[][3]){
	for ( int i=0; i<3; i++){
	if( board_state[i][0] == board_state[i][1] && 
		board_state[i][1] == board_state[i][2] && 
		board_state[i][0] !=' '){
		return (true);
		}else
		return (false);		
	}
	
}

//return true if any of the columns is crossed with simmilar player moves
bool column_crossed( char board_state[][3]){
	for ( int i=0; i<3; i++){
	if( board_state[0][i] == board_state[1][i] &&
		board_state[1][i] == board_state[2][i] &&
		board_state[0][i] !=' '){
		return (true);
		}else
		return (false);
	}
}

/** 
 * check if any of the diagnals has 3 
 * similar board labels **/

bool diagonal_crossed(char board_state[][3]){
		if(board_state[0][0] == board_state[1][1] &&
		board_state[1][1] == board_state[2][2] &&
		board_state[0][0]  !=' '){
			return (true);
			}else
			return (false);
 
		if(board_state[0][2] == board_state[1][1] &&
			board_state[1][1] == board_state[2][0] &&
			board_state[0][2] !=' '){
			return (true);
			}else
			return (false);
	
}
//check if game is over
bool is_game_over(char board_stat){
	return(row_crossed(board_state) || column_crossed(board_state) ||
		diagonal_crossed(board_state) );
}
int* get_move_index(char chr_move){
	
	usr_move[0] = 1;

	switch(chr_move){
		case 'A':
			usr_move[0] = 0;
			usr_move[1] = 0;
		break;

		case 'a':
			usr_move[0] = 0;
			usr_move[1] = 0;
		break;

		case 'B':
			usr_move[0] = 1;
			usr_move[1] = 0;
		break;
		case 'b':
			usr_move[0] = 1;
			usr_move[1] = 0;
		break;
		case 'C':
			usr_move[0] = 2;
			usr_move[1] = 0;
		break;
		case 'c':
			usr_move[0] = 2;
			usr_move[1] = 0;
		break;
		case 'D':
			usr_move[0] = 1;
			usr_move[1] = 0;
		break;
		case 'd':
			usr_move[0] = 1;
			usr_move[1] = 0;
		break;
		case 'E':
			usr_move[0] = 1;
			usr_move[1] = 1;
		break;
		case 'e':
			usr_move[0] = 1;
			usr_move[1] = 1;
		break;
		case 'F':
			usr_move[0] = 1;
			usr_move[1] = 2;
		break;
		case 'f':
			usr_move[0] = 1;
			usr_move[1] = 2;
		break;
		case 'G':
			usr_move[0] = 2;
			usr_move[1] = 0;
		break;
		case 'g':
			usr_move[0] = 2;
			usr_move[1] = 0;
		break;
		case 'H':
			usr_move[0] = 2;
			usr_move[1] = 1;
		break;
		case 'h':
			usr_move[0] = 2;
			usr_move[1] = 1;
		break;
		case 'I':
			usr_move[0] = 2;
			usr_move[1] = 2;
		break;
		case 'i':
			usr_move[0] = 2;
			usr_move[1] = 2;
		break;

	}

	return usr_move;
}
