#include <iostream>


std::pair<int, int> V[5];


int main() {
	V[0].first = 10;
	V[0].second = 11;
	V[1].first = 20;
	V[1].second = 211;
	
	std::cout << V[1].first << '\n';

	putchar('J');
	putchar('\n');

	bool comp(char i, char j);
	std::cout << comp('C', 'A') << '\n';

	return 0;
}


bool comp(char i, char j) {
	if (i > j)
		return true;
	else
		return false;
}
