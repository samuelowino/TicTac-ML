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
 * Utility function that converts a char[] to an int[]
 * using elements in from the input char[]
 * **/
int* parse_char_move_to_int_index(const char move[6]);



/**
 *
* Draws the board in its updated state on screen when called
*
* @param board_state 3-D matrix
***/
void draw_board(const char tic_tac_board_state[3][3]);

/**
 * Searches the board cells to 
 * determine the player move index based on the
 * selected board char value,in the range of  A... I.
 *
 * **/
int* get_move_index(char chr_move);

void get_player_move();

void updateBoard(int selected_point[2]);

int usr_move[2] = {0,0};

char board_state[3][3] = {
	{'A','B','C'},
	{'D','E','F'},
	{'G','H','I'}
};

