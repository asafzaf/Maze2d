#pragma once

#include "mazeGenerator.h"

class SimpleMazeGenerator : public MazeGenerator {
	Maze* generate(int row_size, int col_size) {
		Maze* temp = new Maze(row_size, col_size);
		return temp;
	}
};