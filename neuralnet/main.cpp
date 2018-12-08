#include <iostream>

class Board {
public:
	Board() {

	};
	// Board(int h, int w);
	bool winner(int player) {
		for(int i = 0; i < 6; i++) {
			int run = 0;
			for(int j = 0; j < 7; j ++) {
				if(board_[i][j] == player)
					run ++;
				else
					run = 0;
				if(run == 4)
					return true;
			}
		}

			// verticals
		for( int j = 0; j < 7; j++) {

			int run = 0;
			for(int i = 0; i < 6; i ++) {
				if(board_[i][j] == player)
					run ++;
				else
					run = 0;
				if(run == 4)
					return true;
			}
		}

		 // diagonals
		for(int x  = 0; x < 4; x++) {
			for(int y = 3; y < 6; y++) {
				if(board_[x][y] == player && board_[x+1][y-1] == player && board_[x+2][y-2] == player && board_[x+3][y-3] == player)
					return true;
			}
		}

		// check \ diagonal spaces
		for(int x = 0; x < 4; x++) {
			for(int y = 0; y < 3; y ++)
				if(board_[x][y] == player && board_[x + 1][y + 1] == player &&
					board_[x + 2][y + 2] == player &&
					board_[x + 3][y + 3] == player)
						return true;
		}

		return false;
	}

	void winnerCheck() {
		if(winner(1))
			std::cout << "Winner 1" << std::endl;
		if(winner(2))
			std::cout << "Winner 2" << std::endl;
	}

	bool drop(int col, int player) {
		if(board_[5][col] != 0) {
			return false;
		}
		for(int i = 0; i < 6; i++) {
			if(board_[i][col] == 0)
				board_[i][col] = player;
		}
		winnerCheck();
		return true;
	}

	void print() {
		std::string s = "";
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 7; j++) {
				s += board_[5-i][j];
			}
			s += '\n';
		}
		std::cout << s << std::endl;
	}



private:
	int h_ = 6;
	int w_ = 7;
	int board_[6][7];
};

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}