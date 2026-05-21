#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

vector<int> prep(string &s) {
	int n = s.size();

	vector<int> p(n, 0);
	int j = 0;

	for (int i = 1; i < n; i ++) {
		while (j && s[j] != s[i])
			j = p[j - 1];
		if (s[j] == s[i]) j ++;
		p[i] = j;
	}

	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
		int n, k;
		string s;

		cin >> n >> k >> s;
		auto kmp = prep(s);

		vector<int> dp(k + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < k; i ++) {
			for (int j = 0; j < n; j ++) {
				if (!kmp[j] && i + j + 1 <= k) {
					dp[i + j + 1] = (dp[i + j + 1] + dp[i]) % mod;
				}
			}
		}

		cout << dp[k] << '\n';
	}

	return 0;
}