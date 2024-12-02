#ifndef ITEM_H
#define ITEM_H

#include <cstring>

class Item {
 private:
  char* description;
 public:
  Item(const char* description);
  virtual ~Item();
  char* getDescription();
};

#endif
