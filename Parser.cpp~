#include "Parser.h"
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

Parser::Parser() { //constructor
  //N/A
}

Command* Parser::getCommand() {
  char input[80];
  char* word1 = nullptr;
  char* word2 = nullptr;

  cout << "Enter a command." << endl;
  cin.get(input, 80);
  cin.ignore();

  int length = strlen(input);
  int index = 0;

  while (input[index] != '\0' && input[index] != ' ') { //add to index until space or terminating
    index++;
  }
  
  if (index > 0) { //if it existed
    word1 = new char[index + 1]; //create cstring
    for (int i = 0; i < index; i++) {
      word1[i] = input[i]; //copy in each character
    }
    word1[index] = '\0'; //add terminating char
  }

  int start = index;
  while (input[index] == ' ') {
    index++; //account for spaces
  }

  int secondWordStart = index; //save starting point of second word
  while (input[index] != '\0' && input[index] != ' ') {
    index++;
  }

  if (index > secondWordStart) { //if it existed
    word2 = new char[index - secondWordStart + 1];
    for (int i = secondWordStart; i < index; i++) {
      word2[i - secondWordStart] = input[i]; //copy in
    }
    word2[index - secondWordStart] = '\0'; // add terminating char
  }

  if (word1 != nullptr && commands.isCommand(word1)) { //if valid command
    return new Command(word1, word2);
  }
  else { //if not valid
    delete[] word1;

    if (word2 != nullptr) {
      delete[] word2;
    }
    
    return new Command(nullptr, word2);
  }
}


  
