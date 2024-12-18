#include "Item.h"

Item::Item(const char* description) { //constructor
  this->description = new char[strlen(description) + 1];
  strcpy(this->description, description);
}

Item::~Item() { //destructor
  delete[] description;
}

char* Item::getDescription() {
  char* result = new char[strlen(description) + 1];
  strcpy(result, description);
  return result;
};

