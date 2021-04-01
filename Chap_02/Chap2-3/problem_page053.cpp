#include <iostream>


// 入力
const int MAX_N = 100;
const int MAX_W = 10000;
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];  // メモ化テーブル


int rec(int i, int j) {
	if (dp[i][j] >= 0) {
		// すでに調べたことがあるらならばその結果を再利用
		return dp[i][j];
	}
	int res;
	if (i == n) {
		res = 0;
	}
	else if (j < w[i]) {
		res = rec(i + 1, j);
	}
	else {
		res = std::max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	// 結果をテーブルに記憶する
	return dp[i][j] = res;
}


void solve() {
	// また調べていないことを表す-1でメモ化テーブルを初期化
	std::memset(dp, -1, sizeof(dp));
	std::cout << rec(0, W) << '\n';
}


int main () {
	// 標準入力
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> w[i] >> v[i];
	}
	std::cin >> W;

	// 標準出力
	solve();
	return 0;
}
