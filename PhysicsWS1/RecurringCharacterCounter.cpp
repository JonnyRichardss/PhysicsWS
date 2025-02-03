#include "RecurringCharacterCounter.h"
#include <algorithm>

void RecurringCharacterCounter::printRecurringChar(std::string input)
{
	int positions[128] = { -1 };
	std::fill(std::begin(positions), std::end(positions), -1);
	for (int i = 0; i < input.size(); i++) {
		
		if (positions[input[i]] == -1) {
			positions[input[i]] = i;
		}
		else {
			printf("Reccurring character %c found at index: %i\n", input[i], positions[input[i]]);
			return;
		}
	}
}
