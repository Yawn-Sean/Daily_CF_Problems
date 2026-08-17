#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

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

		if (n & 1) cout << (s[n / 2] == 'B' && (s[n / 2 - 1] == 'B' || s[n / 2 + 1] == 'B') ? "Doludu" : "DoIudu") << '\n';
		else cout << (s[n / 2 - 1] == 'B' || s[n / 2] == 'B' ? "Doludu" : "DoIudu") << '\n';
	}

	return 0;
}