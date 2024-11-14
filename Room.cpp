#include "Room.h"
#include <cstring>
#include <iostream>

Room::Room(char* description) {
  this->description = new char[strlen(description) + 1];
  strcpy(this->description, description)
}

Room::~Room() {
  delete[] description;
}

char* Room::getShortDescription() {
  return description;
}

char* Room::getLongDescription() {
  //long description print
}

char* Room::getExitString() {
  char* returnString = "Exits:";
  for (auto exit = exits.begin(); exit != exits.end();) {
    //returnString
  }
}
