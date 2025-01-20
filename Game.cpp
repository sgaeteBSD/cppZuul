#include <iostream>
#include <vector>
#include <string>
#include "Room.h"
#include "Item.h"

using namespace std;

class Game {
private:
    Room* currentRoom;
    int coffeeCheck;
    Room *boss, *cubicles1, *conference, *break1, *reception, *bridge, *lobby, *cubicles2, *vending, *office, *empty, *IT, *storage, *kitchen, *break2;
    vector<Item> inventory;

public:
    Game() {
        createRooms();
    }

    void createRooms() {
        // Create rooms
        boss = new Room("in your boss' office");
        cubicles1 = new Room("in an average sea of cubicles. Exciting");
        conference = new Room("in a conference room. There's a meeting going on, so you should probably leave");
        break1 = new Room("in a break room. You usually use the coffee machine here, but it's broken. There's another one further north");
        reception = new Room("near the receptionist's desk. There's a can of ground espresso on the counter");
        bridge = new Room("on a bridge between rooms. For whatever reason, there's a frother on the ground");
        lobby = new Room("in the lobby. Leaving through the front door is tempting, but there's work to be done");
        cubicles2 = new Room("in just another room of cubicles. Just as exciting as last time");
        vending = new Room("in an elevator room, with some vending machines. There's water bottles in the machine");
        office = new Room("in a random office. The boss here is out, and there's a really nice mug on his desk");
        empty = new Room("in a completely empty room. Still better than the cubicles");
        IT = new Room("in the IT department's office. Maybe someone here can fix that south coffee machine later");
        storage = new Room("in the storage room. Surprisingly, there's nothing useful");
        kitchen = new Room("in the kitchen. There's milk in the fridge");
        break2 = new Room("in the north break room, with a working coffee machine. Use the command \"brew\" to use the machine");

        // Initialize room exits (using strings for directions)
        boss->setExit("north", cubicles1);

        cubicles1->setExit("south", boss);
        cubicles1->setExit("west", break1);
        cubicles1->setExit("east", conference);

        break1->setExit("east", cubicles1);
        break1->setExit("north", reception);

        conference->setExit("west", cubicles1);
        conference->setExit("north", bridge);

        reception->setExit("south", break1);
        reception->setExit("north", lobby);

        bridge->setExit("south", conference);
        bridge->setExit("north", cubicles2);

        lobby->setExit("south", reception);
        lobby->setExit("east", vending);

        cubicles2->setExit("south", bridge);
        cubicles2->setExit("west", vending);
        cubicles2->setExit("east", office);

        vending->setExit("west", lobby);
        vending->setExit("north", IT);
        vending->setExit("east", cubicles2);

        IT->setExit("south", vending);
        IT->setExit("north", kitchen);

        office->setExit("west", cubicles2);
        office->setExit("north", empty);

        empty->setExit("south", office);
        empty->setExit("north", storage);

        kitchen->setExit("south", IT);
        kitchen->setExit("east", break2);

        storage->setExit("south", empty);
        storage->setExit("west", break2);

        break2->setExit("west", kitchen);
        break2->setExit("east", storage);

        // Initialize items
        reception->setItem(new Item("espresso"));
        bridge->setItem(new Item("frother"));
        vending->setItem(new Item("water"));
        office->setItem(new Item("mug"));
        kitchen->setItem(new Item("milk"));

        currentRoom = boss;  // Start game at boss
    }

    void printWelcome() {
        cout << "\nWelcome to Adventure!" << endl;
        cout << "Adventure is a new, incredibly boring adventure game." << endl;
        cout << "Type 'help' if you need help." << endl;
        cout << "\nYour boss wants a cup of coffee. Find the five ingredients and a coffee machine, then bring the finished latte back." << endl;
        cout << "\n" << currentRoom->getLongDescription() << endl;
    }

    void play() {
        printWelcome();

        bool finished = false;
        while (finished == false) {
	  cout << "Input a command." << endl;
	  char command[30] = "";
	  cin >> command; 
	  cin.ignore();
	  if (strcmp(command, "help") == 0) {
	    printHelp();
	  }
	  else if (strcmp(command, "go") == 0) {
	    cout << "What room are you going to?" << endl;
	    cin >> command;
	    goRoom(command);
	  }
	  else if (strcmp(command, "quit") == 0) {
	    quit();
	    finished = true;
	  }
	  else if (strcmp(command, "inventory") == 0) {
	    printInventory();
	  }
	  else if (strcmp(command, "get") == 0) {
	    cout << "What item would you like to pick up?" << endl;
	    cin >> command;
	    getItem(command);
	  }
	  else if (strcmp(command, "drop") == 0) {
	    cout << "What item would you like to drop?" << endl;
	    cin >> command;
	    dropItem(command);
	  }
	  else if (strcmp(command, "brew") == 0) {
	    brewCoffee();
	  }
	  else {
	    cout << "Invalid input! Try again." << endl;
	  }
	}
        cout << "Thank you for playing. Goodbye." << endl;
    }

    void brewCoffee() {
        if (currentRoom == break2) {  // If there's a coffee machine
            for (int i = 0; i < 5; i++) {
		  if (inventory[i].getDescription() != nullptr) {
                        coffeeCheck += 1;
                  }
            }
	    if (coffeeCheck != 5) {  // Try-catch in case of missing ingredients
                    cout << "You're missing ingredients!" << endl;
                    coffeeCheck = 0;
                    return;
                }

            if (coffeeCheck == 5) {  // Check if all 5 ingredients are present
                inventory.clear();  // Remove all 5 now
                inventory.push_back(Item("coffee"));  // Add coffee
                cout << "You've brewed the coffee! Bring it back to your boss." << endl;
            }
    }
        else if (currentRoom == break1) {
            cout << "The coffee machine here is broken. Too bad." << endl;
        }
        else {
            cout << "There's no coffee machine here!" << endl;
        }
    }

void dropItem(char command[30]) {
    Item* newItem = nullptr;
    int index = 0;
    bool found = false;

    // Search for the item in inventory
    for (int i = 0; i < inventory.size(); ++i) {
        if (strcmp(inventory[i].getDescription(), command) == 0) {
            newItem = &inventory[i];
            index = i;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "That item is not in your inventory!" << endl;
    } else {
        inventory.erase(inventory.begin() + index);  // Remove the pointer from inventory
        currentRoom->setItem(newItem);  // Add it back to the room
        cout << "Dropped: " << command << endl;
    }
}


  void getItem(char command[30]) {
    Item* newItem = currentRoom->getItem(command);  // Get pointer to the item

    if (newItem == nullptr) {
        cout << "That item is not here!" << endl;
    }
    else {
        inventory.push_back(*newItem);  // Push the pointer into inventory (no copy)
        currentRoom->removeItem(command);
        cout << "Picked up: " << command << endl;
    }
  }

    void printInventory() {
        char output[80] = "";
	cout << "You are carrying:" << endl;
    for (int i = 0; i < inventory.size(); ++i) {
        cout << inventory[i].getDescription() << endl;  // Access description through pointer
    }        for (int i = 0; i < inventory.size(); ++i) {
            strcat(output, inventory[i].getDescription());
            strcat(output, " ");
        }

        cout << "You are carrying:" << endl;
        cout << output << endl;
    }

    void printHelp() {
        cout << "You need to find five coffee ingredients and brew a latte for your boss at the northern coffee machine," << endl;
        cout << "and bring it back to their office once you're done." << endl;
        cout << "Your command words are: go, get, drop, inventory, brew, help, quit" << endl;
    }

    bool goRoom(char command[30]) {

        char* direction = command;

        Room* nextRoom = currentRoom->getExit(direction);

        if (nextRoom == nullptr)
            cout << "There is no door!" << endl;
        else {
            currentRoom = nextRoom;
            cout << currentRoom->getLongDescription() << endl;
            // Win condition(s)! Step into boss' room with coffee in inventory
            if (currentRoom == boss && inventory[0].getDescription() == "coffee") {
                cout << "You win! Your boss is very thankful. Now get back to work!" << endl;
                return true;
            }
        }
        return false;
    }

    void quit() {
      cout << "Goodbye!" << endl;
      return;
    }
};

// Main function to start the game
int main() {
    Game mygame;
    mygame.play();
    return 0;
}
