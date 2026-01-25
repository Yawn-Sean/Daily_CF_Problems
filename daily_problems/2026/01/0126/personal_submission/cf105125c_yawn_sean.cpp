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

	int n, m;
	cin >> n >> m;

	vector<int> cnt(n * m + 1, 0);
	for (int i = 0; i < n * m; i ++) {
		int x; cin >> x;
		cnt[x] ++;
	}

	vector<int> vals;
	for (int i = 0; i <= n * m; i ++) {
		for (int j = 0; j < cnt[i]; j ++) vals.emplace_back(i);
		if (i) cnt[i] += cnt[i - 1];
	}

	for (int step = 1; step <= n; step ++) {
		int start = -1, cur = step;

		for (int i = 0; i < m; i ++) {
			start += cur;
			cout << vals[start] << ' ';
			cur = min(cur, start - cnt[vals[start] - 1] + 1);
		}

		cout << '\n';
	}

	return 0;
}