#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
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

		int ans = 0, flg = 0;

		for (int i = 0; i < n; i ++) {
			if (s[i] != '?') {
				ans += 1 + flg;
				flg = 0;
			}
			else if (i && s[i - 1] != '?') {
				if (i + 1 < n && s[i + 1] != '?' && s[i - 1] != s[i + 1])
					ans ++;
				else if (i + 1 < n && s[i + 1] == '?')
					flg = 1;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}