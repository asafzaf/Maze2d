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
private:
    Model* myModel;
public:
    DisplayCommand(Model* model) : myModel(model) {}
    void execute() override {
        myModel->printMazesNames();
        string maze_name;
        cout << "Please enter maze name: ";
        cin >> maze_name;
        cout << endl << "-----------------------" << endl;
        myModel->printMaze(maze_name);
        cout << endl << "-----------------------" << endl;
        cout << "Maze has printed successfully!" << endl;
    }
};

class SaveMazeCommand : public Command {
private:
    Model* myModel;
    MazeCompression* compress;
public:
    SaveMazeCommand(Model* model, MazeCompression* compressor) : myModel(model), compress(compressor) {}
    void execute() override {
        string filename, mazename;
        cout << "Enter maze name to save: ";
        cin >> mazename;
        cout << "Enter file name: ";
        cin >> filename;
        Maze* tempMaze = myModel->getMaze(mazename);
        //compress maze and save it with the name
        compress->compress(tempMaze, filename);
        cout << endl << "-----------------------" << endl;
        cout << "Maze saved successfully!" << endl;
    }
};

class LoadMazeCommand : public Command {
private:
    Model* myModel;
    MazeCompression* compress;
public:
    LoadMazeCommand(Model* model, MazeCompression* compressor) : myModel(model), compress(compressor) {}
    void execute() override {
        string directoryPath = "/";
        string filename, mazename;
        cout << "List of files: " << endl;
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                std::cout << "File: " << entry.path() << endl;
            }
        }
        cout << "Enter file name (*.txt): ";
        cin >> filename;
        filename += ".txt";
;        cout << "Enter new maze name: ";
        cin >> mazename;
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                std::cout << "File: " << entry.path() << endl;
            }
        }
        cout << "Enter new maze name: ";
        cin >> mazename;
        //decompress maze and load it with the name
        Maze* tempmaze = compress->decompress(filename);
        myModel->addMaze(mazename, tempmaze);
    }
};

class MazeSizeCommand : public Command {
private:
    Model* myModel;
public:
    MazeSizeCommand(Model* model) : myModel(model) {}
    void execute() override {
        myModel->printMazesNames();
        string maze_name;
        cout << "Please enter maze name: ";
        cin >> maze_name;
        cout << endl << "-----------------------" << endl;
        myModel->printMazeSize(maze_name);
    }
};

class FileSizeCommand : public Command {
public:
    void execute() override {
        string directoryPath = "/";
        //printing the size
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                std::cout << "File: " << entry.path() << ", Size: " << fs::file_size(entry.path()) << " bytes\n";
            }
        }
    }
};

class ExitCommand : public Command {
public:
    void execute() override {
        std::cout << "Exiting the CLI." << std::endl;
        exit(0);
    }
};
