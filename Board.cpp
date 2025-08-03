//---------------------------------------------------------------------------

#pragma hdrstop

#include "Board.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Board::Set(int n, int m, char value) {
    if (n >= 0 && n < 3 && m >= 0 && m < 3) {
        if (board[n][m] == ' ') { // Chỉ đặt giá trị nếu ô trống
            board[n][m] = value;
            if (value == 'X') {
                X++;
            } else if (value == 'O') {
                O++;
            }
        }
    }
}

Board::Board() {
    X = 0;
	O = 0;
	// Khởi tạo board với các giá trị trống
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board[i][j] = ' ';
		}
	}
}
bool Board::checkXwin(){
    if (X >= 3) {
        // Kiểm tra các hàng
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
                return true;
            }
        }
        // Kiểm tra các cột
		for (int i = 0; i < 3; ++i) {
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') {
                return true;
            }
        }
        // Kiểm tra các đường chéo
		if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
            return true;
        }
		if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
            return true;
        }
	}
    // Nếu không có trường hợp nào thắng, trả về false
    return false;
}
bool Board::checkOwin() {
		// Kiểm tra các hàng
        for (int i = 0; i < 3; ++i) {
			if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
				return true;
			}
        }
		// Kiểm tra các cột
        for (int i = 0; i < 3; ++i) {
			if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') {
                return true;
			}
        }
        // Kiểm tra các đường chéo
		if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
            return true;
		}
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
            return true;
		}
		return false;
}

char Board::Get(int n, int m) const {
    if (n >= 0 && n < 3 && m >= 0 && m < 3) {
        return board[n][m];
	}
	return ' '; // Return a space character if out of bounds
}
void Board::Reset() {
	X = 0;
	O = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board[i][j] = ' '; // Đặt lại tất cả các ô trống
		}
	}
}
bool Board::checkWin(char symbol) const {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true; // Kiểm tra hàng ngang
		if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true; // Kiểm tra hàng dọc
	}
	if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true; // Kiểm tra đường chéo chính
	if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true; // Kiểm tra đường chéo phụ
	return false;
}
bool Board::isFull() const {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}
bool Board::checkDraw(){
	if (isFull() && !checkXwin() && !checkOwin()) {
		return true; // Hòa khi bảng đầy mà không có ai thắng
	}
	return false;
}
void Board::copyFrom(const Board& other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
				board[i][j] = other.board[i][j];
		}
	}
}

