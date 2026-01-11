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

	int M = 1e6;
	vector<int> pr(M + 1);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i <= M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j <= M; j += i) {
				pr[j] = i;
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> ls(n), rs(n);
		for (auto &x: ls) cin >> x;
		for (auto &x: rs) cin >> x;

		int to_check = -1;
		for (int i = 0; i < n; i ++) {
			if (ls[i] == rs[i]) {
				to_check = ls[i];
			}
		}

		if (to_check == -1) {
			cout << "YES\n";
			for (int i = 0; i < n; i ++)
				cout << rs[i] / 2 * 2 << ' ';
			cout << '\n';
		}
		else {
			set<int> prs;
			while (to_check > 1) {
				prs.insert(pr[to_check]);
				to_check /= pr[to_check];
			}

			bool found = false;
			for (auto &p: prs) {
				bool flg = true;
				for (int i = 0; i < n; i ++) {
					if (rs[i] / p * p < ls[i]) {
						flg = false;
					}
				}
				if (flg) {
					found = true;
					cout << "YES\n";
					for (int i = 0; i < n; i ++)
						cout << rs[i] / p * p << ' ';
					cout << '\n';
					break;
				}
			}
			if (!found) cout << "NO\n";
		}
	}

	return 0;
}