
class Command {
  Command::Command(char* firstWord, char* secondWord) {
    this->firstWord = new char[strlen(firstWord) + 1]; //convert to cstring of needed size
    strcpy(this->firstWord, firstWord); //copy the passed in first word to our object
    this->secondWord = new char[strlen(secondWord) + 1];
    strcpy(this->secondWord, secondWord);

    commandWord = firstWord;
  }

  Command::~Command() { //destructor
    delete[] firstWord;
    delete[] secondWord;
  }

  char* getFirstWord() {
    return firstWord;
  }

  char* getSecondWord() {
    return secondWord;
  }

  bool isUnknown() { //true if command is null
    return (firstWord == null);
  }

  bool hasSecondWord() { //true if there is a second word
    return (secondWord != null);
  }
}

