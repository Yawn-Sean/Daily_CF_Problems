#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string sa, sb;
	cin >> sa >> sb;

	vector<int> cnt(10, 0);
	for (auto &c: sa) cnt[c - '0'] ++;
	for (auto &c: sb) cnt[c - '0'] ++;

	int l = max(sa.size(), sb.size());
	vector<int> weights(l, 0);
	for (int i = 0; i < sa.size(); i ++) weights[i] ++;
	for (int i = 0; i < sb.size(); i ++) weights[i] ++;

	int ans = 0, cur = 9, mod = 998244353;
	for (int i = l - 1; i >= 0; i --) {
		ans = 10ll * ans % mod;
		while (weights[i] --) {
			while (!cnt[cur]) cur --;
			ans = (ans + cur) % mod;
			cnt[cur] --;
		}
	}

	cout << ans;

	return 0;
}