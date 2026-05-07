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

	int M = 1e7;
	vector<int> is_prime(M, 1);

	is_prime[0] = 0;
	is_prime[1] = 0;

	for (int i = 2; i < M; i ++) {
		if (is_prime[i]) {
			for (int j = i * 2; j < M; j += i) {
				is_prime[j] = 0;
			}
		}
	}

	vector<int> vis(M, 0), twins;

	for (int i = 0; i < M - 2; i ++) {
		if (is_prime[i] && is_prime[i + 2] && !vis[i]) {
			vis[i] = 1;
			vis[i + 2] = 1;
			twins.emplace_back(i);
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		cout << (n + 3) / 4 + 4 << '\n';
		cout << "-2 -2\n";
		cout << "-2 0\n";
		cout << "0 0\n";
		cout << "0 -2\n";

		for (int i = 0; i < (n + 3) / 4; i ++)
			cout << twins[i * 2] << ' ' << twins[i * 2 + 1] << '\n';

		for (int i = 0; i < n; i ++)
			cout << i % 4 + 1 << ' ' << (i + 1) % 4 + 1 << ' ' << i / 4 + 5 << '\n';
	}

	return 0;
}