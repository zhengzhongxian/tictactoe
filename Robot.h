//---------------------------------------------------------------------------
#ifndef RobotH
#define RobotH
#include <fmx.h>
#include "Player.h"
#include "Board.h"
#include <limits>
#include <algorithm>
#include <cstdlib>
using namespace std;
class Robot:public Player{
	private:
	int mode_hard;
	TForm *form;
	bool hasTwoInARow(const Board& board, char symbol) const;
    int minimax(Board board, int depth, bool maximizingPlayer, int alpha, int beta);
	public:
	Robot(TForm* form);
    int Get_mode() const;
    void Set_mode(int mode);
    void Easy(Board* board);
    void Normal(Board* board);
	void Hardly(Board * board);
	void MakeMove(Board* board);
	Robot();
};
//---------------------------------------------------------------------------
#endif
