#include <iostream>


typedef long long ll;


// 入力
const int MAX_N = 20000;
int N, L[MAX_N];


void solve() {
	ll ans = 0;
	 
	// 板が一本になるまで適用
	while (N > 1) {
		// 一番短い板mii1, 次に短い板mii2を求める
		int mii1 = 0, mii2 = 1;
		if (L[mii1] > L[mii2])
			std::swap(mii1, mii2);
		
		for (int i = 2; i < N; ++i) {
			if (L[i] < L[mii1]) {
				mii2 = mii1;
				mii1 = i;
			}
			else if (L[i] < L[mii2]) 
				mii2 = i;
		}

		// それらを併合
		int t = L[mii1] + L[mii2];
		ans += t;

		if (mii1 == N - 1) 
			std::swap(mii1, mii2);
		L[mii1] = t;
		L[mii2] = L[N - 1];
		--N;
	}
	
	std::cout << ans << '\n';
}


int main() {
	// 標準入力
	std::cin >> N;
	for (int i = 0; i < N; ++i) 
		std::cin >> L[i];
	
	// 標準出力
	solve();
	return 0;
}
