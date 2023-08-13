#pragma once

#include "mazeGenerator.h"

class SimpleMazeGenerator : public MazeGenerator {
	int X;
public:
	SimpleMazeGenerator(int x) {
		X = x;
	};
	Maze* generate(string maze_name, int row_size, int col_size) {
		Maze* temp = new Maze(maze_name, row_size, col_size);
		return temp;
	}
};