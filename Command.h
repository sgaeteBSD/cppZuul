#ifndef COMMAND_H
#define COMMAND_H

class Command {
 private:
    char* commandWord;
    char* secondWord;
 public:
  Command(char* commandWord, char* secondWord);
    virtual ~Command();
    
    char* getCommandWord();
    char* getSecondWord();
    bool isUnknown();
    bool hasSecondWord();
};

#endif
