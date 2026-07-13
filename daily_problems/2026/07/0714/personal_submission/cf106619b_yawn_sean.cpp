#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 2e6 + 5;

	vector<int> pr(M);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i <= M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j <= M; j += i) {
				pr[j] = i;
			}
		}
	}

	vector<int> cnt(M, 0);

	for (int i = 2; i < M; i ++) {
		int cur = i, res = 1;
		while (cur > 1) {
			int p = pr[cur], c = 0;
			while (cur % p == 0) cur /= p, c ++;
			res *= 2 * c + 1;
		}
		cnt[i] += res / 2;
	}

	for (int i = 1; i < M; i ++) cnt[i] += cnt[i - 1];

	int t;
	cin >> t;

	while (t --) {
		int n; cin >> n;
		cout << cnt[n] << '\n';
	}

	return 0;
}