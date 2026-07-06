#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 1e5 + 5;
	vector<int> cnt(M, 0);

	for (int i = 1; i < M; i ++) {
		for (int j = i * 2; j < M; j += i) {
			cnt[j] ++;
		}
	}

	for (int i = 1; i < M; i ++) cnt[i] += cnt[i - 1];

	int mod = 1e9 + 7, rev2 = (mod + 1) / 2;
	vector<int> f(M, 1);
	for (int i = 1; i < M; i ++) f[i] = 1ll * i * f[i - 1] % mod;

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		cout << 1ll * cnt[n] * rev2 % mod * f[n] % mod << '\n';
	}

	return 0;
}