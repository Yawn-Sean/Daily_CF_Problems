#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> ans(2 * n + 1, -1);
	
	// d1 = n - 1, d3 = n - 3 ...
	int l = 1, r = n;
	// 构造奇数的情况
	for (int d = 1; d <= n; d += 2) {
		ans[l++] = d;
		ans[r--] = d;
	}
	
	l = n + 1, r = 2 * n - 1;
	for (int d = 2; d <= n; d += 2) {
		ans[l++] = d;
		ans[r--] = d;
	}
	
	for (int i = 1; i <= 2 * n; i++) {
		cout << (ans[i] == -1 ? n : ans[i]) << ' ';
	}
	
	return 0;
}
