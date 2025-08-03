#include "Robot.h"

Robot::Robot(TForm* form) : Player() {
	this->form=form;
}
Robot::Robot() : Player(), mode_hard(0) {
	// Constructor không nhận tham số và không thực hiện hành động cụ thể
}
int Robot::Get_mode() const {
	return mode_hard;
}

void Robot::Set_mode(int mode) {
	mode_hard = mode;
}

void Robot::Easy(Board* board) {
	bool moveMade = false;
    int emptyCells = 0;
    // Đếm số ô trống
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board->Get(i, j) == ' ') {
				emptyCells++;
			}
		}
	}
	// Nếu không còn ô trống thì thoát hàm
	if (emptyCells == 0) {
		return;
	}
	while (!moveMade) {
		int randomRow = rand() % 3;
		int randomCol = rand() % 3;
		if (board->Get(randomRow, randomCol) == ' ') {
			board->Set(randomRow, randomCol, GetChar());
			UnicodeString buttonName = "b" + IntToStr(randomRow) + "_" + IntToStr(randomCol);
			TButton* btn = dynamic_cast<TButton*>(form->FindComponent(buttonName));
			if (btn) {
				btn->Text = GetChar();
				btn->TextSettings->FontColor = StringToAlphaColor("#FF292580");
			}
			moveMade = true;
		}
	}
}

void Robot::Normal(Board* board) {
	char playerSymbol = GetChar(); // Ký hiệu của robot
	char opponentSymbol = (playerSymbol == 'X') ? 'O' : 'X';

	// 1. Thắng nếu có thể
	for (int i = 0; i < 9; i++) {
		if (board->Get(i / 3, i % 3) == ' ') {
			Board newBoard = *board;
			newBoard.Set(i / 3, i % 3, playerSymbol);
			if ((playerSymbol == 'X' && newBoard.checkXwin()) ||
                (playerSymbol == 'O' && newBoard.checkOwin())) {
				board->Set(i / 3, i % 3, playerSymbol);
				UnicodeString buttonName = "b" + IntToStr(i / 3) + "_" + IntToStr(i % 3);
				TButton* btn = dynamic_cast<TButton*>(form->FindComponent(buttonName));
				if (btn) {
					btn->Text = playerSymbol;
					btn->TextSettings->FontColor = StringToAlphaColor("#FF292580");
				}
				return;
			}
		}
	}

	// 2. Chặn đối thủ nếu họ có thể thắng
	for (int i = 0; i < 9; i++) {
		if (board->Get(i / 3, i % 3) == ' ') {
            Board newBoard = *board;
			newBoard.Set(i / 3, i % 3, opponentSymbol);
			if ((opponentSymbol == 'X' && newBoard.checkXwin()) ||
				(opponentSymbol == 'O' && newBoard.checkOwin())) {
                board->Set(i / 3, i % 3, playerSymbol);
				UnicodeString buttonName = "b" + IntToStr(i / 3) + "_" + IntToStr(i % 3);
				TButton* btn = dynamic_cast<TButton*>(form->FindComponent(buttonName));
				if (btn) {
                    btn->Text = playerSymbol;
					btn->TextSettings->FontColor = StringToAlphaColor("#FF292580");
				}
				return;
			}
		}
	}

	// 3. Tạo cơ hội thắng trong lượt tiếp theo
	for (int i = 0; i < 9; i++) {
		if (board->Get(i / 3, i % 3) == ' ') {
            Board newBoard = *board;
			newBoard.Set(i / 3, i % 3, playerSymbol);
			if (hasTwoInARow(newBoard, playerSymbol)) {
				board->Set(i / 3, i % 3, playerSymbol);
				UnicodeString buttonName = "b" + IntToStr(i / 3) + "_" + IntToStr(i % 3);
				TButton* btn = dynamic_cast<TButton*>(form->FindComponent(buttonName));
				if (btn) {
					btn->Text = playerSymbol;
					btn->TextSettings->FontColor = StringToAlphaColor("#FF292580");
				}
				return;
			}
		}
	}

	// 4. Chặn đối thủ tạo cơ hội thắng trong lượt tiếp theo
	for (int i = 0; i < 9; i++) {
		if (board->Get(i / 3, i % 3) == ' ') {
			Board newBoard = *board;
			newBoard.Set(i / 3, i % 3, opponentSymbol);
			if (hasTwoInARow(newBoard, opponentSymbol)) {
				board->Set(i / 3, i % 3, playerSymbol);
				UnicodeString buttonName = "b" + IntToStr(i / 3) + "_" + IntToStr(i % 3);
				TButton* btn = dynamic_cast<TButton*>(form->FindComponent(buttonName));
				if (btn) {
					btn->Text = playerSymbol;
					btn->TextSettings->FontColor = StringToAlphaColor("#FF292580");
				}
				return;
			}
		}
	}

	// 5. Nếu không có nước đi thắng hoặc chặn, chọn ngẫu nhiên
	Easy(board);
}

bool Robot::hasTwoInARow(const Board& board, char symbol) const {
	// Kiểm tra các hàng
	for (int i = 0; i < 3; i++) {
		int count = 0;
		for (int j = 0; j < 3; j++) {
			if (board.Get(i, j) == symbol) {
				count++;
			}
		}
		if (count == 2) {
			// Kiểm tra nếu có ô trống để thắng
			for (int j = 0; j < 3; j++) {
				if (board.Get(i, j) == ' ') {
					return true;
				}
			}
		}
	}

	// Kiểm tra các cột
    for (int j = 0; j < 3; j++) {
		int count = 0;
		for (int i = 0; i < 3; i++) {
			if (board.Get(i, j) == symbol) {
				count++;
			}
        }
		if (count == 2) {
			// Kiểm tra nếu có ô trống để thắng
			for (int i = 0; i < 3; i++) {
				if (board.Get(i, j) == ' ') {
					return true;
                }
			}
        }
    }

	// Kiểm tra đường chéo chính
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (board.Get(i, i) == symbol) {
			count++;
        }
	}
	if (count == 2) {
		// Kiểm tra nếu có ô trống để thắng
		for (int i = 0; i < 3; i++) {
			if (board.Get(i, i) == ' ') {
				return true;
			}
		}
	}

	// Kiểm tra đường chéo phụ
	count = 0;
	for (int i = 0; i < 3; i++) {
		if (board.Get(i, 2 - i) == symbol) {
			count++;
		}
	}
	if (count == 2) {
		// Kiểm tra nếu có ô trống để thắng
		for (int i = 0; i < 3; i++) {
			if (board.Get(i, 2 - i) == ' ') {
				return true;
			}
		}
	}

	return false;
}
/*void Robot::Hardly(Board* board) {
   char playerSymbol = GetChar(); // Ký hiệu của robot
    char opponentSymbol = (playerSymbol == 'X') ? 'O' : 'X';
    // 1. Thắng nếu có thể
    for (int i = 0; i < 9; i++) {
        if (board->Get(i / 3, i % 3) == ' ') {
            Board newBoard = *board;
            newBoard.Set(i / 3, i % 3, playerSymbol);
            if ((playerSymbol == 'X' && newBoard.checkXwin()) ||
                (playerSymbol == 'O' && newBoard.checkOwin())) {
                board->Set(i / 3, i % 3, playerSymbol);
                UpdateButton(i / 3, i % 3, playerSymbol);
                return;
            }
        }
    }
    // 2. Chặn đối thủ nếu họ có thể thắng
    for (int i = 0; i < 9; i++) {
        if (board->Get(i / 3, i % 3) == ' ') {
            Board newBoard = *board;
            newBoard.Set(i / 3, i % 3, opponentSymbol);
            if ((opponentSymbol == 'X' && newBoard.checkXwin()) ||
                (opponentSymbol == 'O' && newBoard.checkOwin())) {
                board->Set(i / 3, i % 3, playerSymbol);
                UpdateButton(i / 3, i % 3, playerSymbol);
				return;
			}
		}
	}
	// 3. Tạo cơ hội thắng trong lượt tiếp theo
	for (int i = 0; i < 9; i++) {
		if (board->Get(i / 3, i % 3) == ' ') {
            Board newBoard = *board;
            newBoard.Set(i / 3, i % 3, playerSymbol);
			if (hasTwoInARow(newBoard, playerSymbol)) {
                board->Set(i / 3, i % 3, playerSymbol);
                UpdateButton(i / 3, i % 3, playerSymbol);
				return;
            }
		}
	}
	// 4. Chặn đối thủ tạo cơ hội thắng trong lượt tiếp theo
	for (int i = 0; i < 9; i++) {
		if (board->Get(i / 3, i % 3) == ' ') {
			Board newBoard = *board;
			newBoard.Set(i / 3, i % 3, opponentSymbol);
			if (hasTwoInARow(newBoard, opponentSymbol)) {
				board->Set(i / 3, i % 3, playerSymbol);
				UpdateButton(i / 3, i % 3, playerSymbol);
				return;
			}
		}
	}
	// 5. Chọn nước đi chiến lược khác nếu không có nước đi thắng hoặc chặn
	// Kiểm tra các ô góc và trung tâm
	int cornerMoves[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
	int centerMove[2] = {1, 1};
	// Kiểm tra nếu ô trung tâm còn trống
	if (board->Get(centerMove[0], centerMove[1]) == ' ') {
		board->Set(centerMove[0], centerMove[1], playerSymbol);
        UpdateButton(centerMove[0], centerMove[1], playerSymbol);
		return;
	}
	// Kiểm tra các ô góc
	for (auto& move : cornerMoves) {
		if (board->Get(move[0], move[1]) == ' ') {
			board->Set(move[0], move[1], playerSymbol);
			UpdateButton(move[0], move[1], playerSymbol);
			return;
		}
	}
	// 6. Chọn ngẫu nhiên nếu không có nước đi tối ưu
	Easy(board);
}*/
void Robot::MakeMove(Board* board) {
	switch (mode_hard) {
	case 0:
		Easy(board);
		break;
	case 1:
		Normal(board);
		break;
	case 2:
		Hardly(board);
		break;
	default:
		Easy(board);
		break;
	}
}

int Robot::minimax(Board board, int depth, bool maximizingPlayer, int alpha, int beta) {
	char playerSymbol = GetChar();
	char opponentSymbol = (playerSymbol == 'X') ? 'O' : 'X';
	if (board.checkWin(playerSymbol)) return 10 - depth;
	if (board.checkWin(opponentSymbol)) return depth - 10;
	if (board.isFull()) return 0;
	if (maximizingPlayer) {
    int maxEval = -numeric_limits<int>::max();
    for (int i = 0; i < 9; i++) {
        if (board.board[i / 3][i % 3] == ' ') {
			board.board[i / 3][i % 3] = playerSymbol;
            int eval = minimax(board, depth + 1, false, alpha, beta);
            board.board[i / 3][i % 3] = ' ';
            maxEval = max(maxEval, eval);
            alpha = max(alpha, maxEval);
            if (beta <= alpha) {
				break; // cái này là cắt tỉa beta nha ae
            }
        }
    }
    return maxEval;
}
else {
    int minEval = numeric_limits<int>::max();
    for (int i = 0; i < 9; i++) {
        if (board.board[i / 3][i % 3] == ' ') {
            board.board[i / 3][i % 3] = opponentSymbol;
            int eval = minimax(board, depth + 1, true, alpha, beta);
            board.board[i / 3][i % 3] = ' ';
            minEval = min(minEval, eval);
            beta = min(beta, minEval);
            if (beta <= alpha) {
                break; // Cắt tỉa alpha
            }
        }
    }
    return minEval;
}
}

void Robot::Hardly(Board* board) {
	int bestMoveRow = -1;
	int bestMoveCol = -1;
	int bestValue = -numeric_limits<int>::max();
	char playerSymbol = GetChar();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
            if (board->Get(i, j) == ' ') {
                Board newBoard = *board;
				newBoard.Set(i, j, playerSymbol);
                int moveValue = minimax(newBoard, 0, false, -numeric_limits<int>::max(), numeric_limits<int>::max());
                if (moveValue > bestValue) {
                    bestValue = moveValue;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }
    if (bestMoveRow != -1 && bestMoveCol != -1) {
		board->Set(bestMoveRow, bestMoveCol, playerSymbol);
        UnicodeString buttonName = "b" + IntToStr(bestMoveRow) + "_" + IntToStr(bestMoveCol);
        TButton* btn = dynamic_cast<TButton*>(form->FindComponent(buttonName));
        if (btn) {
			btn->Text = playerSymbol;
            btn->TextSettings->FontColor = StringToAlphaColor("#FF292580");
        }
	}
}

