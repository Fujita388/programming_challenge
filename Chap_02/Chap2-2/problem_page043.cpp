#include <iostream>


// 入力
const int MAX_N = 100000;
int N, S[MAX_N], T[MAX_N];


// 仕事をソートするためのpairの配列
std::pair<int, int> itv[MAX_N];


void solve() {
	// pairは辞書順で比較される
	// 終了時間の早い順にしたいため、Tをfirstに、Sをsecondに入れる
	for (int i = 0; i < N; ++i) {
		itv[i].first = T[i];
		itv[i].second = S[i];
	}
	sort(itv, itv + N);  // 終了時間でソート

	// tは最後に選んだ仕事の終了時間(仕事にかぶりがないように)
	int ans = 0, t = 0;
	for (int i = 0; i < N; ++i) {
		if (t < itv[i].second) {
			++ans;
			t = itv[i].first;
		}
	}
	std::cout << ans << '\n';
}


int main() {
	// 標準入力
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> S[i];
	}
	for (int j = 0; j < N; ++j) {
		std::cin >> T[j];
	}
	
	// 標準出力
	solve();
	return 0;
}
