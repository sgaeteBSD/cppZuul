#ifndef ROOM_H
#ifndef ROOM_H
#define ROOM_H

#include "Item.h"
#include <vector>
#include <map>

class Room {
 private:
  char* description; //Room description
  map<char*, Room*> exits; //Exits mapped to their cardinal directions
  vector<Item*> items; //Items in room
 public:
  //constructor & destructor
  Room(char* description);
  ~Room();

  //Room management
  void setExit();
  char* getShortDescription();
  char* getLongDescription();
  char* getExitString();
  Room getExit(char* direction);

  //Item management
  Item getItem(int index);
  Item getItemN(char* itemName);
  void removeItem(char* itemName);
  void setItem(Item newItem);
  char* getRoomItems();
};
