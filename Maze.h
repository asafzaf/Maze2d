#pragma once
#include <iostream>;
#include <vector>;

using namespace std;

enum c_status {
	wall,
	cell
};

enum p_side {
	up,
	right,
	down,
	left
};

class Maze2d {
	vector<int, int> Cell;
	int size;
	
	virtual void move(p_side side);
};

class Cell {
	c_status status;
};