#include <iostream>
#include <vector>

// Abstract base class for command
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// Concrete classes for commands
class OpenCommand : public Command {
public:
    OpenCommand() {}
    void execute() override { std::cout << "Opening file...\n"; }
};

class SaveCommand : public Command {
public:
    SaveCommand() {}
    void execute() override { std::cout << "Saving file...\n"; }
};

// Invoker class
class Invoker {
public:
    void setCommand(Command* command) { m_command = command; }
    void executeCommand() { m_command->execute(); }
private:
    Command* m_command;
};

// Client code
int main() {
    Invoker invoker;
    Command* openCommand = new OpenCommand();
    Command* saveCommand = new SaveCommand();
    invoker.setCommand(openCommand);
    invoker.executeCommand();
    invoker.setCommand(saveCommand);
    invoker.executeCommand();
    delete openCommand;
    delete saveCommand;
    return 0;
}
