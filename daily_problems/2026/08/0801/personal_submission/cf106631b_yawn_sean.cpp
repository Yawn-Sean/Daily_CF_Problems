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

		auto check1 = [&] () -> bool {
			for (auto &c: s) if (c == '0') return false;
			return true;
		};

		auto check2 = [&] () -> bool {
			for (int i = 0; i < n; i ++) {
				if (s[i] - '0' == i % 2) {
					return false;
				}
			}
			return true;
		};

		auto check3 = [&] () -> bool {
			if (s[0] == '0') return false;
			for (int i = 1; i < n; i ++)
				if (s[i] == '1') return false;
			return true;
		};

		auto check4 = [&] () -> bool {
			if (s[0] == '0' || s[n - 1] == '0') return false;
			for (int i = 1; i < n - 1; i ++)
				if (s[i] == '1') return false;
			return true;
		};

		if (check1()) cout << string(n, 'a') << '\n';
		else if (check2()) {
			for (int i = 0; i < n; i ++)
				cout << (i % 2 ? 'b' : 'a');
			cout << '\n';
		}
		else if (check3()) cout << string(n - 1, 'a') << 'b' << '\n';
		else if (check4()) cout << string((n - 1) / 2, 'a') << string(n - (n - 1) / 2 * 2, 'b') << string((n - 1) / 2, 'a') << '\n';
		else cout << "-1\n";
	}

	return 0;
}