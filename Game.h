#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Robot.h"
#include <fmx.h>  // For TImage

class Game {
private:
    Player* player1;
    Player* player2;
	Robot *rb;

public:
    // Constructors
	Game(Player* p1, Player* p2, Robot *r);
    Game();

    // Destructor
    ~Game();

    // Getters and Setters
    Player* GetPlayer1();
    void SetPlayer1(Player* p);
    Player* GetPlayer2();
    void SetPlayer2(Player* p);
	Robot* GetRobot();
	void SetRobot(Robot *r);

    // Game methods
    void NextStep(bool check);
	void SetRandom(int n, TImage* a, TImage* b, bool check,Board *bd);
};

#endif // GAME_H


