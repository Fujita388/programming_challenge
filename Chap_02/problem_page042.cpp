#include <iostream>


// 入力
int C[6];  // C[0] = C_1, C[1] = C_5, ...
int A;
const int V[6] = {1, 5, 10, 50, 100, 500};  // コインの金額


void solve() {
	int ans = 0;
	
	for (int i = 5; i >= 0; --i) {
		int t = std::min(A / V[i], C[i]);  // コインiを使う枚数
		A -= t * V[i];  // V[i]のコインを使って払った金額
		ans += t;
	}
	
	std::cout << ans << '\n';
}


int main() {
	// 標準入力
	for (int i = 0; i < 6; ++i) {
		std::cin >> C[i];
	}
	std::cin >> A;
	
	// 標準出力
	solve();
	return 0;
}
