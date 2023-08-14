#pragma once
#include <map>

#include "Observer.h"
#include "maze.h"


class Model : public Subject {
private:
    friend class Command;
    map<string, Maze*> mazes;
public:
    Model(string m) : Subject(m) {}

    void addMaze(string name, Maze* maze) {
        mazes[name] = maze;
        cout << "Maze '" << name << "' added successfully" << endl;
    }
    void removeMaze(string name) {
        mazes.erase(name);
        cout << "Maze '" << name << "' removed successfully" << endl;
    }
    void printMaze(string name) {
        cout << "Printing Maze: " << name << endl;
        mazes[name]->printMaze();
    }
};