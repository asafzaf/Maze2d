#include "maze.h"
#include "mazeCompression.h"
#include "SimpleMazeGenerator.h"
#include "CLI.h"
#include "BFS.h"

int main() {


	Graph g(6); // Create a graph with 6 vertices

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	cout << "Breadth-First Traversal starting from vertex 0: ";
	BFS bfs;

	bfs.bfs(g, 2);

	//CLI cli(cin,cout);
	//cli.start();

	//SimpleMazeGenerator simp(1);

	//simp.measureAlgorithmTime(100, 100);

	MazeCompression compress;

	string s = "asaf";

	Maze maze(s, 10, 10);
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