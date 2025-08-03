//---------------------------------------------------------------------------

#ifndef BoardH
#define BoardH
#include <fmx.h>
//---------------------------------------------------------------------------
using namespace std;
class Board{
	private:
	int X,O;
	public:
    char board[3][3];
	Board();
	void Set(int n, int m, char board);
	bool checkXwin() ;
	bool checkOwin() ;
	char Get(int n, int m) const;
	void Reset();
	bool checkWin(char symbol) const ;
	bool isFull() const ;
	bool checkDraw();
    void copyFrom(const Board& others);
};
#endif
