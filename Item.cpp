#include "Item.h"

Item::Item(const char* description) { //constructor
  this->description = new char[80];
  strcpy(this->description, description);
}

Item::~Item() { //destructor
  delete[] description;
}

char* Item::getDescription() {
  char* result = new char[80];
  strcpy(result, description);
  return result;
};

