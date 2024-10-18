#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> perm(n);
	for (auto& x: perm) {
		cin >> x;
	}
	
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int x, int y) {
		return (perm[x] + perm[(x + 1) % n]) < (perm[y] + perm[(y + 1) % n]);
	});
	
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[order[i]] = i;
	}
	for (auto& x: ans) { cout << x << ' '; }
	return 0;
}
