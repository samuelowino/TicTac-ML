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

/**
 * Maps the specified cell index with the player code
 *
 * **/
void update_board_state(const string cell_index[3][3],const char& player_code);

void outline_strategy_to_machine_player(const string tic_tac_board_state[3][3]);

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

int validate_move(const char  move[2], const string tic_tac_board_state[3][3]);

/**
*Draws the board in its updated state on screen when called
*@param board_state 3-D matrix
***/
void draw_board(const string tic_tac_board_state[3][3]);

void get_player_move();

void updateBoard(string slected_point);

char human_player_code = 'X';

char machine_player_code = 'O';

char player_move[6];

string board_state[3][3] = {
	{"0,0","0,1","0,2"},
	{"1,0","1,1","1,2"},
	{"2,0","2,1","2,2"}
};


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

	validate_move(player_move, board_state);

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

int validate_move(const char move[6], const string board_state[3][3],char& player_code){
	cout<<move[1]<<endl;
	string existing_value;
	/**
	 * Check if index is used; if used warn the user and re-run game play
	 * if not used; call update_board_state(cell_index, and value to write)
	 * **/
	
	for(int i = 0; i<3;i++){
	//column
		
		for(int j = 0; j<3;j++){
			//row
			if(j = move[2] && i = move[0]){
				if(board_state[i][j] != "X" && board_state[i][j] != "O"){
					update_board_state(board_state[i][j],player_code);
				}else
					cout<<"This index is already used, try a diffrent cell"<<endl;
				break;
			}		


		}
	}

	/**

	if(move[1] == '0'){
		existing_value = board_state[0][0];
		cout<<"Existing value == " <<existing_value;
	}else if(move[1] == '1'){
		existing_value = board_state[0][1];
		cout<<"Existing value == "<< existing_value;
	}
	else if(move[1] == '2'){
		existing_value = board_state[0][2];
		cout<<"Val =="<< existing_value;
	}
	else if (move[1] == '3'){
		existing_value = board_state[1][0];
		cout<<"val =="<< ex
	}
	else if (move[1] == '4'){
	}
	else if (move[1] == '5'){
	}
	else if (move[1] == '6'){
	}
	else if (move[1] == '7'){
	}
	else if (move[1] == '8'){
	}else
		cout<<"I dont know"; **/

}
