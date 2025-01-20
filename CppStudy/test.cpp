#include <iostream>
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

enum Direct {
	RIGHT = 0,
	DOWN,
	LEFT,
	UP
};

bool CanGo(int y, int x) {
	if (x < 0 || x >= N) {
		return false;
	}
	else if (y < 0 || y >= N){
		return false;
	}
	else if (board[y][x] > 0) {
		return false;
	}
	return true;
}

void SetBoard() {
	int num = 1;
	int x = 0;
	int y = 0;
	int dir = 0;

	while (true) {
		board[y][x] = num;

		if (num == N * N)
			break;

		int dirX[4] = { 1, 0, -1, 0 };
		int dirY[4] = { 0, 1, 0, -1 };

		int nextX;
		int nextY;

		nextX = x + dirX[dir];
		nextY = y + dirY[dir];

		if (CanGo(nextY, nextX)) {
			x = nextX;
			y = nextY;
			num++;
		}
		else {
			dir = (dir + 1) % 4;
		}
		
	}

}

void PrintBoard() {
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			std::cout << std::setfill('0') << std::setw(2) << board[y][x] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::cin >> N;

	SetBoard();

	PrintBoard();


	return 0;
}