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

	int n, m;
	cin >> n >> m;

	vector<int> idxs1, idxs2;

	for (int i = 1; i <= m; i ++) {
		int x, y;
		cin >> x >> y;
		if (x < y) idxs1.emplace_back(i);
		else idxs2.emplace_back(i);
	}

	cout << "YES\n";
	if (idxs1.size() > idxs2.size()) {
		cout << idxs1.size() << '\n';
		for (auto &v: idxs1) cout << v << ' ';
	}
	else {
		cout << idxs2.size() << '\n';
		for (auto &v: idxs2) cout << v << ' ';
	}

	return 0;
}