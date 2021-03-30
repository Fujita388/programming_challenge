#include <iostream>


// 入力
const int MAX_N = 2000;
int N;
char S[MAX_N + 1];


void solve() {
	// S[a], S[a+1], ..., S[b]が残っている文字列
	int a = 0, b = N - 1;

	while (a <= b) {
		// 左からみた場合と右からみた場合を比較(同じ時はその次のペアを比較)
		bool left = false;
		for (int i = 0; a + i <= b; ++i) {
			if (S[a + i] < S[b - i]) {
				left = true;
				break;
			}
			else if (S[a + i] > S[b - i]) {
				left = false;
				break;
			}
		}
		
		if (left)
			putchar(S[a++]);  // S[a]を出力してからインクリメント 
		else 
			putchar(S[b--]);
	}
	
	putchar('\n');
}


int main() {
	// 標準入力
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> S[i];
	}

	// 標準出力
	solve();
	return 0;
}

