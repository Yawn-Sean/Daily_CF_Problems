#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> cnt(1 << 14);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	
	if (k == 0) {
		i64 ans = 0;
		for (int i = 0; i < (1 << 14); i++) {
			ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
		}
		cout << ans << '\n';
		return 0;
	}
	
	vector<int> vals;
	for (int i = 0; i < (1 << 14); i++) {
		if (__builtin_popcount(i) == k) {
			vals.push_back(i);
		}
	}

	i64 ans = 0;
	for (int i = 0; i < (1 << 14); i++) {
		for (auto& v: vals) {
			ans += 1ll * cnt[i] * cnt[v ^ i];
		}
	}
	cout << ans / 2 << '\n';	
	return 0;
}
