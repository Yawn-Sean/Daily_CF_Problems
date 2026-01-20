#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	string digit = "1234567890";

	int t;
	cin >> t;

	while (t --) {
		string s;
		cin >> s;

		int n = s.size();
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < 2; j ++) {
				for (auto &c: digit) {
					if (s[i] != c) cout << c;
				}
			}
			if (i != n - 1) cout << s[i];
		}
		
		cout << '\n';
	}

	return 0;
}