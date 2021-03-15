#include <iostream>


const int MAX_N = 1000000;
int L, n, x[MAX_N];  // 入力


int main() {
	// 関数のプロトタイプ
	int min_time(void);
	int max_time(void);

	// 標準入力
	std::cin >> L >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i];
	}

	// 標準出力
	std::cout << "min = " << min_time() << '\n';
	std::cout << "max = " << max_time() << '\n';

	return 0;
}


int min_time(void) {
	int t = 0;
	for (int i = 0; i < n; ++i) {
		t = std::max(t, std::min(x[i], L - x[i])); 
	}
	return t;
}


int max_time(void) {
	int t = 0;
	for (int i = 0; i < n; ++i) {
		t = std::max(t, std::max(x[i], L - x[i]));
	}
	return t;
} 


