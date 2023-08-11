#include "maze.h"

int main() {

	Maze maze(10,10);
	maze.printMaze();
	Position start = maze.getStartPosition();

	vector<string> moves = maze.getPossibleMoves(start);

	for (string move : moves) {
		cout << move << endl;
	}

	string str = maze.getData();

	cout << str;

	Maze n(str);

	n.printMaze();

	cout << "1";



	return 0;
}