#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int rows = 10;
const int cols = 10;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Cell {
private:
    int row;
    int col;
    bool visited = false;
    bool walls[4] = { true, true, true, true }; // Up, Down, Left, Right
public:
    Cell(int Row, int Col) : row(Row), col(Col), visited(false) {}
    bool getVisited() { return visited; }
    void setVisited(bool Visited) { visited = Visited; }
    bool getWall(Direction dir) {
        switch (dir)
        {
        case UP:
            return (walls[0] == true);
            break;
        case DOWN:
            return (walls[1] == true);
            break;
        case LEFT:
            return (walls[2] == true);
            break;
        case RIGHT:
            return (walls[3] == true);
            break;
        default:
            break;
        }
    }
    void setWall(Direction dir, bool isWall) {
        switch (dir)
        {
        case UP:
            walls[0] = isWall;
            break;
        case DOWN:
            walls[1] = isWall;
            break;
        case LEFT:
            walls[2] = isWall;
            break;
        case RIGHT:
            walls[3] = isWall;
            break;
        default:
            break;
        }
    }
};

class MazeGenerator {
private:
    vector<vector<Cell>> grid;
    stack<pair<int, int>> backtrackStack;

public:
    MazeGenerator(int rows, int cols) {
        grid = vector<vector<Cell>>(rows, vector<Cell>(cols, Cell(rows, cols)));
        srand(time(0)); // Seed the random number generator
        generateMaze(0, 0); // Generate maze starting from (0, 0)
    }

    void generateMaze(int row, int col) {
        grid[row][col].setVisited(true);

        vector<Direction> directions = { UP, DOWN, LEFT, RIGHT };
        random_shuffle(directions.begin(), directions.end());

        for (Direction dir : directions) {
            int newRow = row;
            int newCol = col;

            if (dir == UP && row > 0) {
                newRow--;
            }
            else if (dir == DOWN && row < rows - 1) {
                newRow++;
            }
            else if (dir == LEFT && col > 0) {
                newCol--;
            }
            else if (dir == RIGHT && col < cols - 1) {
                newCol++;
            }

            if (!grid[newRow][newCol].getVisited()) {
                // Knock down the wall between current cell and new cell
                if (dir == UP) {
                    grid[row][col].setWall(UP, false);
                    grid[newRow][newCol].setWall(DOWN, false);
                }
                else if (dir == DOWN) {
                    grid[row][col].setWall(DOWN, false);
                    grid[newRow][newCol].setWall(UP, false);
                }
                else if (dir == LEFT) {
                    grid[row][col].setWall(LEFT,false);
                    grid[newRow][newCol].setWall(RIGHT, false);
                }
                else if (dir == RIGHT) {
                    grid[row][col].setWall(RIGHT, false);
                    grid[newRow][newCol].setWall(LEFT, false);
                }

                backtrackStack.push(make_pair(row, col));
                generateMaze(newRow, newCol);
            }

        }
    }
    void printMaze(int max_rows, int max_cols) {
        for (int i = 0; i < max_rows; i++) {
            for (int j = 0; j < max_cols; j++) {
                //cout << " ";
                if (i == 0) cout << "#";
                else if (i == max_rows) cout << "#";
                else if (j == 0) cout << "#";
                else if (j == max_cols) cout << "#";
                else if (grid[i][j].getWall(UP)) cout << "#";
                else cout << " ";
                //cout << " ";
                if (grid[i][j].getWall(LEFT)) cout << "#";
                else cout << " ";
            }
            cout << endl;
        }
    }
};