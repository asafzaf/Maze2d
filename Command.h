#pragma once
#include <iostream>
#include <filesystem>
#include <fstream> // implement!!!

#include "Model.h"
class Controller;
//class Model;

using namespace std;

namespace fs = std::filesystem;


// Command interface
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// Concrete command classes
class DirCommand : public Command {
public:
    void execute() override {
        string path_str;
        
        cout << "Pleasse enter a dir: ";
        cin >> path_str;
        fs::path path(path_str);

        std::vector<std::string> fileAndDirNames;

        if (fs::exists(path) && fs::is_directory(path)) {
            for (const auto& entry : fs::directory_iterator(path)) {
                if (fs::is_regular_file(entry)) {
                    fileAndDirNames.push_back("File: " + entry.path().filename().string());
                }
                else if (fs::is_directory(entry)) {
                    fileAndDirNames.push_back("Directory: " + entry.path().filename().string());
                }
            }
        }
        else {
            std::cerr << "The specified path is not a valid directory." << std::endl;
            return;
        }

        // Print the list of file and directory names
        for (const auto& name : fileAndDirNames) {
            std::cout << name << std::endl;
        }

        return;
    }
};

class GenerateMazeCommand : public Command {
private:
    Model* myModel;
public:
    GenerateMazeCommand(Model* model) : myModel(model) {}
    //GenerateMazeCommand() : myModel(NULL) {}

    void execute() override {
        string name;
        int rows, cols;
        cout << "Enter maze name: ";
        cin >> name;
        cout << "Number of rows: ";
        cin >> rows;
        cout << "Number of cols: ";
        cin >> cols;
        Maze* temp = new Maze(rows, cols);
        myModel->addMaze(name, temp);
    }
};

class DisplayCommand : public Command {
public:
    void execute() override {
        
    }
};

class SaveMazeCommand : public Command {
public:
    void execute() override {
        string filename, mazename;
        cout << "Enter maze name to save: ";
        cin >> mazename;
        cout << "Enter file name: ";
        cin >> filename;
        //looking for the maze

        //compress maze and save it with the name
    }
};

class LoadMazeCommand : public Command {
public:
    void execute() override {
        string filename, mazename;
        cout << "Enter file name (*.txt): ";
        cin >> filename;
        cout << "Enter new maze name: ";
        cin >> mazename;
        //looking for the file

        //decompress maze and load it with the name
    }
};

class MazeSizeCommand : public Command {
public:
    void execute() override {
        //looking for the maze

        //printing the size
    }
};

class FileSizeCommand : public Command {
public:
    void execute() override {
        //looking for the file

        //printing the size
    }
};

class ExitCommand : public Command {
public:
    void execute() override {
        std::cout << "Exiting the CLI." << std::endl;
        exit(0);
    }
};
