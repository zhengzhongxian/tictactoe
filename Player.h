#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    char symbol;
    bool step;

public:
    // Constructors
    Player();
    Player(char c);

    // Destructor
    ~Player();

    // Getter and Setter for symbol
    char GetChar() const;
    void SetChar(char c);

    // Getter and Setter for step
    bool getStep() const;
    void setStep(bool s);
};

#endif // PLAYER_H

