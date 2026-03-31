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

	int n, m;
	cin >> n >> m;

	vector<long long> diff_k(2 * m + 1, 0), diff_b(2 * m + 1, 0);
	int v = (m + 1) / 2;

	while (n --) {
		int x;
		cin >> x;

		diff_k[x] += 1;
		diff_k[x + v] -= 1;
		diff_b[x] -= x;
		diff_b[x + v] += x;

		diff_k[x + v] -= 1;
		diff_k[x + m] += 1;
		diff_b[x + v] += x + m;
		diff_b[x + m] -= x + m;
	}

	for (int i = 0; i < 2 * m; i ++) {
		diff_k[i + 1] += diff_k[i];
		diff_b[i + 1] += diff_b[i];
	}

	vector<long long> ans(m, 0);
	for (int i = 0; i < 2 * m; i ++)
		ans[i % m] += diff_k[i] * i + diff_b[i];

	cout << *min_element(ans.begin(), ans.end());

	return 0;
}