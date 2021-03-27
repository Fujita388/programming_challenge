#include <iostream>


const int MAX_N = 20;
int n, a[MAX_N], k;


int main() {
	// 関数のプロトタイプ
	void solve();

	// 標準入力
	std::cin >> n;
	for (int i = 0; i < n; ++i) 
		std::cin >> a[i];
	std::cin >> k;

	// 標準出力
	solve();
	return 0;
}


// iまででsumを作って、残りi以降を調べる
bool dfs(int i, int sum) {
	// n個決め終わったら、今までの和sumがkと等しいかを返す
	if (i == n)  // 終端条件
		return sum == k;
	// a[i]を使わない場合
	if (dfs(i + 1, sum))
		return true;
	// a[i]を使う場合
	if (dfs(i + 1, sum + a[i]))
		return true;
	// a[i]を使う使わないによらずkが作れないのでfalseを返す
	return false;
}


void solve() {
	if (dfs(0, 0))
		std::cout << "Yes" << '\n';
	else
		std::cout << "No" << '\n';
}
