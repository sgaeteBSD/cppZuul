#include "Command.h"
#include <cstring>

  Command::Command(char* commandWord, char* secondWord) {
    this->commandWord = new char[strlen(commandWord) + 1]; //convert to cstring of needed size
    strcpy(this->commandWord, commandWord); //copy the passed in first word to our object
    this->secondWord = new char[strlen(secondWord) + 1];
    strcpy(this->secondWord, secondWord);
  }

  Command::~Command() { //destructor
    delete[] commandWord;
    delete[] secondWord;
  }

char* Command::getCommandWord() {
    return commandWord;
  }

char* Command::getSecondWord() {
    return secondWord;
  }

bool Command::isUnknown() { //true if command is null
    return (commandWord == nullptr);
  }

bool Command::hasSecondWord() { //true if there is a second word
    return (secondWord != nullptr);
  }

