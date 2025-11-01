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
		int n, c0 = 0, c1 = 0;
		cin >> n;

		while (n --) {
			string s;
			cin >> s;

			bool f = false;

			for (int i = 0; i < 4; i ++) {
				if (s.substr(i, 3) == "xxx") {
					f = true;
				}
			}

			if (f) {
				c1 ^= 1;
				continue;
			}

			for (int i = 0; i < 5; i ++) {
				if (s.substr(i, 2) == "xx") {
					f = true;
				}
			}

			if (f) c0 ^= 1;
		}

		cout << ((c0 | c1) ?  "Monocarp" : "Polycarp") << '\n';
	}

	return 0;
}