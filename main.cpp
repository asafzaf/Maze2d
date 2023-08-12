#include "maze.h"
#include "mazeCompression.h"

int main() {

	MazeCompression compress;

	Maze maze(10,10);
	maze.printMaze();
	//Position start = maze.getStartPosition();

	//vector<string> moves = maze.getPossibleMoves(start);

	//for (string move : moves) {
	//	cout << move << endl;
	//}

	//string str = maze.getData();

	//cout << str;

	//Maze n(str);

	//n.printMaze();

	//cout << "1";

	compress.compress(maze);

	const string path = "output.txt";

	Maze* m = compress.decompress(path);

	m->printMaze();

	cout << "1";

	return 0;
}