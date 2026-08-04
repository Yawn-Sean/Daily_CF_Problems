#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int N = 1e6;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> mn(N + 1);
	iota(mn.begin(), mn.end(), 0);
	for (int i = 2; i <= N; i++) {
		if (mn[i] != i) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			mn[j] = min(mn[j], mn[i]);
		}
	}

	vector<int> cnt(N + 1), pre(N + 1);
	i64 sum = 1;
	for (int i = 1; i <= N; i++) {
		int t = i;
		vector<array<int, 2>> fac;
		bool x = false;
		while (t > 1) {
			int v = mn[t], c = 0;
			while (t % v == 0) {
				c++, t /= v;
			}
			fac.push_back({v, c});
			x |= (c > cnt[v]);
		}
		if (x) {
			for (const auto&  [l, r] : fac) {
				cnt[l] += r;
			}
			sum++;
		}
		pre[i] = sum;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << pre[n] << "\n";
	}
	return 0;
}