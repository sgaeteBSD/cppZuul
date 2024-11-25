#ifndef PARSER_H
#define PARSER_H

#include "CommandWords.h"
#include "Command.h"
#include <cstring>

class Parser {
 private:
    CommandWords commands; //all valid command words

 public:
    Parser();
    Command* getCommand();
    void showCommands(); //prints out valid command words
};

#endif
