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

	int n;
	string s;

	cin >> n >> s;

	int ca = 0, cb = 0, cc = 0;
	for (auto &c: s) {
		if (c == 'A') ca ++;
		else if (c == 'B') cb ++;
		else cc ++;
	}

	if (ca == n && cb == n && cc == n) cout << 0;
	else {
		int l = 0, r = 0;
		while (l < 3 * n) {
			while (max({ca, cb, cc}) > n && r < 3 * n) {
				if (s[r] == 'A') ca --;
				else if (s[r] == 'B') cb --;
				else cc --;
				r ++;
			}

			if (max({ca, cb, cc}) > n) break;

			if (ca == n && cb == n) {
				cout << 1 << '\n';
				cout << l + 1 << ' ' << r << " C\n";
				return 0;
			}

			if (ca == n && cc == n) {
				cout << 1 << '\n';
				cout << l + 1 << ' ' << r << " B\n";
				return 0;
			}

			if (cb == n && cc == n) {
				cout << 1 << '\n';
				cout << l + 1 << ' ' << r << " A\n";
				return 0;
			}

			if (s[l] == 'A') ca ++;
			else if (s[l] == 'B') cb ++;
			else cc ++;

			l ++;
		}

		ca = 0, cb = 0, cc = 0;
		cout << 2 << '\n';

		for (int i = 0; i < 3 * n; i ++) {
			if (s[i] == 'A') ca ++;
			else if (s[i] == 'B') cb ++;
			else cc ++;

			if (ca == n) {
				cout << i + 2 << ' ' << 3 * n << " B\n";
				cout << 3 * n - (n - cc) + 1 << ' ' << 3 * n << " C\n";
				break;
			}

			if (cb == n) {
				cout << i + 2 << ' ' << 3 * n << " A\n";
				cout << 3 * n - (n - cc) + 1 << ' ' << 3 * n << " C\n";
				break;
			}

			if (cc == n) {
				cout << i + 2 << ' ' << 3 * n << " A\n";
				cout << 3 * n - (n - cb) + 1 << ' ' << 3 * n << " B\n";
				break;
			}
		}
	}

	return 0;
}