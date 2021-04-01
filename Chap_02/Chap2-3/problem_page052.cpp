#include <iostream>


// 入力
const int MAX_N = 100;
int n, W;
int w[MAX_N], v[MAX_N];


// i番目以降の品物から重さの総和がj以下となるように選ぶ
int rec(int i, int j) {
	int res;  // 価値
	if (i == n) {
		// もう品物は残っていない
		res = 0;
	}
	else if (j < w[i]) {
		// この品物は入らない
		res = rec(i + 1, j);
	}
	else {
		// 入れない場合と入れる場合を両方試す
		res = std::max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return res;
}


void solve() {
	std::cout << rec(0, W) << '\n';
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



