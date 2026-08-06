#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	i64 n, q;
	cin >> n >> q;
	vector<map<i64, i64>> mp(n + 1);
	while (q--) {
		i64 fst, stp, cost;
		cin >> fst >> stp >> cost;
		i64 g = __gcd(stp, n);
		mp[g][(fst - 1) % g] += cost;
	}

	vector<i64> ans(n);
	for (int i = 1; i <= n; i++) {
		for (const auto& [l, r] : mp[i]) {
			for (int j = l; j < n; j += i) {
				ans[j] += r;
			}
		}
	}

	cout << max_element(ans.begin(), ans.end()) - ans.begin() + 1;
	return 0;
}