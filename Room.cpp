#include "Room.h"
#include <cstring>
#include <iostream>

Room::Room(char* description) { //Constructor
  this->description = new char[strlen(description) + 1];
  strcpy(this->description, description)
}

Room::~Room() { //Destructor
  delete[] description;

  for (auto item : items) {
    delete item;
  }
}

void Room::setExit(char* direction, Room* neighbor) { //Set exit to neighbor
  exits[direction] = neighbor;
}

char* Room::getShortDescription() { //Get short desc
  char* result = new char[strlen(description) + 1];
  strcpy(result, description);
  return result;
}

char* Room::getLongDescription() { //Get long desc
  //create base
  int baseLength = strlen("You are in ") + strlen(description) + (strlen(".\n") + 1; //find needed length
  char* result = new char[baseLength]; //create cstring
  strcpy(result, "You are in ");
  strcat(result, description);
  strcat(result, ".\n")

  //append exit string
  char* exitString = getExitString();
  int finalLength = baseLength + strlen(exitString) + 1;
  char* finalResult = new char[finalLength];
  strcpy(finalResult, result);
  strcpy(finalResult, exitString);

  delete[] result;
  delete[] exitString;
  return finalResult;								  //a
								  }

char* Room::getExitString() {
  char* returnString = "Exits:";
  for (auto exit = exits.begin(); exit != exits.end();) {
    //returnString
  }
}
