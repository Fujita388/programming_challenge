#include <iostream>
#include <queue>


int main() {
	typedef std::pair<int, int> P;
	std::queue<P> que;

	que.push(P(1, 3));
	std::cout << que.front().first << '\n';
	std::cout << que.front().second << '\n';
	return 0;
}
