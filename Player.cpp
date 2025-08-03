#include "Player.h"

Player::Player() : symbol(' '), step(false) { }
Player::Player(char c) : symbol(c), step(true) { }
Player::~Player() { }
char Player::GetChar() const {
    return symbol;
}
void Player::SetChar(char c) {
	symbol = c;
}
bool Player::getStep() const {
	return step;
}
void Player::setStep(bool s) {
    step = s;
}
