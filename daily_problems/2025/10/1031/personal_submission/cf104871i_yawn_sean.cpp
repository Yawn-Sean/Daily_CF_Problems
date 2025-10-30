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

	cout << "QUERY " << string(n, '1') << endl;
	vector<int> total_deg(n);
	for (auto &x: total_deg) cin >> x;

	vector<vector<int>> notes(15, vector<int>(n));

	for (int j = 0; j < 15; j ++) {
		cout << "QUERY ";
		for (int i = 0; i < n; i ++)
			cout << (i >> j & 1);
		cout << endl;

		for (auto &x: notes[j]) cin >> x;
	}

	cout << "ANSWER\n";
	vector<int> stk;

	for (int i = 0; i < n; i ++) {
		if (total_deg[i] == 1) {
			stk.emplace_back(i);
		}
	}

	for (int i = 0; i < n - 1; i ++) {
		int u = stk.back(); stk.pop_back();
		int v = 0;

		for (int j = 0; j < 15; j ++) {
			if (notes[j][u]) {
				v |= 1 << j;
			}
		}

		for (int j = 0; j < 15; j ++) {
			if (u >> j & 1) {
				notes[j][v] --;
			}
		}

		total_deg[v] --;
		if (total_deg[v] == 1) stk.emplace_back(v);
		cout << u + 1 << ' ' << v + 1 << '\n';
	}

	return 0;
}