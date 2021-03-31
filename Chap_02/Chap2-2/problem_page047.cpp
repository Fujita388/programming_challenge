#include <iostream>


// 入力
const int MAX_N = 1000;
int N, R;
int X[MAX_N];


void solve() {
	std::sort(X, X + N);

	int i = 0, ans = 0;
	while (i < N) {
		// sはカバーされていない一番左の点の位置
		int s = X[i++];
		// sから距離Rを超える点まで進む
		while (i < N && X[i] <= s + R)
			++i;

		// pは新しく印を付ける点の位置
		int p = X[i - 1];  // 最後にインクリメントされた分を削る
		// pから距離Rを超える点まで進む
		while (i < N && X[i] <= p + R)
			++i;

		++ans;
	}

	std::cout << ans << '\n';
}


int main() {
	// 標準入力
	std::cin >> N >> R;
	for (int i = 0; i < N; ++i) {
		std::cin >> X[i];
	}
	
	// 標準出力
	solve();
	return 0;
}
