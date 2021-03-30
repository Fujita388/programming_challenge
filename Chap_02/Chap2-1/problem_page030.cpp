#include <iostream>


const int MAX_N = 50;
int m, memo[MAX_N];


int main() {
	int fib(int n);

	// 標準入力  1 <= m <= 50
	std::cin >> m;

	// 標準出力
	std::cout << fib(m) << '\n';
	return 0;
}


int fib(int n) {
	if (n <= 1)
		return n;
	if (memo[n] != 0)
		return memo[n];
	return memo[n] = fib(n - 1) + fib(n - 2);
}
