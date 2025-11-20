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
		long long a, b;
		cin >> a >> b;

		if (a > b) swap(a, b);
		
		if (2 * a < b) cout << "NO\n";
		else if (a == b) {
			if (a & 1) cout << "NO\n";
			else cout << "SI\n";
		}
		else {
			if (a % (b - a)) cout << "NO\n";
			else {
				bool flg = false;

				for (int i = 2; i <= 4; i ++) {
					if (b % i == 0) {
						long long x = a - b / i;
						if (x > 0 && b % x == 0) {
							flg = true;
						}
					}
				}

				cout << (flg ? "SI" : "NO") << '\n';
			}
		}
	}

	return 0;
}