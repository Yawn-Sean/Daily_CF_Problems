#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

		set<char> vis(s.begin(), s.end());
		cout << (vis.size() == 1 || (n == 3 && vis.size() == 3) ? "NO" : "YES") << '\n';
	}

	return 0;
}