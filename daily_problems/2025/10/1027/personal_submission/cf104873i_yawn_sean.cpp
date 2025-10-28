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

	int n;
	cin >> n;

	vector<vector<int>> ans(n);

	if (n == 1) {
		cout << "? 1 1" << endl;
		int k; cin >> k;
		ans[0].resize(k);
		for (auto &v: ans[0]) cin >> v;
	}
	else {
		for (int i = 0; i < n; i += n / 2) {
			vector<int> idxs;
			for (int j = i; j < i + n / 2 && j < n; j ++) {
				idxs.emplace_back(j + 1);
				idxs.emplace_back(j + 1);
			}

			int k = idxs.size() / 2;
			cout << '?' << ' ' << idxs.size();
			for (auto &v: idxs) cout << ' ' << v;
			cout << endl;

			int m;
			cin >> m;

			vector<int> res(m);
			for (auto &x: res) cin >> x;

			int pt = 0;

			for (int j = i; j < i + k; j ++) {
				int npt = pt + 1;
				while (res[npt] != res[pt]) npt ++;
				for (int k = pt; k < npt; k ++) ans[j].emplace_back(res[k]);
				pt = 2 * npt - pt;
			}
		}
	}

	cout << "!";
	for (auto &x: ans) {
		cout << ' ' << x.size();
		for (auto &y: x) cout << ' ' << y;
	}

	return 0;
}