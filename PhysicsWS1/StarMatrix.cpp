#include "StarMatrix.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
void StarMatrix::printSquare(int numLines)
{
	for (int i = 0; i < numLines; i++) {
		for (int j = 0; j < numLines; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void StarMatrix::printTriangle(int numLines)
{
	for (int i = 1; i <= numLines; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void StarMatrix::printRandomBox()
{
	int x = rand() % 20;
	int y = rand() % 20;
	using namespace std;
	vector<vector<bool>> array2D;
	for (int i = 0; i < x; i++) {
		array2D.push_back(vector<bool>());
		for (int j = 0; j < y; j++) {
			bool b = rand() % 2;
			array2D[i].push_back(b);
		}
	}
	printf("-");
	for (int i = 0; i < y; i++) {
		printf("-");
	}
	printf("-\n");
	for (int i = 0; i < x; i++) {
		printf("|");
		for (int j = 0; j < y; j++) {
			if (array2D[i][j]) {
				printf("*");
			
			}
			else {
				printf(" ");
			}
		}
		printf("|\n");
	}
	printf("-");
	for (int i = 0; i < y; i++) {
		printf("-");
	}
	printf("-\n");
}
