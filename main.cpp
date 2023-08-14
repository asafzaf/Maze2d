#include "maze.h"
#include "mazeCompression.h"
#include "SimpleMazeGenerator.h"
#include "BFS.h"
#include "Controller.h"
#include "View.h"
#include "Model.h"

int main() {


	//Graph g(6); // Create a graph with 6 vertices

	//g.addEdge(0, 1);
	//g.addEdge(0, 2);
	//g.addEdge(1, 3);
	//g.addEdge(2, 4);
	//g.addEdge(3, 4);
	//g.addEdge(3, 5);
	//g.addEdge(4, 5);

	//cout << "Breadth-First Traversal starting from vertex 0: ";
	//BFS bfs;

	//bfs.bfs(g, 2);
	string str = "start";
	Model* myModel = new Model(str);
	Controller myController(myModel);
	Controller* p = &myController;
	CLI cli(cin, cout, p);
	cli.start();

	//SimpleMazeGenerator simp(1);

	//simp.measureAlgorithmTime(100, 100);

	//cout << endl;

	//MazeCompression compress;

	//string s = "asaf";

	//Maze maze(s, 10, 10);
	//maze.printMaze();
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

	//compress.compress(maze);

	//const string path = "output.txt";

	//string name = "asaf";

	//Maze* m = compress.decompress(path, name);

	//m->printMaze();

	cout << "1";

	return 0;
}