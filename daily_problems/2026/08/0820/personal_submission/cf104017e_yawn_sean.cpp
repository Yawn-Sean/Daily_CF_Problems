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
		string s1, s2;
		cin >> s1 >> s2;

		auto f = [&] (string &s) -> pair<bool, vector<char>> {
			bool flg = false;
			vector<char> stk;

			for (auto &c: s) {
				if (c == 'B') flg ^= 1;
				else if (!stk.empty() && stk.back() == c) stk.pop_back();
				else stk.emplace_back(c);
			}

			return {flg, stk};
		};

		cout << (f(s1) == f(s2) ? "YES" : "NO") << '\n';
	}

	return 0;
}