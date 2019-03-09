#include <iostream>
#include <string>
#include "tictacheader.h"

using namespace std;


int main(){

	cout<<"=============================== " <<endl;
	cout<<"|	TIC-TAC-TOE	     |"<<endl;
	cout<<"=============================== " <<endl;


	cout<<"Select Player Code:" <<endl;
	cout<<"Player X [X] "<<endl;
	cout<<"Player O [O] "<<endl;

	cout<<"===================================================="<<endl;
	cin.get(human_player_code);

	switch(human_player_code){
		case '0':
			cout<<"Computer | X"<<endl;
			cout<<"You are O "<<endl;
			machine_player_code='X';
			human_player_code = 'O';
		break;

		case 'X':
			cout<<"You are [Xs]"<<endl;
			cout<<"Computer is [Os]"<<endl;
			machine_player_code='O';

		break;

		case 'x':
			cout<<"you are [Xs]"<<endl;
			cout<<"computer is [Os]"<<endl;
			machine_player_code='O';

		break;

		case 'o':
			cout<<"you are [Os]"<<endl;
			cout<<"Computer is [Xs]"<<endl;
			human_player_code='O';
			machine_player_code='X';

		case 'O':
			cout<<"You are [Os]"<<endl;
			cout<<"Computer is [Xs]"<<endl;
			machine_player_code='X';
		break;

		default:
			cout<<"Computer is [Xs]"<<endl;
			cout<<"You are [Os]"<<endl;
		break;
	}

	cout << " ============ START =============== \n"<<endl;

	draw_board(board_state);

	cout<<"======== Player Xs Move ==========="<<endl;
	get_player_move();
	//cin.get(player_move,2);

	validate_move(player_move, board_state,'X');

	draw_board(board_state);

//	board_state

	//define rules to machine player

	//check if one player has won

	//check tie

	//draw board before move

	//draw board after move

	//draw board at end of game with results summary

}


void get_player_move(){
	cin.ignore();
	cin.get(player_move,6);
	cout<<"Before 2nd ignore move == ["<<player_move[0]<<"] ["<<player_move[2]<<"]"<<endl;
	cin.ignore();
	cout<<"After 2nd ignore move == ["<<player_move[0]<<"] ["<<player_move[2]<<"]"<<endl;
}

/**
*Draws the board in its updated state on screen when called
*@param board_state 3-D matrix
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

int validate_move(char move[2],char board_state[3][3],char player_code){
	
	/**
	 * Check if index is used; if used warn the user and re-run game play
	 * if not used; call update_board_state(cell_index, and value to write)
	 * **/

	cout<<move[0]<<endl;

	for(int x = 0; x<3;x++){
	
		for(int y = 0; y<3;y++){
	
			if(x == move[0] && y == move[1]){
				/**if(board_state[x][y] != "X" || board_state[x][y] != "O"){
					update_board_state(board_state[x][y],player_code);
				}else
					cout<<"This index is already used, try a diffrent cell"<<endl;
				break; **/
			}


		}
	}
}

int* parse_char_move_to_int(const char chr_move){
	
	usr_move[0] = 1;

	switch(chr_move){
		case 'A':
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
