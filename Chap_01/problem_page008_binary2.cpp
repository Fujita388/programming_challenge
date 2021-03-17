#include <iostream>


const int MAX_N = 50;
int n, m, k[MAX_N];


// 2つの作れる数を格納する配列
int kk[MAX_N * MAX_N];


int main() {
	// 関数のプロトタイプ
	void solve();

	// 標準入力
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> k[i];
	}

	// 標準出力
	solve();

	return 0;
}


bool binary_search(int x) {
	// xの存在し得る範囲はkk[l], kk[l+1], ..., kk[r-1];
	int l = 0, r = n * n;
	
	// 範囲に何も含まれなくなるまで繰り返す
	while (r - 1 >= l) {
		int i = (l + r - 1) / 2;
		if (kk[i] == x)
			return true;  // 見つかった
		else if (kk[i] < x)
			l = i + 1;
		else
			r = i;
	}
	
	// 見つからなかった
	return false;
}


void solve() {
	// k[c] + k[d]のとり得る数を列挙
	for (int c = 0; c < n; ++c) {
		for (int d = 0; d < n; ++d) {
			kk[c * n + d] = k[c] + k[d];
		}
	}
	
	// 二分探索を行うためにソート
	std::sort(kk, kk + n * n);

	bool f = false;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			// 内側の二つのループの代わりに二分探索
			if (binary_search(m - k[a] - k[b])) {
				f = true;
			}
		}
	}

	if (f)
		puts("Yes");
	else
		puts("No");
}




