#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <map>

class Room {
 private:
  char* description;
  map exits;
 public:
  Room(char* description);
  virtual ~Room();
}

#endif
