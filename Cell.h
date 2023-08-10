#pragma once

enum c_status {
	wall,
	way
};

class Cell {
private:
	int col;
	int row;
	c_status status;
	bool visited;

public:
	Cell(int Col, int Row) {
		this->col = Col;
		this->row = Row;
		this->status = wall;
		this->visited = false;
	}
	c_status getStatus() {
		return status;
	}
	void setStatus(c_status stat) {
		this->status = stat;
	}
	int getCol() {
		return col;
	}
	int getRow() {
		return row;
	}
};