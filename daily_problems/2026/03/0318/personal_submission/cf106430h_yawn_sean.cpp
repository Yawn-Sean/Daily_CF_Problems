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

	int M = 2e5;

	vector<int> phi(M + 1);
	iota(phi.begin(), phi.end(), 0);
	phi[1] = 0;

	for (int i = 2; i <= M; i ++) {
		if (phi[i] == i) {
			for (int j = i; j <= M; j += i) {
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}

	vector<long long> acc(M + 1, 0);

	for (int i = 2; i <= M; i ++) {
		if (phi[i] == i - 1) {
			for (int j = i; j <= M; j += i) {
				acc[j] += phi[j / i];
			}
		}
	}

	for (int i = 1; i <= M; i ++) acc[i] += acc[i - 1];

	int t;
	cin >> t;

	while (t --) {
		int l, r;
		cin >> l >> r;
		cout << acc[r] - acc[l - 1] << '\n';
	}

	return 0;
}