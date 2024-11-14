#include "Item.h"

  Item::Item(char* description) {
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description)
  }
  Item::~Item() {
    delete[] description;
  }

char* Item::getDescription() {
  return description;
}

