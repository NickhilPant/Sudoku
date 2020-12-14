#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;
vector<vector<int>> generateBoard() {
	vector<vector<int>> board = {


	/*	{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0}*/
		{7,8,0,4,0,0,1,2,0},
		{6,0,0,0,7,5,0,0,9},
		{0,0,0,6,0,1,0,7,8},
		{0,0,7,0,4,0,2,6,0},
		{0,0,1,0,5,0,9,3,0},
		{9,0,4,0,6,0,0,0,5},
		{0,7,0,3,0,0,0,1,2},
		{1,2,0,0,0,7,4,0,0},
		{0,4,9,2,0,6,0,0,7}
	};

	return board;
}

void printBoard(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (j == 0) {
				cout << "| ";
			}
			cout << v[i][j] << " ";
			if ((j + 1) % 3 == 0) {
				cout << "| ";
			}
		}
		if ((i + 1) % 3 == 0) {
			cout << endl;
			cout << "- - - - - - - - - - - -";
		}
		cout << endl;

	}


}

bool isComplete(vector<vector<int>> v) {
	for (auto x : v) {
		for (auto y : x) {
			if (y == 0) {
				return false;
			}
		}
	}
	return true;
}

pair<int, int> findEmpty(vector<vector<int>> board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == 0) {
				pair<int, int> location(i, j);
				return location;
			}
		}
	}
}

bool isValid(vector<vector<int>> board, int num, int row, int col) {
	//checks the entire row
	for (int i = 0; i < board[col].size(); i++) {
		if (board[row][i] == num) {
			return false;
		}
	}

	//check column 
	for (int i = 0; i < board.size(); i++) {
		if (board[i][col] == num) {
			return false;
		}
	}
	
	//check 3x3 grid
	int bRow;
	int bCol;
	int rstart;
	int rend;
	int cstart;
	int cend;
	if ((row / 3) == 0) {
		rstart = 0;
		rend = 3;
	}
	else if ((row / 3) == 1) {
		rstart = 3;
		rend = 6;
	}
	else if ((row / 3) == 2) {
		rstart = 6;
		rend = 9;
	}
	//cols
	if ((col / 3) == 0) {
		cstart = 0;
		cend = 3;
	}
	else if ((col / 3) == 1) {
		cstart = 3;
		cend = 6;
	}
	else if ((col / 3) == 2) {
		cstart = 6;
		cend = 9;
	}

	for (int i = rstart; i < rend; i++) {
		for (int j = cstart; j < cend; j++) {
			if (board[i][j] == num) {
				return false;
			}
		}
	}
	return true;

}

bool solve(vector<vector<int>> &board) {
	if (isComplete(board)) {
		return true;
	}
	pair<int, int> p = findEmpty(board);
	int row = p.first;
	int col = p.second;
	for (int i = 1; i < 10; i++) {
		if (isValid(board, i, row, col)) {
			board[row][col] = i;
			if (solve(board)) {
				return true;
			}
			if (!isComplete(board))
				board[row][col] = 0;
		}
		
	}
	return false;

}



vector<vector<int>> createBoard() {
	vector<vector<int>> temp;
	return temp;
}




int main() {
	srand(time(NULL));
	/*while (!createBoard()) {
		createBoard();
	}*/
	vector<vector<int>> board = generateBoard();
	printBoard(board);
	cout << endl;
	cout << endl;
	solve(board);
	cout << endl;
	cout << endl;
	printBoard(board);
	//if (!isComplete(board)) {
	//	pair<int, int> p = findEmpty(board);
	//	cout << " the x coordinate: " << p.first << "The y cooridnate is: "<< p.second << endl;
	//}


	return 0;

}