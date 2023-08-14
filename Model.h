#pragma once
#include <map>

#include "Observer.h"
#include "maze.h"
#


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

    void printMazeSize(string name) {
        cout << "Maze '" << name << "' size in memory is - " << sizeof(mazes[name]) << " bytes." << endl;
    }

    void printMazesNames() {
        cout << "Printing Maze:" << endl;
        cout << "----------------" << endl;
        cout << "Avaliable mazes:" << endl;
        for (auto const& pair : mazes) {
            cout << "- " << pair.first << endl;
        }
    }

    bool checkMaze(string name) {
        map<string, Maze*>::iterator it;
        it = mazes.find(name);
        if (it != mazes.end()) {
            return true;
        }
        else return false;
    }

    Maze* getMaze(string name) {
        return mazes[name];
    }
};