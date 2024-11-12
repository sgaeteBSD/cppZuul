#include <vector>

class CommandWords {
private:
  //vector of char* to hold the possible commands list
  vector<char*> cmd;
  cmd.push_back("go");
  cmd.push_back("quit");
  cmd.push_back("help");
  cmd.push_back("inventory");
  cmd.push_back("get");
  cmd.push_back("drop");
  cmd.push_back("brew"); //this is specific to our game! brew the coffee
public:
  CommandWords() {
    //constructor
  }

  bool isCommand(char* aString) { //check if given string is a valid command
    for (int i = 0; i < cmd.size(); i++) {
      if (strcmp(cmd[i], aString) == 0) {
	return true;
      }
    }
    return false; //command not found
  }

  void showAll() {
    for (int i = 0; i < cmd.size(); i++) { //print out all possible commands
      cout << cmd[i] << ", ";
    }
    cout << endl; //end line
  }
}
