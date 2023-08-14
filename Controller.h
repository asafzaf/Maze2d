#pragma once
#include <map>

#include "Observer.h"
#include "maze.h"
#include "Command.h"
#include "mazeCompression.h"


using namespace std;

class Controller : public Observer {
private:
    Model* mymodel;
    MazeCompression* compress;
    //friend class CLI;
    friend class Command;

    map<string, Command*> commands;


public:
    Controller(Model* model) : Observer() {
        mymodel = model;
        compress = new MazeCompression();
        DirCommand* dir = new DirCommand();
        GenerateMazeCommand* generatemaze = new GenerateMazeCommand(model);
        DisplayCommand* display = new DisplayCommand(model);
        SaveMazeCommand* savemaze = new SaveMazeCommand(model, compress);
        LoadMazeCommand* loadmaze = new LoadMazeCommand(model, compress);
        MazeSizeCommand* mazesize = new MazeSizeCommand(model);
        FileSizeCommand* filesize = new FileSizeCommand();


        ExitCommand* exit = new ExitCommand();

        commands["dir"] = (dir);
        commands["generate maze"] = (generatemaze);
        commands["display"] = (display);
        commands["save maze"] = (savemaze);
        commands["load maze"] = (loadmaze);
        commands["maze size"] = (mazesize);
        commands["file size"] = (filesize);


        commands["exit"] = (exit);

        //register_command("dir", make_unique<DirCommand>());
        //register_command("generate maze", make_unique<GenerateMazeCommand>());
        //register_command("display", make_unique<DisplayCommand>());
        //register_command("save maze", make_unique<SaveMazeCommand>());
        //register_command("load maze", make_unique<LoadMazeCommand>());
        //register_command("maze size", make_unique<MazeSizeCommand>());
        //register_command("file size", make_unique<FileSizeCommand>());
        ////register_command("solve", make_unique<Command>());
        //register_command("display solution", make_unique<GenerateMazeCommand>());
        //register_command("exit", make_unique<ExitCommand>());
    }

    /*void register_command(const string& command_name, unique_ptr<Command> command) {
        commands[command_name] = move(command);
    }*/
    /* virtual */void update(string message) override {}

    map<string , Command*> getCommands() { return commands; }

};

