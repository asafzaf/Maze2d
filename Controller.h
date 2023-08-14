#pragma once
#include <map>

#include "Observer.h"
#include "maze.h"
#include "Command.h"


using namespace std;

class Controller : public Observer {
private:
    Model* mymodel;
    //friend class CLI;
    friend class Command;

    map<string, Command*> commands;


public:
    Controller(Model* model) : Observer() {
        mymodel = model;
        DirCommand* dir = new DirCommand();
        GenerateMazeCommand* generatemaze = new GenerateMazeCommand(model);
        DisplayCommand* display = new DisplayCommand();

        commands["dir"] = (dir);
        commands["generate maze"] = (generatemaze);
        commands["display"] = (display);
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

