#include <iostream>


// 入力
const int MAX_N = 100;
const int MAX_W = 10000;
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];  // DPテーブル(0で初期化されている)


void solve() {
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j <= W; ++j) {
			if (j < w[i]) 
				dp[i][j] = dp[i + 1][j];  // dp[i][]にはdp[i+1][]が必要
			else 
				dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
		}
	}
	std::cout << dp[0][W] << '\n';
}


int main() {
	// 標準入力
	std::cin >> n;
	for (int i = 0; i < n; ++i) 
		std::cin >> w[i] >> v[i];
	std::cin >> W;

	// 標準出力
	solve();
	return 0;
}
