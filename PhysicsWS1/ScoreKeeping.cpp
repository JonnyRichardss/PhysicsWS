#include "ScoreKeeping.h"

void ScoreKeeping::CalculateScore(std::string input)
{
	int counts[58] = { 0 };
	for (int i = 0; i < input.size(); i++) {
		counts[input[i] - 'A']++;
	}
	int scores[26] = { 0 };
	for (int i = 0; i < 26; i++) {
		scores[i] -= counts[i];
		scores[i] += counts[i + 32];
	}
	bool printing = false;
	for (int i = 25; i >= 0; i--) {
		if (scores[i] != 0) {
			printing = true;
		}
		if (printing)printf("%c: %i\n", i + 'a', scores[i]);
	}
	printf("\n");
}
