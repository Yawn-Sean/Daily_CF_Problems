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
		cin >> n;

		cout << '?';
		for (int i = 0; i < 2; i ++) {
			cout << ' ' << n;
			for (int j = 1; j <= n; j ++) cout << ' ' << j;
		}
		cout << endl;

		int total_edge;
		cin >> total_edge;

		int resid_deg = total_edge * 2;
		vector<int> degs(n);

		for (int i = 0; i < n - 1; i ++) {
			cout << '?';
			for (int t = 0; t < 2; t ++) {
				cout << ' ' << n - 1;
				for (int j = 0; j < n; j ++) {
					if (i != j) cout << ' ' << j + 1;
				}
			}
			cout << endl;

			int x;
			cin >> x;
			degs[i] = total_edge - x;
			resid_deg -= degs[i];
		}

		degs[n - 1] = resid_deg;

		int ans = -2;
		for (int i = 0; i < n; i ++) {
			if (degs[i] == 1) {
				ans = i;
			}
		}

		cout << "! " << ans + 1 << endl;
	}

	return 0;
}