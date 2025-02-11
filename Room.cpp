#include "Room.h"
#include <cstring>
#include <iostream>

Room::Room(const char* description) { //Constructor
  this->description = new char[strlen(description) + 1];
  strcpy(this->description, description);
}

Room::~Room() { //Destructor
  delete[] description;

  for (auto item : items) {
    delete item;
  }
}

void Room::setExit(const char* direction, Room* neighbor) { //Set exit to neighbor
  exits[direction] = neighbor;
}

char* Room::getShortDescription() { //Get short desc
  char* result = new char[strlen(description) + 1];
  strcpy(result, description);
  return result;
}

char* Room::getLongDescription() { //Get long desc
  //create base
  int baseLength = strlen("You are ") + strlen(description) + strlen(".\n") + 1; //find needed length
  char* result = new char[baseLength]; //create cstring
  strcpy(result, "You are "); //copy first into result
  strcat(result, description); //then append the others
  strcat(result, ".\n");

  //append exit string
  char* exitString = getExitString();
  int finalLength = baseLength + strlen(exitString) + 1;
  char* finalResult = new char[finalLength];
  strcpy(finalResult, result); //copy first result into final
  strcat(finalResult, exitString); //append exits

  //clear up memory
  delete[] result;
  delete[] exitString;
	
  return finalResult; //return
}

char* Room::getExitString() {
    //start with "Exits:" 
    int stringSize = strlen("Exits:") + 1;
    char* result = new char[stringSize];
    strcpy(result, "Exits:");

    for (const auto& exit : exits) { //append possible exit directions
        const char* direction = exit.first;
        int newSize = stringSize + strlen(" ") + strlen(direction);
        char* temp = new char[newSize]; //cstring with new size
        strcpy(temp, result); //copy in our existing result
        strcat(temp, " "); //add a space
        strcat(temp, direction); //add the direction option

        delete[] result; //clear result
        result = temp; //now result points to the temp memory
        stringSize = newSize; //updates string size
    }

    //we also need to include room items. append those
    char* roomItems = getRoomItems();
    int finalSize = stringSize + strlen("\nItems in the room:\n") + strlen(roomItems); //new lines
    char* finalResult = new char[finalSize]; //create cstring
    strcpy(finalResult, result); //copy in
    strcat(finalResult, "\nItems in the room:\n"); //append
    strcat(finalResult, roomItems); //append

    //clean up
    delete[] result;
    delete[] roomItems;
    return finalResult;
}

Room* Room::getExit(char* direction) { //return room in specific direction
    for (const auto& pair : exits) {
        if (strcmp(pair.first, direction) == 0) {
            return pair.second; // Found matching key
        }
    }

  /*auto it = exits.find(direction); //use map's find()
    if (it != exits.end()) {
	//if the direction exists, return its room pointer
	return it->second; //use it->second to get the map element's value (the room name) and not its key (the direction)
    }*/
    return nullptr; //if no room exists in given direction, return null
}

Item* Room::getItem(const char* itemName) {
  for (auto& item : items) {
    if (strcmp(item->getDescription(), itemName) == 0) {
      return item;
    }
  }
  return nullptr; //if no match, return null
}

void Room::removeItem(const char* itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) { //go through items
        if (strcmp((*it)->getDescription(), itemName) == 0) { //if desc matches item
            delete *it; //free memory of the item
            items.erase(it); //remove the item from the vector
            cout << "Removed item: " << itemName << endl;
            return; //stop function/iteration after removal
        }
    }
    cout << "Item not found: " << itemName << endl; //if item isn't found
}

void Room::setItem(Item* newItem) {
    //add given item to vector
    items.push_back(newItem);
}

char* Room::getRoomItems() {
    //create empty cstring
    char* result = new char[1];
    result[0] = '\0';

    for (auto item : items) {
        char* description = item->getDescription(); //get this item's description

        //determine needed size
        int newSize = strlen(result) + strlen(description) + strlen(" ") + 1;

        //create temp for copying and appending
        char* temp = new char[newSize];
        strcpy(temp, result);       //copy in old
        strcat(temp, description); //add item desc
        strcat(temp, " ");         //add space

        delete[] result; //free the old memory
        result = temp;   //now result points to the temp memory
    }
    return result;
}
