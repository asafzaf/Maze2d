#pragma once

#include <string>
#include <map>
#include <memory>

#include "Command.h"

using namespace std;

// CLI Invoker
class CLI {
private:
    istream& input;
    ostream& output;
    map<string, unique_ptr<Command>> commands;

public:
    CLI(istream& in, ostream& out) : input(in), output(out) {
        register_command("hello", make_unique<HelloCommand>());
        register_command("greet", make_unique<GreetCommand>());
        register_command("exit", make_unique<ExitCommand>());
    }

    void register_command(const string& command_name, unique_ptr<Command> command) {
        commands[command_name] = move(command);
    }

    void list_commands() {
        output << "Available commands:" << endl;
        for (const auto& pair : commands) {
            output << pair.first << ": " << endl;
        }
    }

    void start() {
        while (true) {
            string user_input;
            output << "Enter a command (type 'menu' for available commands): ";
            input >> user_input;

            if (user_input == "exit") {
                output << "Exiting the CLI." << endl;
                break;
            }
            else if (user_input == "menu") {
                list_commands();
            }
            else if (commands.find(user_input) != commands.end()) {
                commands[user_input]->execute();
            }
            else {
                output << "Command not found. Type 'menu' to see available commands." << endl;
            }
        }
    }
};