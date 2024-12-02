#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class CommandWords {
private:
  //vector of const char* to hold the possible commands list
  vector<const char*> cmd;

public:
  CommandWords(); //constructor

  bool isCommand(const char* aString); //check if given string is a valid command
  void showAll(); //print out all possible commands
};

#endif
