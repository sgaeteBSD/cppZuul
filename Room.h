#ifndef ROOM_H
#define ROOM_H

#include "Item.h"
#include <vector>
#include <map>

class Room {
 private:
  char* description;
  map<char*, Room*> exits;
  vector<Item*> items;
 public:
  Room(char* description);
  ~Room();
  void setExit();
  char* getShortDescription();
  char* getLongDescription();
  char* getExitString();
  Room getExit(char* direction);
  Item getItem(int index);
  Item getItemN(char* itemName);
  void removeItem(char* itemName);
  void setItem(Item newItem);
  char* getRoomItems();
};

#endif
