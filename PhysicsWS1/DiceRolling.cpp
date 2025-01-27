#include "DiceRolling.h"
#include <vector>
#include <sstream>
using namespace std;
vector<string> Split(string input, char delim) {
	vector<string> words;
	stringstream ss(input);
	string word;
	while (getline(ss, word, delim)) {
		words.push_back(word);
	}
	return words;
}
void DiceRolling::Roll(std::string input)
{
	vector<string> nums = Split(input, 'd');
	if (nums.size() != 2) {
		printf("Invalid Format!\n");
		return;
	}
	//no input checking here too :)
	int numDice = stoi(nums[0]);
	int maxVal = stoi(nums[1]);
	printf("%iD%i:\n",numDice,maxVal);
	int sum = 0;
	vector<int> rolls;
	for (int i = 0; i < numDice; i++) {
		int roll = (rand() % maxVal) + 1;
		sum += roll;
		rolls.push_back(roll);
		
	}
	printf("%i:", sum);
	for (int i = 0; i < rolls.size(); i++) {
		printf(" %i", rolls[i]);
	}
	printf("\n");
}
