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

	int t;
	cin >> t;

	while (t --) {
		int n;
		string s;
		cin >> n >> s;

		if (n == 1) {
			cout << "0 0\n";
			continue;
		}

		int ans = 0;
		char ma1 = '0', ma2 = '0';
		for (auto &c: s) {
			ans += c - '0';
			if (c > ma1) swap(ma1, ma2), ma1 = c;
			else ma2 = max(c, ma2);
		}

		int cnt = (s[0] != ma2) + (s.back() != ma1);
		if (s[0] == ma1 && s.back() == ma2) cnt = min(cnt, 1);

		cout << cnt << ' ' << 11 * ans - 10 * (ma1 - '0') - (ma2 - '0') << '\n';
	}

	return 0;
}