#pragma once
#include <iostream>

// Command interface
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// Concrete command classes
class HelloCommand : public Command {
public:
    void execute() override {
        std::cout << "Hello, world!" << std::endl;
    }
};

class GreetCommand : public Command {
public:
    void execute() override {
        std::string name;
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Hello, " << name << "!" << std::endl;
    }
};

class ExitCommand : public Command {
public:
    void execute() override {
        std::cout << "Exiting the CLI." << std::endl;
        exit(0);
    }
};
