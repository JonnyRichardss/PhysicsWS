#pragma once
#define BOARD_WIDTH 40
class GameOfLife
{
public:
	void RunGame(bool random,bool pause);

	void PrintBoard();
	void RegenBoard();
	void GenClearBoard();
	void MakeGlider(int row, int col);
	void MakeOscillator(int row, int col);
	int CountNeighbours(int row, int col);
	void SwapBoards();
	void CopyFrontToBack();
	bool frontBoard[BOARD_WIDTH][BOARD_WIDTH];
	bool backBoard[BOARD_WIDTH][BOARD_WIDTH];
};

