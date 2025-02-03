#include "GameOfLife.h"
#include "GameClock.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

void GameOfLife::RunGame(bool random, bool pause)
{
	GenClearBoard();
	if (random)
		RegenBoard();
	else MakeGlider(2, 1);
	PrintBoard();
	if (pause) getchar();
	GameClock* clock = GameClock::GetInstance();
	//could add way to break but meh
	for (;;) {
		//CopyFrontToBack();
		for (int i = 0; i < BOARD_WIDTH; i++) {
			for (int j = 0; j < BOARD_WIDTH; j++) {
				bool alive = frontBoard[i][j];
				int neighbours = CountNeighbours(i, j);
				if (alive && neighbours < 2) {
					backBoard[i][j] = false;    //Any live cell with fewer than two live neighbours dies, as if by underpopulation.
				}
				else if (alive && (neighbours == 2 || neighbours == 3)) {
					backBoard[i][j] = true;//Any live cell with two or three live neighbours lives on to the next generation.
				}
				else if (alive && neighbours > 3) {
					backBoard[i][j] = false;	//Any live cell with more than three live neighbours dies, as if by overpopulation.
				}
				else if (!alive && neighbours == 3) {
					backBoard[i][j] = true;	//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
				}
				else {
					backBoard[i][j] = false;
				}
				
			}
		}
		PrintBoard();
		clock->Tick();
		if (pause) getchar();
	}
}
void GameOfLife::PrintBoard()
{
	SwapBoards();
	
	std::string output;
	output.push_back('\n');
	output.push_back('-');
	for (int i = 0; i < BOARD_WIDTH; i++) {
		output.push_back('-');
	}
	output.push_back('-\n');
	for (int i = 0; i < BOARD_WIDTH; i++) {
		output.push_back('|');
		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (frontBoard[i][j]) {
				output.push_back('*');
			}
			else {
				output.push_back(' ');
			}
		}
		output.push_back('|');
		output.push_back('\n');
	}
	output.push_back('-');
	for (int i = 0; i < BOARD_WIDTH; i++) {
		output.push_back('-');
	}
	output.push_back('-');
	output.push_back('\n');

	system("cls");//might clear idk
	printf(output.c_str());


}

void GameOfLife::RegenBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			frontBoard[i][j] = rand() % 2;
			backBoard[i][j] = frontBoard[i][j];
		}
	}
}

void GameOfLife::GenClearBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			frontBoard[i][j] = false;
			backBoard[i][j] = false;
		}
	}
}

void GameOfLife::MakeGlider(int row, int col)
{

	frontBoard[row][col] = false;
	frontBoard[row][col+1] = false;
	frontBoard[row][col+2] = true;

	frontBoard[row+1][col] = true;
	frontBoard[row+1][col+1] = false;
	frontBoard[row+1][col+2] = true;

	frontBoard[row+2][col] = false;
	frontBoard[row+2][col+1] = true;
	frontBoard[row+2][col+2] = true;


	backBoard[row][col] = false;
	backBoard[row][col + 1] = false;
	backBoard[row][col + 2] = true;

	backBoard[row + 1][col] = true;
	backBoard[row + 1][col + 1] = false;
	backBoard[row + 1][col + 2] = true;

	backBoard[row + 2][col] = false;
	backBoard[row + 2][col + 1] = true;
	backBoard[row + 2][col + 2] = true;
}
void GameOfLife::MakeOscillator(int row, int col) {
	frontBoard[row][col] = true;
	frontBoard[row][col + 1] = true;
	frontBoard[row][col + 2] = true;
	backBoard[row][col] = true;
	backBoard[row][col + 1] = true;
	backBoard[row][col + 2] = true;
}

int GameOfLife::CountNeighbours(int row, int col)
{
	int output = 0;
	for (int i = row - 1; i <= row + 1; i++) {
		if (i<0 || i >= BOARD_WIDTH) continue;
		for (int j = col - 1; j <= col + 1; j++) {
			if (j<0 || j >= BOARD_WIDTH) continue;
			if (j == col && i == row) continue;
			if (frontBoard[ i][ j]) { 
				output++; 
			}
		}
	}


	return output;
}

void GameOfLife::SwapBoards()
{
	bool tempArray[BOARD_WIDTH][BOARD_WIDTH];
	memcpy(tempArray, backBoard, sizeof(bool) * BOARD_WIDTH * BOARD_WIDTH);
	memcpy(backBoard, frontBoard, sizeof(bool) * BOARD_WIDTH * BOARD_WIDTH);
	memcpy(frontBoard, tempArray, sizeof(bool) * BOARD_WIDTH * BOARD_WIDTH);
}

void GameOfLife::CopyFrontToBack()
{
	memcpy(backBoard, frontBoard, sizeof(bool) * BOARD_WIDTH * BOARD_WIDTH);
}
