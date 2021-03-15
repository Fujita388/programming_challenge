#include <iostream>


const int MAX_N = 100;


int n, a[MAX_N];  // 入力変数


int main() {
	// 関数のプロトタイプ
	int solve(void);

	//標準入力
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	// 標準出力
	std::cout << solve() << '\n';
	return 0;
} 


int solve(void) {
	int ans = 0;

	// 棒を重複して選ばないように x < y < z とする
	for (int x = 0; x < n - 2; ++x) {
		for (int y = x + 1; y < n - 1; ++y) {
			for (int z = y + 1; z < n; ++z) {
				int len = a[x] + a[y] + a[z];  // 周長
				int max_len = std::max(a[x], std::max(a[y], a[z]));  // 最大の辺
				if (max_len * 2 <= len) 
					ans = std::max(len, ans);  // ansを更新
			}
		}
	}

	return ans;	
}



