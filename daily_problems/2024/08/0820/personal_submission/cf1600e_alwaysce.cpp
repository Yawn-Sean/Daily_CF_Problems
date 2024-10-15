
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/**
The second player's strategy: 
Find a corresponding move for each move of the first player.
**/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& v: a) { cin >> v; }
	
	// 首先考虑dp
	// 先手拿走的l还是r
	// 递增前缀
	int l = 0;
	while (l + 1 < n and a[l + 1] > a[l]) {
		l++;
	}
	// 递减后缀
	int r = n - 1;
	while (r > 0 and a[r - 1] > a[r]) {
		r--;
	}
	
	// 前后都是奇数
	// 前后都是偶数 后手赢
	// 其中一个奇数 先手赢
	// 都是奇数 取开始值更大的那个
	if ( ((l + 1) % 2) | ((n - r) % 2) ) {
		cout << "Alice\n";
	} else {
		cout << "Bob\n";
	}
	
	return 0;
}
