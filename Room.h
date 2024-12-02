#ifndef ROOM_H
#define ROOM_H

#include "Item.h"
#include <vector>
#include <map>

using namespace std;

class Room {
 private:
  char* description; //Room description
  map<const char*, Room*> exits; //Exits mapped to their cardinal directions
  vector<Item*> items; //Items in room
 public:
  //constructor & destructor
  Room(const char* description);
  ~Room();

  //Room management
  void setExit(const char* direction, Room* neighbor);
  char* getShortDescription();
  char* getLongDescription();
  char* getExitString();
  Room* getExit(char* direction);

  //Item management
  Item* getItem(const char* itemName);
  void removeItem(const char* itemName);
  void setItem(Item* newItem);
  char* getRoomItems();
};

#endif
