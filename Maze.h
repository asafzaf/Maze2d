#pragma once
#include <iostream>
#include <map>
#include "Cell.h"
#include <random>

using namespace std;

enum p_side {
	up,
	right,
	down,
	left
};

int random(int min, int max) {
	return min + rand() % (max - min + 1);
}

class Maze2d {
protected:
	map<int, Cell*> cells;
	int col_size;
	int row_size;
	Cell *start_point;
	Cell *curr_point;
	Cell* end_point;
	
public:
	// virtual void move(p_side side);
	int getTotalCellsSize() {
		return col_size * row_size;
	}
	Maze2d(int col, int row) {
		this->col_size = col;
		this->row_size = row;
		for (int i = 0; i < row * col; i++) {
			this->cells[i] = new Cell(i / col, i % col);
		}
		start_point = cells[col+col];
		start_point->setStatus(way);
		curr_point = cells[col+col+1];
		curr_point->setStatus(way);
		end_point = cells[row * col - 2];
		end_point->setStatus(way);
		while (curr_point != end_point) {
			curr_point = cells[random(0, row * col)];
			makeMaze(curr_point);
		}
	}
	void move(p_side side) {
		Cell* req_cell;
		switch (side)
		{
		case p_side::up:
			if (curr_point->getRow() == 0) {
				printf("Cant move - border");
				break;
			}
			req_cell = cells[(curr_point->getRow() - 1) * col_size + (curr_point->getCol())];
			if (req_cell->getStatus() == wall) {
				printf("Cant move - wall");
				break;
			}
			else {
				this->setCurrPosition(req_cell);
			}
			break;
		case p_side::right:
			if (curr_point->getCol() == col_size - 1) {
				printf("Cant move - border");
				break;
			}
			req_cell = cells[(curr_point->getRow()) * col_size + (curr_point->getCol() + 1)];
			if (req_cell->getStatus() == wall) {
				break;
			}
			else {
				this->setCurrPosition(req_cell);
			}
			break;
		case p_side::down:
			if (curr_point->getRow() == row_size - 1) {
				printf("Cant move - border");
				break;
			}
			req_cell = cells[(curr_point->getRow() + 1) * col_size + (curr_point->getCol())];
			if (req_cell->getStatus() == wall) {
				printf("Cant move - wall");
				break;
			}
			else {
				this->setCurrPosition(req_cell);
			}
			break;
		case p_side::left:
			if (curr_point->getCol() == 0) {
				printf("Cant move - border");
				break;
			}
			req_cell = cells[(curr_point->getRow()) * col_size + (curr_point->getCol()-1)];
			if (req_cell->getStatus() == wall) {
				printf("Cant move - wall");
				break;
			}
			else {
				this->setCurrPosition(req_cell);
			}
			break;
		default:
			break;
		}
	}
	Cell* getCurrPosition() {
		return curr_point;
	}
	void setCurrPosition(Cell* cell) {
		this->curr_point = cell;
	}
	Cell* getStartPosition() {
		return start_point;
	}
	void genarateWay() {
		while (curr_point != end_point) {

		}
	}
	void printMaze() {
		for (int i = 0; i < col_size * row_size; i++) {
			if (i % col_size == 0) {
				printf("\n");
			}
			if (cells[i] == curr_point) {
				printf("@");
			}
			else if(cells[i]->getStatus() == wall)
				printf("#");
			else printf(" ");
		}
	}
	
	void makeMaze(Cell* point) {
		if (check_visit(point) == false) {
			return;
		}
		else {
			int random_number = random(0,3);
			p_side new_side = p_side(random_number);
			Cell* new_point;
			switch (new_side)
			{
			case p_side::up:
				new_point = cells[(point->getRow() - 1) * col_size + (point->getCol())];
				break;
			case p_side::right:
				new_point = cells[(point->getRow()) * col_size + (point->getCol() + 1)];
				break;
			case p_side::down:
				new_point = cells[(point->getRow() + 1) * col_size + (point->getCol())];
				break;
			case p_side::left:
				new_point = cells[(point->getRow()) * col_size + (point->getCol() - 1)];
				break;
			default:
				new_point = cells[(point->getRow()) * col_size +(point->getCol())];
				break;
			}
			makeMaze(new_point);
		}
	}

	bool check_visit(Cell* cell) {
		if ((cell->getCol() != 0) && (cell->getCol() != col_size - 1)
			&& (cell->getRow() != 0) && (cell->getRow() != row_size - 1)) {
			int num_of_walls = 0;
			if (cells[(cell->getRow() - 1) * col_size + (cell->getCol())]->getStatus() == wall) { num_of_walls++; }
			if (cells[(cell->getRow() + 1) * col_size + (cell->getCol())]->getStatus() == wall) { num_of_walls++; }
			if (cells[(cell->getRow()) * col_size + (cell->getCol() - 1)]->getStatus() == wall) { num_of_walls++; }
			if (cells[(cell->getRow()) * col_size + (cell->getCol() + 1)]->getStatus() == wall) { num_of_walls++; }
			if (num_of_walls == 3) {
				cell->setStatus(way);
				return true;
			}
			else return false;
		}
		else return false;
	}
};