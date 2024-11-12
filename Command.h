#ifndef COMMAND_H
#define COMMAND_H

class Command {
 private:
    char* firstWord;
    char* secondWord;
 public:
    Command(char* firstWord, char* secondWord)
    virtual ~Command();
    
    char* getFirstWord();
    char* getSecondWord();
    bool isUnknown();
    bool hasSecondWord();
}

#endif
