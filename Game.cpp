#include "Game.h"

// Constructor
Game::Game(Player* p1, Player* p2, Robot *r) : player1(p1), player2(p2), rb(r) {}
Game::Game() {
    player1 = nullptr;
    player2 = nullptr;
    rb = nullptr;
}
// Destructor
Game::~Game() {
    delete player1;
    delete player2;
	delete rb;
}
Player* Game::GetPlayer1() {
    return player1;
}
void Game::SetPlayer1(Player* p) {
    player1 = p;
}
void Game::SetPlayer2(Player* p) {
    player2 = p;
}
Player* Game::GetPlayer2() {
    return player2;
}
Robot* Game::GetRobot() {
    return rb;
}
void Game::SetRobot(Robot *r) {
    rb = r;
}
void Game::NextStep(bool check) {
	if (!check) {
        if (player1->getStep()) {
            player1->setStep(false);
            if (rb != nullptr) {
                rb->setStep(true);
            }
		} else if (rb != nullptr && rb->getStep()) {
			rb->setStep(false);
            player1->setStep(true);
        }
    } else {
        if (player1->getStep()) {
            player1->setStep(false);
            player2->setStep(true);
        } else if (player2->getStep()) {
            player2->setStep(false);
            player1->setStep(true);
        }
    }
}
void Game::SetRandom(int n, TImage *a, TImage *b, bool check,Board *bd) {
	// Khởi tạo ngẫu nhiên
	if (n == 1) {
		player1->setStep(true);
		if (!check) {
			if (rb != nullptr) {
				rb->setStep(false);
				a->Opacity = 1;
				b->Opacity = 1;
			}
		} else {
			player2->setStep(false);
			a->Opacity = 1;
			b->Opacity = 0.2;
		}
	} else {
		player1->setStep(false);
		if (!check) {
			if (rb != nullptr) {
				rb->setStep(true);
				a->Opacity = 1;
				b->Opacity = 1;
				rb->MakeMove(bd);
				NextStep(check);
			}
		} else {
			player2->setStep(true);
            a->Opacity = 0.3;
			b->Opacity = 1;
		}
	}
}

